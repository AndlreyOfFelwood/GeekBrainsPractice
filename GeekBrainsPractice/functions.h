#pragma once
#include <iostream>

using namespace std;

 
// Функция-разделитель вывода задач
void taskSeparator()
{
    cout << "\n---------------------------------------------------------------------\n\n";
}


/* 
* @brief – Рандомайзер чисел типа double
* @param fMin - минимальное значение случайного числа
* @param fMax - максимальное значение случайного числа
*/
double myRand(double fMin = -100, double fMax = 100)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}


/* 
* @brief – Рандомайзер чисел типа int
* @param fMin - минимальное значение случайного числа
* @param fMax - максимальное значение случайного числа
*/
int myRand(int iMin = -100, int iMax = 100)
{
    return (rand() % (iMax * 2)) - abs(iMin);
}


/*
* @brief Заполнение массива случайными целыми числами
* @param arr  - целочисленный массив
* @param size - размер массива
* @param min  - минимальное значение элемента массива
* @param max  - максимальное значение элемента массива
*/
void fillArr(int* arr, size_t size, int min = -100, int max = 100)
{
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = myRand(min, max);
    }
}

/*
* @brief Заполнение массива случайными дробными числами
* @param arr  - массив дробных чисел
* @param size - размер массива
* @param min  - минимальное значение элемента массива
* @param max  - максимальное значение элемента массива
*/
void fillArr(double* arr, size_t size, int min = -100, int max = 100)
{
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = myRand(min, max);
    }
}

/*
* @brief Вывод целочисленного массива
* @param arr  - массив целых чисел
* @param size - размер массива
*/
void arrOut(int* arr, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i];
        if ((i + 1) < size)
            cout << ",";
        cout << " ";
    }
    cout << endl;
}

/*
* @brief Вывод массива дробных чисел
* @param arr  - массив дробных чисел
* @param size - размер массива
*/
void arrOut(double* arr, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i];
        if ((i + 1) < size)
            cout << ",";
        cout << " ";
    }
    cout << endl;
}