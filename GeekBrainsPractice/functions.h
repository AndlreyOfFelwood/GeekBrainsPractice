#pragma once
#include <iostream>

using namespace std;

namespace MyFunc
{
	// Функция-разделитель вывода задач
	void taskSeparator();


	/*
	* @brief – Рандомайзер чисел типа int
	* @param fMin - минимальное значение случайного числа
	* @param fMax - максимальное значение случайного числа
	*/
	int myRand(int iMin = -100, int iMax = 100);


	/*
	* @brief – Рандомайзер чисел типа float
	* @param fMin - минимальное значение случайного числа
	* @param fMax - максимальное значение случайного числа
	*/
	float myRand(float fMin = -100, float fMax = 100);


	/*
	* @brief – Рандомайзер чисел типа double
	* @param fMin - минимальное значение случайного числа
	* @param fMax - максимальное значение случайного числа
	*/
	double myRand(double fMin = -100, double fMax = 100);


	/*
	* @brief Заполнение массива случайными целыми числами
	* @param arr  - целочисленный массив
	* @param size - размер массива
	* @param min  - минимальное значение элемента массива
	* @param max  - максимальное значение элемента массива
	*/
	void fillArr(int* arr, size_t size, int min = -100, int max = 100);

	/*
	* @brief Заполнение массива случайными дробными числами
	* @param arr  - массив дробных чисел
	* @param size - размер массива
	* @param min  - минимальное значение элемента массива
	* @param max  - максимальное значение элемента массива
	*/
	void fillArr(double* arr, size_t size, double min = -100, double max = 100);

	/*
	* @brief Заполнение массива случайными дробными числами
	* @param arr  - массив дробных чисел
	* @param size - размер массива
	* @param min  - минимальное значение элемента массива
	* @param max  - максимальное значение элемента массива
	*/
	void fillArr(float* arr, size_t size, float min = -100, float max = 100);

	/*
	* @brief Вывод целочисленного массива
	* @param arr  - массив целых чисел
	* @param size - размер массива
	*/
	void arrOut(int* arr, size_t size);

	/*
	* @brief Вывод массива дробных чисел
	* @param arr  - массив дробных чисел
	* @param size - размер массива
	*/
	void arrOut(double* arr, size_t size);

	/*
	* @brief Вывод массива дробных чисел
	* @param arr  - массив дробных чисел
	* @param size - размер массива
	*/
	void arrOut(float* arr, size_t size);

	/*
	* @brief Функция считает количество положительных и отрицательных элементов в массиве типа float
	* @param arr - указатель на одномерный массив типа float
	* @param size - размер массива
	*/
	void plusMinusCounter(float* arr, size_t size);

	/*
	* @brief Функция безопасного получения данных от пользователя
	* @param var - ссылка на переменную в которую пользователь должен записать значение
	*/
	void cIn(int& var);

	/*
	* @brief Функция сортировки пузырьком
	* @param arr - указатель на сортируемый массив
	* @param size - размер сортируемого массива
	*/
	void arraySort(int* arr, size_t size);
}