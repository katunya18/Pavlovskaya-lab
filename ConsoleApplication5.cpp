#include "pch.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

struct student {
	string name;
	int group;
	int mark[5];
	int schet;
	float secondarymark = 0;
};

int main()
{
setlocale(LC_ALL, "Russian");
	student var;
	student array[10];

	for (int i = 0; i < 10; i++) {
		cout << "Введите фамилию и инициалы:";
		getline(cin, array[i].name);
		cout << "Введите номер группы:";
		cin >> array[i].group;
		cout << "Введите успеваемость (5 элементов через пробел): ";
			for (int j = 0; j < 5; j++) {
			cin >> array[i].mark[j];
			array[i].secondarymark += array[i].mark[j];
		}

		array[i].secondarymark = array[i].secondarymark / 5;
		cin.get();
	}

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9 - i; j++)
			if (array[j].group > array[j + 1].group) {
				var = array[j];
				array[j] = array[j + 1];
				array[j + 1] = var;
			}
	cout << "-------------" << endl;
	cout << "Вывод студентов по возрастанию номера группы: " << endl;
	   	  
	for (int i = 0; i < 10; i++) {
				cout << "ФИО: " << array[i].name;
				cout << " номер группы:" << array[i].group << endl;
	for (int j = 0; j < 5; j++)
				if (array[i].mark[j] > 3) array[i].schet++;
	}cout << "-------------" << endl;



	for (int i = 0; i < 10; i++) {
				int j = 0;
				if (array[i].secondarymark > 3.9) {
			cout << "Студент, у которого ср. балл выше 4,0: " << array[i].name << endl;
			cout << "Номер группы: " << array[i].group << endl;
			j++;

		}
		else
			if (array[i].secondarymark < 3.9) cout << "Нет таких студентов у которых средний балл выше 4,0";
		}
		system("PAUSE");
	return 0;
	}