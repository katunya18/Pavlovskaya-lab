#include "pch.h"
#include <iostream>  
using namespace std;
int main()
{
	setlocale(0, "");
	int n, min, max, proz;
	int im, jm;
	cout << "Введите кол-во элементов: ";
	cin >> n;
	int sum = 0;
	int *a = new int[n];
	while (true)
	{

		system("cls");
		cout << "\t\tМЕНЮ: \n" << endl;
		cout << "1. ввод массива" << endl;
		cout << "2. сумма отр. эл-ов" << endl;
		cout << "3. сортировка" << endl;
		cout << "4. умножение" << endl;
		cout << "5. вывод массива" << endl;
		cout << "0. выход" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			for (int i = 0; i < n; i++)
			{
				cin >> a[i];
			}
			break;

		case 2:
			system("cls");
			for (int i = 0; i < n; i++)
			{
				if (a[i] < 0)
					sum += a[i];
			}
			cout << "Summ = " << sum;
			system("pause");
			break;

		case 3:
			system("cls");
			int temp;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n - 1; j++)
				{
					if (a[j] > a[j + 1])
					{
						temp = a[j];
						a[j] = a[j + 1];
						a[j + 1] = temp;
					}
				}
			}
			cout << "Отсортированный массив:\n ";
			for (int i = 0; i < n; i++)
			{
				cout << a[i] << " ";
			}
			system("pause");
			break;

		case 4:
			system("cls");
			max = a[0];
			min = a[0];

			for (int i = 0; i < n; i++)
			{
				if (a[i] > max)
				{
					max = a[i];
					im = i;
				}
					if (a[i] < min)

				{
					min = a[i];
					jm = i;
				}
			}

			proz = 1;
			if (im > jm)
			{

				for (int i = jm; i <= im; i++)
				{
					proz *= a[i];
				}
			}
			else if (jm > im)
			{
				for (int i = jm; i <= im; i++)
				{
					proz *= a[i];
				}
			}
			cout << "Произведение между максимальным и минимальным элементами = " << proz;
			system("pause");
				break;

		case 5:
			system("cls");
			for (int i = 0; i < n; i++)
			{
				cout << a[i] << " ";
			}
			system("pause");
			break;
		case 0:
			return 0;
			break;
		}
	}
	delete a;
	}