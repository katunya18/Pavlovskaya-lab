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
	setlocale(LC_ALL, "Russian");
	string line;
	ifstream myfile("D:\\proverka2.txt");
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
	int Counter = 0;   //Объявляем счетчик
	for (int i = 0; i <= Length; i++)
	{
		if ((Text[i] == '.') && (Text[i] == '!') && (Text[i] == '?')) //Проверяем символ, если он !, ., или ?
		{
			Counter++;
		}                             //То прибавить 1 к счетчику предложений

		cout << "\nПредложений в тексте: " << Counter;
	}
	system("Pause");
	return 0;

}
	
	