#pragma once
#include <iostream>

using namespace std;

 
// ‘ункци¤-разделитель вывода задач
void taskSeparator()
{
    cout << "\n---------------------------------------------------------------------\n\n";
}


/* 
* @brief –андомайзер чисел типа double
* @param fMin - минимальное значение случайного числа
* @param fMax - максимальное значение случайного числа
*/
double dRand(double fMin = -100, double fMax = 100)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}


/* 
* @brief –андомайзер чисел типа int
* @param fMin - минимальное значение случайного числа
* @param fMax - максимальное значение случайного числа
*/
int iRand(int iMin = -100, int iMax = 100)
{
    return (rand() % (iMax * 2)) - iMin;
}


/*
* @brief «аполнение массива случайными целыми числами
* @param arr  - целочисленный массив
* @param size - размер массива
* @param min  - минимальное значение элемента массива
* @param max  - максимальное значение элемента массива
*/
void fillArr(int* arr, size_t size, int min = -100, int max = 100)
{
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = iRand(min, max);
    }
}

/*
* @brief «аполнение массива случайными дробными числами
* @param arr  - массив дробных чисел
* @param size - размер массива
* @param min  - минимальное значение элемента массива
* @param max  - максимальное значение элемента массива
*/
void fillArr(double* arr, size_t size, int min = -100, int max = 100)
{
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = dRand(min, max);
    }
}

/*
* @brief ¬ывод целочисленного массива
* @param arr  - массив целых чисел
* @param size - размер массива
*/
void iArrOut(int* arr, size_t size)
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
* @brief ¬ывод массива дробных чисел
* @param arr  - массив дробных чисел
* @param size - размер массива
*/
void dArrOut(double* arr, size_t size)
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