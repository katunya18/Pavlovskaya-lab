#include <iostream>
#include <cmath>
#include <stdlib.h>         //Библа для рандома
#include <time.h>			//Библа для рандома
using namespace std;

int main(){
	int stb,str;
	const int varRandom = 10;		
	srand(time(NULL));				//Для рандома
	cout<<"Кол-во строк и столбцов: ";
	cin>>stb>>str;
	
	int** mass = new int* [stb];
	for(int i=0; i<stb; i++){
		mass[i] = new int[str];
	}
	int sString=0;
	int max = INT_MIN;
	
	for(int i=0; i<stb; i++)
		for(int j=0; j<str; j++)	
			mass[i][j] = rand()%varRandom;
	for(int i=0; i<stb; i++){
		for(int j=0; j<str; j++)
			cout<<mass[i][j]<<" ";
		cout<<endl;
	}
	for(int i=0; i<stb; i++){
		int a = 0;
		for(int j=0; j<str; j++){
			if(mass[i][j] != 0) a++;
		}
		if(a == str) sString++;
	}
	cout<<"Количество строк без нулевого элемента: "<<sString<<endl;
	
	int mass2[stb*str];
	int k=0;
	
	while(k<stb*str){
		for(int i=0; i<stb; i++)
			for(int j=0; j<str; j++){
				mass2[k] = mass[i][j];
				k++;
			}
	}
	
	for(int i=0; i<stb*str; i++)
		for(int j=i+1; j<stb*str; j++)
			if(mass2[i] == mass2[j] && mass2[i]>max && i!=j) max = mass2[i];			
					
	cout<<"Максимальное из встречающихся более одного раза: "<<max<<endl;
	
	return 0;
}
