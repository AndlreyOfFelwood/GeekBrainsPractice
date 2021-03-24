#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

enum class TicTakToeValues
{
    EMPTY = '_', 
    CROSS = 'X',
    ZERO = '0'
};

enum class AIDifficult
{
    EASY,
    HARD
};

enum class PlayerType
{
    HUMAN,
    AI
};

typedef TicTakToeValues ttt;
typedef AIDifficult aid;
typedef PlayerType pt;

struct Player
{
    ttt marker = ttt::CROSS;
    bool isWon = false;
    pt type = pt::HUMAN;
};

struct Game 
{
    const unsigned short sizeX = 3;
    const unsigned short sizeY = 3;
    ttt** field = nullptr;
    aid difficult = aid::EASY;
    int preferredMoves[9][2] = {
         {1, 1}, {0, 0}, {0, 2}, {2, 0}, {2, 2},
         {0, 1}, {1, 0}, {1, 2}, {2, 1} };
    int winConditions[8] = {
         0b111000000, 0b000111000, 0b000000111, // rows
         0b100100100, 0b010010010, 0b001001001, // cols
         0b100010001, 0b001010100               // diagonals
    };
    int* nextMoves[9];
    int moveCounter = 0;
    Player human;
    Player ai;
    pt activePlayer;
    bool haveWinner = false;
    bool draw = false;
};

void fieldSeparator()
{
    cout << "-------------------";
    cout << endl;
}

void printField(Game& game)
{
    system("cls");
    cout << "   | 1 | 2 | 3 |" << endl;
    fieldSeparator();
    for (size_t i = 0; i < game.sizeX; i++)
    {
        cout << " " << i + 1 << " |";
        for (size_t j = 0; j < game.sizeY; j++)
        {
            cout << " " << (char)game.field[i][j] << " |";
        }
        cout << endl;
        if (i + 1 < game.sizeX)
            fieldSeparator();
    }
}

bool checkWin(Game &game, bool setWinner = true) {
    Player &activePlayer = (game.activePlayer == pt::HUMAN) ? game.human : game.ai;
    int pattern = 0b000000000;  // 9-bit pattern for the 9 cells
    for (int row = 0; row < game.sizeX; ++row) {
        for (int col = 0; col < game.sizeY; ++col) {
            if (game.field[row][col] == activePlayer.marker) {
                pattern |= (1 << (row * game.sizeY + col));
            }
        }
    }
    for (int winConditions : game.winConditions) {
        if ((pattern & winConditions) == winConditions)
        {
            if (setWinner)
                activePlayer.isWon = true;
            return true;
        }
    }

    return false;
}

bool checkDraw(Game &game)
{
    for (size_t i = 0; i < game.sizeX; i++)
    {
        for (size_t j = 0; j < game.sizeY; j++)
        {
            if (game.field[i][j] == ttt::EMPTY)
            {
                game.draw = false;
                return game.draw;
            }
        }
    }
    game.draw = true;
    return game.draw;
}

void chooseDificult(Game& game)
{
    unsigned short dif = 0;
    cout << "\nВыберите сложность:\n";
    cout << "Введите 1, чтобы сыграть со слабым компьютером,\n или 2, чтобы сыграть с сильным компьютером.\n";
    cin >> dif;

    if (dif == 1)
        game.difficult = aid::EASY;
    else if (dif == 2)
        game.difficult = aid::HARD;
    else
        chooseDificult(game);
}

void aiEasyMode(Game& game)
{
    for (int* arr : game.preferredMoves)
    {
        if (game.field[arr[0]][arr[1]] == ttt::EMPTY)
        {
            game.field[arr[0]][arr[1]] = game.ai.marker;
            break;
        }
    }
}

bool aiNormalMode(Game& game)
{
    for (size_t i = 0; i < game.sizeX; i++)
    {
        for (size_t j = 0; j < game.sizeY; j++)
        {
            if (game.field[i][j] == ttt::EMPTY)
            {
                game.field[i][j] = game.ai.marker;
                if (checkWin(game, false))
                    return true;

                game.field[i][j] = ttt::EMPTY;
            }
        }
    }

    for (size_t i = 0; i < game.sizeX; i++)
    {
        for (size_t j = 0; j < game.sizeY; j++)
        {
            if (game.field[i][j] == ttt::EMPTY)
            {
                game.field[i][j] = game.human.marker;
                game.activePlayer = pt::HUMAN;
                if (checkWin(game, false))
                {
                    game.field[i][j] = game.ai.marker;
                    game.activePlayer = pt::AI;
                    return true;
                }
                game.field[i][j] = ttt::EMPTY;
            }
        }
    }

    game.activePlayer = pt::AI;
    aiEasyMode(game);
}

void aiMove(Game &game)
{
    if (game.difficult == aid::EASY)
        aiEasyMode(game);
    else if (game.difficult == aid::HARD)
        aiNormalMode(game);

    printField(game);
}

void getCoord(unsigned short &coord)
{
    while (true)
    {
        std::cin >> coord;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Введите корректное число!\n";
        }
        else
        {
            std::cin.ignore(32767, '\n');
            break;
        }
    }
}

void humanMove(Game &game)
{
    unsigned short coordY, coordX;

    cout << "\nВведите кординаты клетки:\n\n";

    cout << "Введите координату по оси X:\n";
    getCoord(coordX);
    cout << "Введите координату по оси Y:\n";
    getCoord(coordY);

    if (game.field[coordY - 1][coordX - 1] == ttt::EMPTY)
    {
        game.field[coordY - 1][coordX - 1] = game.human.marker;
        printField(game);
    }
    else
        humanMove(game);
}

unsigned short coinFlip()
{
    srand(static_cast<unsigned int>(time(0)));
    unsigned short flip = rand() % 2 + 1;
    return flip;
}

void swapPlayer(Game& game)
{
    if (game.activePlayer == pt::HUMAN)
        game.activePlayer = pt::AI;
    else
        game.activePlayer = pt::HUMAN;
}

void getMove(Game &game)
{
    if (game.activePlayer == pt::HUMAN)
        humanMove(game);
    else if (game.activePlayer == pt::AI)
        aiMove(game);
}

void getMoveOrder(Game& game)
{
    cout << "\nБросаем монетку чтобы решить кто будет ходить первым...\n";
    if (coinFlip() == 1)
    {
        cout << "\nПоздравляю, вы ходите первым!\n";
        cout << "\nВы будете играть " << (char)ttt::CROSS << "\n";
        game.human.marker = ttt::CROSS;
        game.human.type = pt::HUMAN;
        game.activePlayer = pt::HUMAN;
        game.ai.marker = ttt::ZERO;
    }
    else
    {
        cout << "\nУвы, но компьютер будет ходить первым(\n";
        cout << "\nВы будете играть " << (char)ttt::ZERO << "\n";
        game.ai.marker = ttt::CROSS;
        game.ai.type = pt::AI;
        game.activePlayer = pt::AI;
        game.human.marker = ttt::ZERO;
    }
    system("pause");
}

void gameInit(Game &game)
{
    game.field = new  TicTakToeValues * [game.sizeX];

    for (size_t i = 0; i < game.sizeX; i++)
        game.field[i] = new TicTakToeValues[game.sizeY];

    for (size_t i = 0; i < game.sizeX; i++)
        for (size_t j = 0; j < game.sizeY; j++)
            game.field[i][j] = ttt::EMPTY;

    game.ai.marker = ttt::ZERO;
    game.ai.type = pt::AI;
}

void deinitGame(Game& game)
{
    for (size_t i = 0; i < game.sizeY; i++)
        delete[] game.field[i];

    delete[] game.field;
    game.field = nullptr;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    Game game;

    gameInit(game);
    printField(game);
    chooseDificult(game);
    getMoveOrder(game);
    do
    {
        getMove(game);

        if (checkWin(game))
        {
            game.haveWinner = true;
            break;
        }
        if (checkDraw(game))
            break;

        swapPlayer(game);

    } while (!game.haveWinner || !game.draw);

    if (game.human.isWon == true)
        cout << "\nПобедил человек!\n";
    else if (game.ai.isWon == true)
        cout << "\nСкайнет победил!\n";
    else
        cout << "Ничья.\n";


    deinitGame(game);
    return 0;
}
