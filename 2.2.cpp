#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	int size = 5; 

	// выделяем память для указателей на строки матрицы
	int** arrWithDigits = new int* [size];
	for (int i = 0; i < size; i++)
	{
		arrWithDigits[i] = new int[size]; // выделение памяти для каждого элемента строки матрицы
	}
	
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			arrWithDigits[i][j] = 10 + rand() % 90; // заполняем числами от 10 до 99
			cout << arrWithDigits[i][j] << " | ";   // показываем
		}
		cout << endl;
	}
	cout << endl << endl;

	// поиск максимального значение в строке матрицы

	int max = 0;	// для записи максимального значения
	int buf = 0;	// буфер для перестановки местами значений
	int x = 0;		// для записи номера строки в котором ищем максимальное значение
	int y = 0;		// для записи номера столбца с максимальным значением

	for (int i = 0; i < size; i++)
	{
		max = arrWithDigits[i][0];
		for (int j = 1; j < size; j++)
		{
			if (arrWithDigits[i][j] > max)
			{
				max = arrWithDigits[i][j];
				x = i;  // запоминаем номер строки
				y = j;	// запоминаем номер столбца
			}
		}
		// замена максимума с первым элементом в строке
		if (arrWithDigits[i][0] < max)
		{
			buf = arrWithDigits[i][0];
			arrWithDigits[i][0] = max;
			arrWithDigits[x][y] = buf;
		}
	}

	cout << "Матрица после перестановки максимальных значений в строке: "<< endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << arrWithDigits[i][j] << " | ";
		}
		cout << endl;
	}
	cout << endl << endl;

	// освобождение памяти
	for (int i = 0; i < size; i++)
	{
		delete[] arrWithDigits[i]; //  освобождаем память ячеек
	}
	delete[] arrWithDigits; // память под указатели на строки матрицы
	return 0;
}
