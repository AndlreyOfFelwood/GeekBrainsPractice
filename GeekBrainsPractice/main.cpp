#include <iostream>
#include "functions.h"

using namespace std;

const unsigned short SIZE = 10;
const unsigned short OFFSET = 2;


// 1. Написать функцию которая выводит массив double чисел на экран. Параметры функции это сам массив и его размер. Вызвать эту функцию из main.
void firstTask(double *arr, size_t size)
{
    cout << "\nНаписать функцию которая выводит массив double чисел на экран. Параметры функции это сам массив и его размер. Вызвать эту функцию из main.\n\n";

    dArrOut(arr, size);
}


// 2. Задать целочисленный массив, состоящий из элементов 0 и 1. Например: [ 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 ]. Написать функцию, заменяющую в принятом массиве 0 на 1, 1 на 0. Выводить на экран массив до изменений и после.
void secondTask()
{
    cout << "\nЗадать целочисленный массив, состоящий из элементов 0 и 1. Например: [ 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 ]. Написать функцию, заменяющую в принятом массиве 0 на 1, 1 на 0. Выводить на экран массив до изменений и после.\n\n";

    int arr[10] = { 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 };

    cout << "Начальный массив:\n";
    iArrOut(arr, 10);

    for (size_t i = 0; i < 10; i++)
    {
        if (arr[i] == 1)
            arr[i] = 0;
        else
            arr[i] = 1;
    }

    cout << "Итоговый массив:\n";
    iArrOut(arr, 10);
}


// 3. Задать пустой целочисленный массив размером 8. Написать функцию, которая с помощью цикла заполнит его значениями 1 4 7 10 13 16 19 22. Вывести массив на экран. 
void thirdTask()
{
    cout << "\nЗадать пустой целочисленный массив размером 8. Написать функцию, которая с помощью цикла заполнит его значениями 1 4 7 10 13 16 19 22. Вывести массив на экран.\n\n";

    int iArr[8], val = 1;

    for (size_t i = 0; i < 8; i++)
    {
        iArr[i] = val;
        val += 3;
    }

    iArrOut(iArr, 8);
}


// 4. * Написать функцию, которой на вход подаётся одномерный массив и число n (может быть положительным, или отрицательным), при этом метод должен циклически сместить все элементы массива на n позиций.
void fourthTask(int *arr, int n)
{
    cout << "\n* Написать функцию, которой на вход подаётся одномерный массив и число n (может быть положительным, или отрицательным), при этом метод должен циклически сместить все элементы массива на n позиций.\n\n";
    
    cout << "Вывод массива до смещения на " << n << ":\n";
    iArrOut(arr, SIZE);

    int tmpArr[SIZE];

    for (size_t i = 0; i < SIZE; i++)
    {
        tmpArr[(i + n)% SIZE] = arr[i];
    }
    arr = tmpArr;

    cout << "Вывод массива после смещения на " << n << ":\n";
    iArrOut(arr, SIZE);
}


// 5. ** Написать метод, в который передается не пустой одномерный целочисленный массив, метод должен вернуть истину если в массиве есть место, в котором сумма левой и правой части массива равны. 
bool fifthTask(int *arr, size_t size)
{
    cout << "\n** Написать метод, в который передается не пустой одномерный целочисленный массив, метод должен вернуть истину если в массиве есть место, в котором сумма левой и правой части массива равны.\n\n";

    cout << "Массив:\n";
    iArrOut(arr, size);

    int lSum = 0, rSum = 0;

    for (size_t i = 0; i < size; i++)
    {
        lSum += arr[i];
        for (size_t j = size-1; j > i; j--)
        {
            rSum += arr[j];
        }
        if (lSum == rSum)
        {
            return true;
        }
        else
            rSum = 0;
    }

    return false;
}


int main()
{
    setlocale(LC_ALL, "Russian");

    unsigned short numberOfTask = 0;
    double dArray[SIZE];
    int iArray[SIZE], 
        arrBalance[SIZE] = { 45, 1, 2, 3, 4, 5, 6, 7, 8, 11 };

    fillArr(dArray, SIZE);
    fillArr(iArray, SIZE);

    do
    {
        cout << "Введите номер задания от 1 до 5 или 0 для выхода из программы" << endl;
        cin >> numberOfTask;

        if (numberOfTask >= 0 && numberOfTask <= 5)
        {
            switch (numberOfTask)
            {
            case 1:
                firstTask(dArray, SIZE);
                break;
            case 2:
                secondTask();
                break;
            case 3:
                thirdTask();
                break;
            case 4:
                fourthTask(iArray, OFFSET);
                break;
            case 5:
                if (fifthTask(arrBalance, SIZE))
                    cout << "\nЭто сбалансированный массив\n";
                else
                    cout << "\nЭто не сбалансированный массив\n";
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
