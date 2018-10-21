#include "pch.h"
#include <iostream> 
#include <limits.h>
using namespace std;
#define SZ 4 
bool Find(int val, int* ar, int size = SZ, int pos = 0)
{
	for (int i = pos; i < size; i++)
		if (ar[i] == val)
			return true;
	return false;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int matr[][SZ] = {
		1, 2, 1, 6,
		8, 1, 3, 0,
		5, 0, 4, 2,
		1, 3, 7, 9
	};
	cout << "1 2 1 6 " << endl;
	cout << "8 1 3 0 " << endl;
	cout << "5 0 4 2 " << endl;
	cout << "1 3 7 9  " << endl;

	int  count = 0;
	int  max_val = INT_MIN;
	for (int i = 0; i < SZ; i++)
	{
		count += (int)!Find(0, matr[i]);
		for (int j = 0; j < SZ; j++)
			if (matr[i][j] > max_val)
				if (Find(matr[i][j], (int*)matr, SZ * SZ, i * SZ + j + 1))
					max_val = matr[i][j];
	}
	cout << "количество строк без нулей: " << count << endl;
	cout << "максимальное число,встречающееся более одного раза: " << max_val << endl;
	system("pause");
	return 0;
}