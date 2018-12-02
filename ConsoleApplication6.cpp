#include <iostream> 
#include <limits.h>

using namespace std;
const int SZ = 4; 

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
	
	int** matr = new int* [SZ];
	for(int i=0; i<SZ; i++)
		matr[i]= new int [SZ];	
	
	for(int i=0; i<SZ; i++)
		for(int j=0; j<SZ; j++){
			cin>>matr[i][j];
		}
	
	/*matr[][] = {
		1, 2, 1, 6,
		8, 1, 3, 0,
		5, 0, 4, 2,
		1, 3, 7, 9
	};
	cout << "1 2 1 6 " << endl;
	cout << "8 1 3 0 " << endl;
	cout << "5 0 4 2 " << endl;
	cout << "1 3 7 9  " << endl;
	*/
	
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
	cout << "?????????? ????? ??? ?????: " << count << endl;
	cout << "???????????? ?????,????????????? ????? ?????? ????: " << max_val << endl;
	system("pause");
	return 0;
}
