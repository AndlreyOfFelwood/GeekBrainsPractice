#include <iostream>

using namespace std;

#define SwapINT(a, b)   tmp = a; a = b; b = tmp

namespace MyFunc
{
    void taskSeparator()
    {
        cout << "\n---------------------------------------------------------------------\n\n";
    }

    double myRand(double fMin = -100, double fMax = 100)
    {
        double f = (double)rand() / RAND_MAX;
        return fMin + f * (fMax - fMin);
    }

    float myRand(float fMin = -100, float fMax = 100)
    {
        float f = (float)rand() / RAND_MAX;
        return fMin + f * (fMax - fMin);
    }

    int myRand(int iMin = -100, int iMax = 100)
    {
        return (rand() % (iMax * 2)) - abs(iMin);
    }

    void fillArr(int* arr, size_t size, int min = -100, int max = 100)
    {
        for (size_t i = 0; i < size; i++)
        {
            arr[i] = myRand(min, max);
        }
    }

    void fillArr(double* arr, size_t size, double min = -100, double max = 100)
    {
        for (size_t i = 0; i < size; i++)
        {
            arr[i] = myRand(min, max);
        }
    }

    void fillArr(float* arr, size_t size, float min = -100, float max = 100)
    {
        for (size_t i = 0; i < size; i++)
        {
            arr[i] = myRand(min, max);
        }
    }

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

    void arrOut(float* arr, size_t size)
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

    void plusMinusCounter(float* arr, size_t size)
    {
        int plus = 0, minus = 0;

        for (size_t i = 0; i < size; i++)
        {
            arr[i] > 0 ? plus++ : minus++;
        }

        cout << "Отрицательных элементов в массиве - " << minus << endl;
        cout << "Положительных элементов в массиве - " << plus << endl;
    }

    void cIn(int& var)
    {
        do
        {
            if (cin.fail())
            {
                cout << "Ошибка, введите ЦЕЛОЕ ЧИСЛО!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize> ::max(), '\n');
            }
            else
                cout << "Введите целое число:\n";

            cin >> var;
        } while (cin.fail());
    }

    void arraySort(int* arr, size_t size)
    {
        int tmp = 0;
        for (size_t i = 0; i < size; i++) {
            for (size_t j = (size - 1); j >= (i + 1); j--) {
                if (arr[j] < arr[j - 1]) {
                    SwapINT(arr[j], arr[j - 1]);
                }
            }
        }
    }
}