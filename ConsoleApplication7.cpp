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
	int size;
	cout<<"������� ����� ���������: ";
	cin>>size;
	cin.get();
	student* array = new student [size];

	for (int i = 0; i < size; i++) {
		cout << "������� ������� � ��������:";
		getline(cin, array[i].name);
		cout << "������� ����� ������:";
		cin >> array[i].group;
		cout << "������� ������������ (5 ��������� ����� ������): ";
			for (int j = 0; j < 5; j++) {
			cin >> array[i].mark[j];
			array[i].secondarymark += array[i].mark[j];
		}

		array[i].secondarymark = array[i].secondarymark / 5;
		cin.get();
	}

	for (int i = 0; i < size - 1; i++)
		for (int j = 0; j < size - 1 - i; j++)
			if (array[j].group > array[j + 1].group) {
				var = array[j];
				array[j] = array[j + 1];
				array[j + 1] = var;
			}
	cout << "-------------" << endl;
	cout << "����� ��������� �� ����������� ������ ������: " << endl;
	   	  
	for (int i = 0; i < size; i++) {
				cout << "���: " << array[i].name;
				cout << " ����� ������:" << array[i].group << endl;
	for (int j = 0; j < 5; j++)
				if (array[i].mark[j] > 3) array[i].schet++;
	}cout << "-------------" << endl;


	int j = 0;
	for (int i = 0; i < size; i++) {
			if (array[i].secondarymark > 3.9) {
			cout << "�������, � �������� ��. ���� ���� 4,0: " << array[i].name << endl;
			cout << "����� ������: " << array[i].group << endl;
			j++;
		}
	}
	
	if (j=0) cout << "��� ����� ��������� � ������� ������� ���� ���� 4,0"<<endl;

	
	system("PAUSE");
	return 0;
	}
