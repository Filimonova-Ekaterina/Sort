#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int encoding_identifier = 1251; //код для использования русского языка
const int array_size = 25; //размер массива

void swap(int& element1, int& element2) //функция перестановки двух элементов массива
{
	int tmp = element1;
	element1 = element2;
	element2 = tmp;
}

void insertion_sort(int arr[]) //функция сортировки вставками
{
	for (int counter = 1; counter < array_size; counter++)
		for (int counter1 = counter; counter1 > 0; counter1--)
		{
			if (arr[counter1] < arr[counter1 - 1]) swap(arr[counter1], arr[counter1 - 1]);
		}
}

void selection_sort(int arr[])//функция сортировки выбором
{
	for (int counter = 0; counter < array_size; counter++)
	{
		int min = counter;
		for (int counter1 = counter+1; counter1 < array_size; counter1++)
		{
			if (arr[counter1] < arr[min])min = counter1;
		}
		swap(arr[counter], arr[min]);
	}
}
void random_sort(int arr[]) //функция случайной сортировки
{
	int sum = 0;
	for (int counter = 0; counter < array_size-1; counter++) { if (arr[counter] <= arr[counter + 1])sum++; }
	while (sum < array_size)
	{
		srand(time(0));
		for (int counter = 0; counter < array_size; counter++)
		{
			swap(arr[counter], arr[rand() % array_size]);
		}
		sum = 0;
		for (int counter = 0; counter < array_size - 1; counter++) { if (arr[counter] <= arr[counter + 1])sum++; }
	}
}

int main()
{
	SetConsoleCP(encoding_identifier);
	SetConsoleOutputCP(encoding_identifier);
	int arr[array_size],arr1[array_size], arr2[array_size];
	cout << "Начальный массив:\n";
	srand(time(0));
	for (int counter = 0; counter < array_size; counter++)
	{
		arr[counter] = rand() % array_size;//заполнение массива случайными числами от 0 до значения размера массива
		cout << arr[counter] << ' ';
	}
	cout << "\n";
	for (int counter = 0; counter < array_size; counter++)
	{
		arr1[counter] = rand() % array_size;//заполнение массива случайными числами от 0 до значения размера массива
		cout << arr1[counter] << ' ';
	}
	cout << "\n";
	for (int counter = 0; counter < array_size; counter++)
	{
		arr2[counter] = rand() % array_size;//заполнение массива случайными числами от 0 до значения размера массива
		cout << arr1[counter] << ' ';
	}
	insertion_sort(arr);
	selection_sort(arr1);
	random_sort(arr2);
	cout << "\nОтсортированный массив:\n";
	for (int counter = 0; counter < array_size; counter++)
	{
		cout << arr[counter] << ' ';
	}
	cout << "\n";
	for (int counter = 0; counter < array_size; counter++)
	{
		cout << arr1[counter] << ' ';
	}
	cout << "\n";
	for (int counter = 0; counter < array_size; counter++)
	{
		cout << arr2[counter] << ' ';
	}
}
