# include "pch.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

int main() {
	char button;
	char words[1000];
	int Lenght = 0;
	int sStrings = 0;
	char** proverka = new char*[sStrings];
	setlocale(LC_ALL, "Russian");
	string line;
	ifstream myfile("D:\\proverka2.dat");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			cout << line << '\n';
		}
		myfile.close();
	}
	else cout << "Не удается открыть файл";
	string Text;
	const int Length = Text.length();
	int Counter = 0;  
	for (int i = 0; i <= Length; i++)
	{
		if ((Text[i] == '.') || (Text[i] == '!') || (Text[i] == '?')) //Проверяем символ, если он !, ., или ?
		{
			Counter++;
		}                             

		cout << "\nПредложений в тексте: " << Counter;
	}
	int q1=0;
	while(q1<sStrings+1)
		
	for(int i=0; i<sStrings; i++)
		for(int j=0;j<strlen(proverka[i])+1;j++){

			if(proverka[i][j]=='\0') predlogenia[q1]='.';
			else predlogenia[s1]=proverka[i][j];
			q1++;
		}

	q1=0;
	while(q1<strlen(predlogenia)-2){
		cout<<endl;
		cout<<"Нажмите H для выделения предложений ";
		cin>>button;
		if(button=='H'){

			while(predlogenia[q1]!='.')  || (predlogenia[q1]!='?')  || (predlogenia[q1]!='!'){
				cout<<predlogenia[q1];
				q1++;
			}

		q1++;
		cout<<endl;
		}
	}
	system("Pause");
	return 0;
}

	
	
