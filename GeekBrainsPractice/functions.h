#pragma once
#include <iostream>

using namespace std;


// �������-����������� ������ �����
void taskSeparator()
{
    cout << "\n---------------------------------------------------------------------\n\n";
}


/* 
* @brief ����������� ����� ���� double
* @param fMin - ����������� �������� ���������� �����
* @param fMax - ������������ �������� ���������� �����
*/
double dRand(double fMin = -100, double fMax = 100)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}


/* 
* @brief ����������� ����� ���� int
* @param fMin - ����������� �������� ���������� �����
* @param fMax - ������������ �������� ���������� �����
*/
int iRand(int iMin = -100, int iMax = 100)
{
    return (rand() % (iMax * 2)) - iMin;
}


/*
* @brief ���������� ������� ���������� ������ �������
* @param arr  - ������������� ������
* @param size - ������ �������
* @param min  - ����������� �������� �������� �������
* @param max  - ������������ �������� �������� �������
*/
void fillArr(int* arr, size_t size, int min = -100, int max = 100)
{
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = iRand(min, max);
    }
}

/*
* @brief ���������� ������� ���������� �������� �������
* @param arr  - ������ ������� �����
* @param size - ������ �������
* @param min  - ����������� �������� �������� �������
* @param max  - ������������ �������� �������� �������
*/
void fillArr(double* arr, size_t size, int min = -100, int max = 100)
{
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = dRand(min, max);
    }
}

/*
* @brief ����� �������������� �������
* @param arr  - ������ ����� �����
* @param size - ������ �������
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
* @brief ����� ������� ������� �����
* @param arr  - ������ ������� �����
* @param size - ������ �������
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