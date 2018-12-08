#include <iostream>
#include <cmath>
#include <stdlib.h>         //����� ��� �������
#include <time.h>			//����� ��� �������
using namespace std;

void funcStb(int** array, int sstb, int sstr){
	int sString=0;
	for(int i=0; i<sstb; i++){
		int a = 0;
		for(int j=0; j<sstr; j++){
			if(array[i][j] != 0) a++;
		}
		if(a == sstr) sString++;
	}
	cout<<"���������� ����� ��� �������� ��������: "<<sString<<endl;
}

void funcOne(int** array, int sstb, int sstr){	
	int max = INT_MIN;
	int tArray[sstb*sstr];
	int k=0;
	while(k<sstb*sstr){
		for(int i=0; i<sstb; i++)
			for(int j=0; j<sstr; j++){
				tArray[k] = array[i][j];
				k++;
			}
	}
	
	for(int i=0; i<sstb*sstr; i++)
		for(int j=i+1; j<sstb*sstr; j++)
			if(tArray[i] == tArray[j] && tArray[i]>max && i!=j) max = tArray[i];			
					
	cout<<"������������ �� ������������� ����� ������ ����: "<<max<<endl;
}

int main(){
	int stb,str;
	const int varRandom = 10;		
	srand(time(NULL));				//��� �������
	cout<<"���-�� ����� � ��������: ";
	cin>>stb>>str;
	
	int** mass = new int* [stb];
	for(int i=0; i<stb; i++){
		mass[i] = new int[str];
	}
	
	for(int i=0; i<stb; i++)
		for(int j=0; j<str; j++)	
			mass[i][j] = rand()%varRandom;
	for(int i=0; i<stb; i++){
		for(int j=0; j<str; j++)
			cout<<mass[i][j]<<" ";
		cout<<endl;
	}
	
	funcStb(mass,stb,str);
	funcOne(mass,stb,str);
	return 0;
}
