#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<locale.h>
#include<Windows.h>

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


void fillArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		arr[i] = -3 + rand() % 9;
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << "  ";
	cout << endl << endl;
}

void insertionSort(int arr[], int n)  // сортировка вставкой вариант 1 (меньше итераций)
{
	int count = 0;
	for (int i = 0; i < n; i++)
		for (int j = i; j > 0; j--)
		{
			count++;
			if (arr[j] < arr[j - 1])
				swap(arr[j], arr[j - 1]);
			else
				break;
		}
		//cout << count << endl;
}

void selectionSort(int arr[], int n) // сортировка вставкой вариант 2 (больше итераций)
{
	int min, min_pos;
	int count = 0;

	for (int i = 0; i < n - 1; i++)
	{
		min = INT_MAX;
		for (int j = i; j < n; j++)
		{
			count++;
			if (arr[j] < min)
			{
				min = arr[j];
				min_pos = j;
			}
			swap(arr[i], arr[min_pos]);
		}
	}
	//cout << count << endl;

}

void binarySearch(int arr[], int n, int key)
{
	int low = 0;
	int high = n - 1;
	int middle;
	   
	while (low <= high)

	{
		middle = (low + high) / 2;
		if (arr[middle] < key)
			low = middle + 1;

		else if (arr[middle] > key)
			high = middle - 1;

		else
		{
			cout << "\n Индекс искомого значения в массиве: " << middle <<"\n\n";
			break;
		}
		
	}

	if (arr[middle] != key)
		cout << "\n Искомого значения нет в массиве! \n\n";

}

void binarySearchRecursion(int search, int arr[], int left, int n)
{
	int middle=(left+n)/2;

	if (left > n)
	{
		cout << "\n Искомого значения нет в массиве! \n\n";
		return;
	}
	if (arr[middle] > search)  return binarySearchRecursion(search, arr, left, middle - 1);
	if (arr[middle] < search)  return binarySearchRecursion(search, arr, middle + 1, n);
	if (arr[middle] == search) cout << "\n Индекс искомого значения в массиве: " << middle << "\n\n";
}


int main()
{
	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n Orlov Vladimir  HomeWork_13_02_2019_1550072658 \n\n";
	SetConsoleTextAttribute(hConsole, 7);

	/*1.	Дан одномерный массив целых чисел. Напишите рекурсивную функцию, которая осуществляет нахождения искомого значения
		с помощью бинарного  поиска. Функция возвращает позицию вхождения искомого значения.Проиллюстрируйте работу функции примером.*/

	setlocale(LC_ALL, "");
	srand(time(NULL));

	int key, left=0, n=10, choice=1;
	//int arr[10];
	int arr[10] = { 0,1,2,8,12,21,23,74,81,97 };

	//fillArray(arr, n);
	//printArray(arr, n);
	//insertionSort(arr, n);
	//selectionSort(arr, n);
	printArray(arr, n);

	while (choice==1)
	{
		cout << "Ввведите искомое значение в массиве -> ";
		cin >> key;

		//binarySearch(arr, n, key);
		binarySearchRecursion(key, arr, left, n);

		cout << "Если хотите продолжить, нажмите (1) -> ";
		cin >> choice;
		cout << endl;
	}
}
