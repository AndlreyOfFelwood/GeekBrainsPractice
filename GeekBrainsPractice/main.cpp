#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include "functions.h"

using namespace std;

// Функции для первого задания
size_t getSize(size_t size)
{
    std::cin >> size;
    if (size > 0)
        return size;
    else
        getSize(size);
}

int* declareArray(int* ptrArr, size_t size)
{
    if (size > 0)
    {
        ptrArr = new (nothrow) int[size];

        if (ptrArr != nullptr)
            return ptrArr;
        else
            return 0;
    }
    else
        return 0;
}

void initArray(int* arr, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = (int)pow(2, i);
    }
}

// 1. Выделить в памяти динамический одномерный массив типа int. Размер массива запросить у пользователя. Инициализировать его числами степенями двойки: 1, 2, 4, 8, 16, 32, 64, 128 … Вывести массив на экран. Не забыть освободить память. =) Разбить программу на функции.
void firstTask()
{
    size_t size = 0;

    std::cout << "Введите размер массива: \n";
    size = getSize(size);

    int* ptrArr = nullptr;
    ptrArr = declareArray(ptrArr, size);

    initArray(ptrArr, size);
    arrOut(ptrArr, size);
}


//Функции для второго задания
int** declareArray(int** ptrArr, size_t parentSize, size_t nestedSize)
{
    if (parentSize > 0 && nestedSize > 0)
    {
        ptrArr = new int* [parentSize];
        for (size_t i = 0; i < parentSize; i++) {
            ptrArr[i] = new int[nestedSize];
        }
        return ptrArr;
    }
    return 0;
}

void initArray(int** arr, size_t parentSize, size_t nestedSize)
{
    for (size_t i = 0; i < parentSize; i++)
    {
        for (size_t j = 0; j < nestedSize; j++)
        {
            arr[i][j] = myRand(0, 100);
        }
    }
}

void arrOut(int** arr, size_t parentSize, size_t nestedSize)
{
    for (size_t i = 0; i < parentSize; i++)
    {
        for (size_t j = 0; j < nestedSize; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// 2. Динамически выделить матрицу 4х4 типа int. Инициализировать ее псевдослучайными числами через функцию rand. Вывести на экран. Разбейте вашу программу на функции которые вызываются из main.
void secondTask()
{
    int** ptrArr = nullptr;
    size_t parentSize = 0;
    size_t nestedSize = 0;

    std::cout << "Введите размер родительского массива: \n";
    parentSize = getSize(parentSize);

    std::cout << "Введите размер вложенного массива: \n";
    nestedSize = getSize(nestedSize);

    ptrArr = declareArray(ptrArr, parentSize, nestedSize);

    initArray(ptrArr, parentSize, nestedSize);
    arrOut(ptrArr, parentSize, nestedSize);
}

//Функции для третьего задания
string getName()
{
    string name;
    cout << "Введите имя файла:\n";
    cin >> name;

    return name;
}

void createFile(string name, short num = 1)
{
    string fileName = name + ".txt";
    ofstream fout(fileName);

    if (num == 1)
    {
        fout << "Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n In rhoncus placerat luctus. Aliquam erat volutpat.\n Aliquam malesuada turpis justo, nec porta risus pellentesque viverra. \nDuis laoreet neque augue, ac tristique odio semper ac.\n Phasellus non convallis quam, in porta justo.\n Praesent vulputate quis turpis quis rhoncus.\n Aenean feugiat lectus non viverra pulvinar.\n Sed euismod, metus ac vestibulum aliquam, lacus orci.\n";
    }
    else
        fout << "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aenean pharetra ligula augue, vitae ullamcorper lorem hendrerit ac. Ut finibus finibus ipsum ut luctus. Vivamus ac enim non felis mattis feugiat sit amet id erat. Nam varius elementum auctor. Suspendisse id urna sed urna vestibulum ullamcorper a et justo. Nulla sollicitudin velit quam, id tempus risus ultricies quis. Aliquam sollicitudin quis lectus commodo tristique. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Vivamus tristique quam sit amet turpis vulputate iaculis. Aliquam porta dapibus tortor vitae faucibus. Nulla molestie scelerisque tellus, at cursus urna facilisis et. Suspendisse.\n";

    fout.close();
}

// 3. Написать программу c 2-я функциями, которая создаст два текстовых файла (*.txt), примерно по 50-100 символов в каждом (особого значения не имеет с каким именно содержимым). Имена файлов запросить у польлзователя.
void thirdTask()
{
    string  firstFileName = getName(), 
            secondFileName = getName();

    createFile(firstFileName);
    createFile(secondFileName, 2);
}

//Функции для четвертого задания
string getFileData(string fileName)
{
    string resString = "";
    ifstream fileData(fileName + ".txt");

    if (fileData.is_open())
    {
        const size_t size = 255;
        char buf[size];
        while (!fileData.eof())
        {
            fileData.getline(buf, size);
            resString += buf;
        }
        fileData.close();
        return resString;
    }
    else
    {
        cout << "Error. Can not open file "+ fileName +".";
        return "";
    }
}

void createFile(string name, string data)
{
    string fileName = name + ".txt";
    ofstream fout(fileName);

    fout << data;

    fout.close();
}

// 4. * Написать функцию, «склеивающую» эти файлы в третий текстовый файл (имя файлов спросить у пользователя).
void fourthTask()
{
    string  firstFileData, secondFileData;

    firstFileData = getFileData(getName());
    secondFileData = getFileData(getName());

    createFile(getName(), firstFileData + secondFileData);
}


// 5. * Написать программу, которая проверяет присутствует ли указанное пользователем при запуске программы слово в указанном пользователем файле (для простоты работаем только с латиницей).
void fifthTask()
{
    string searchWord, fileName, fileData;

    cout << "Введите искомое слово:\n";
    cin >> searchWord;

    cout << "Введите название файла, в котором нужно найти данное слово:\n";
    cin >> fileName;

    fileData = getFileData(fileName);
    (fileData.find(searchWord) == -1) ?
        cout << "Слово " + searchWord + " не найдено в файле " + fileName << endl
        :
        cout << "В файле " + fileName + " присутствует слово " + searchWord << endl;

}


int main()
{
    setlocale(LC_ALL, "Russian");

    unsigned short numberOfTask = 0;

    do
    {
        cout << "Введите номер задания от 1 до 5 или 0 для выхода из программы" << endl;
        cin >> numberOfTask;

        if (numberOfTask >= 0 && numberOfTask <= 5)
        {
            switch (numberOfTask)
            {
            case 1:
                firstTask();
                break;
            case 2:
                secondTask();
                break;
            case 3:
                thirdTask();
                break;
            case 4:
                fourthTask();
                break;
            case 5:
                fifthTask();
                break;
            case 0:
                cout << "Выход из программы" << endl;
                break;
            }

            taskSeparator();
        }
    } while (numberOfTask != 0);

    

    return 0;
}
