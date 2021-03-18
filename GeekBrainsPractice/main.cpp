#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include "functions.h"

using namespace std;
using namespace MyFunc;

#define CHECK_NUMBER(checkedNumber, maxNumber) (checkedNumber >= 0 && checkedNumber < maxNumber)
#define SIZE 5

//Структура для четвертого задания
#pragma pack(push, 1)
struct Emploee
{
    string name = "";
    unsigned short age = 0;
    unsigned int salary = 0;
};
#pragma pack(pop)

// 1. Создайте проект из 2х cpp файлов и заголовочного (main.cpp, mylib.cpp, mylib.h) во втором модуле mylib объявить 3 функции: для инициализации массива (типа float), печати его на экран и подсчета количества отрицательных и положительных элементов. Вызывайте эти 3-и функции из main для работы с массивом.
void firstTask()
{
    cout << "Создайте проект из 2х cpp файлов и заголовочного (main.cpp, mylib.cpp, mylib.h) во втором модуле mylib объявить 3 функции: для инициализации массива (типа float), печати его на экран и подсчета количества отрицательных и положительных элементов. Вызывайте эти 3-и функции из main для работы с массивом.\n\n";

    int size = 0;

    do
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize> ::max(), '\n');
        cout << "Введите размер массива\n";
        cin >> size;
    } while (size <= 0);

    float* ptrArr = new (nothrow) float[size];

    if (ptrArr != nullptr)
    {
        fillArr(ptrArr, size);
        arrOut(ptrArr, size);
        plusMinusCounter(ptrArr, size);
    }

    delete[] ptrArr;
}


// 2. Описать макрокоманду (через директиву define), проверяющую, входит ли переданное ей число (введенное с клавиатуры) в диапазон от нуля (включительно) до переданного ей второго аргумента (исключительно) и возвращает true или false, вывести на экран «true» или «false».
void secondTask()
{
    cout << "Описать макрокоманду (через директиву define), проверяющую, входит ли переданное ей число (введенное с клавиатуры) в диапазон от нуля (включительно) до переданного ей второго аргумента (исключительно) и возвращает true или false, вывести на экран «true» или «false».\n\n";
    int checkedNumber, maxNumber = 50;

    cIn(checkedNumber);

    CHECK_NUMBER(checkedNumber, maxNumber) == 1 ?
        cout << "True\n" :
        cout << "False\n";
}

// 3. Задайте массив типа int. Пусть его размер задается через директиву препроцессора #define. Инициализируйте его через ввод с клавиатуры. Напишите для него свою функцию сортировки (например Пузырьком). Реализуйте перестановку элементов как макрокоманду SwapINT(a, b). Вызывайте ее из цикла сортировки.
void thirdTask()
{
    cout << "Задайте массив типа int. Пусть его размер задается через директиву препроцессора #define. Инициализируйте его через ввод с клавиатуры. Напишите для него свою функцию сортировки (например Пузырьком). Реализуйте перестановку элементов как макрокоманду SwapINT(a, b). Вызывайте ее из цикла сортировки.\n\n";

    int arr[SIZE];

    for (size_t i = 0; i < SIZE; i++)
    {
        cout << "Введите " << i << " элемент массива\n";
        cIn(arr[i]);
    }

    cout << "\nМассив до сортировки:\n\n";
    arrOut(arr, SIZE);

    arraySort(arr, SIZE);

    cout << "\nМассив после сортировки:\n\n";
    arrOut(arr, SIZE);
}

//Функция для четвертого задания
void structOut(Emploee* emploee)
{
    cout << "Профайл работника:\n\n";
    cout << "Имя: ";
    cout << emploee->name << endl;
    cout << "Возраст: ";
    cout << emploee->age << endl;
    cout << "Зарплата: ";
    cout << emploee->salary << endl;
}

// 4. * Объявить структуру Сотрудник с различными полями. Сделайте для нее побайтовое выравнивание с помощью директивы pragma pack. Выделите динамически переменную этого типа. Инициализируйте ее. Выведите ее на экран и ее размер с помощью sizeof. Сохраните эту структуру в текстовый файл.
void fourthTask()
{
    cout << "\n* Объявить структуру Сотрудник с различными полями. Сделайте для нее побайтовое выравнивание с помощью директивы pragma pack. Выделите динамически переменную этого типа. Инициализируйте ее. Выведите ее на экран и ее размер с помощью sizeof. Сохраните эту структуру в текстовый файл.\n\n";



    Emploee* emploee = new (nothrow) Emploee;

    emploee->name = "Иванов Иван Иванович";
    emploee->age = 33;
    emploee->salary = 77'777;

    structOut(emploee);

    cout << "\nРазмер структуры: ";
    cout << sizeof(emploee) << endl;
    
    ofstream fout("emploee.txt");
    
    fout << "Профайл работника:\n\n";
    fout << "Имя: ";
    fout << emploee->name << endl;
    fout << "Возраст: ";
    fout << emploee->age << endl;
    fout << "Зарплата: ";
    fout << emploee->salary << endl;

    fout.close();

    delete emploee;
}


// 5. * Сделайте задание 1 добавив свой неймспейс во втором модуле (первое задание тогда можно не делать)
void fifthTask()
{
    firstTask();
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
