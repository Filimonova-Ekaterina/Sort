#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int encoding_identifier = 1251;
const int array_size = 5;

void swap(int& element1, int& element2)
{
	int tmp = element1;
	element1 = element2;
	element2 = tmp;
}

void insertion_sort(int arr[])
{
	for (int counter = 1; counter < array_size; counter++)
		for (int counter1 = counter; counter1 > 0; counter1--)
		{
			if (arr[counter1] < arr[counter1 - 1]) swap(arr[counter1], arr[counter1 - 1]);
			else break;
		}
}

void selection_sort(int arr[])
{
	for (int counter = 0; counter < array_size; counter++)
	{
		int min = counter;
		for (int counter1 = counter + 1; counter1 < array_size; counter1++)
		{
			if (arr[counter1] < arr[min])min = counter1;
		}
		swap(arr[counter], arr[min]);
	}
}
void random_sort(int arr[])
{
	int sum=0;
	for (int counter = 0; counter < array_size - 1; counter++) { if (arr[counter] <= arr[counter + 1]) sum++; }
	while (sum < array_size-1)
	{
		srand(time(0));
		swap(arr[rand() % array_size], arr[rand() % array_size]);
		sum = 0;
		for (int counter = 0; counter < array_size - 1; counter++) { if (arr[counter] <= arr[counter + 1])sum++; }
	}
}

int main()
{
	SetConsoleCP(encoding_identifier);
	SetConsoleOutputCP(encoding_identifier);
	int arr[array_size], arr1[array_size], arr2[array_size];
	cout << "Initial array:\n";
	srand(time(0));
	for (int counter = 0; counter < array_size; counter++)
	{
		arr[counter] = rand() % array_size;
		cout << arr[counter] << ' ';
	}
	cout << "\n";
	for (int counter = 0; counter < array_size; counter++)
	{
		arr1[counter] = rand() % array_size;
		cout << arr1[counter] << ' ';
	}
	cout << "\n";
	for (int counter = 0; counter < array_size; counter++)
	{
		arr2[counter] = rand() % array_size;
		cout << arr2[counter] << ' ';
	}
	insertion_sort(arr);
	cout << "\nSort array:\n";
	for (int counter = 0; counter < array_size; counter++)
	{
		cout << arr[counter] << ' ';
	}
	cout << "\n";
	selection_sort(arr1);
	for (int counter = 0; counter < array_size; counter++)
	{
		cout << arr1[counter] << ' ';
	}
	cout << "\n";
	random_sort(arr2);
	for (int counter = 0; counter < array_size; counter++)
	{
		cout << arr2[counter] << ' ';
	}
}
