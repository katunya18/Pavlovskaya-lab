#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

struct scan_info{
	char model[25];
	int price;
	double x_size;
	double y_size;
	int optr;
	int grey;
};

void zapisFile(int razmer, scan_info* array){
	ofstream file("save.bin", ios::binary | ios_base::trunc);
	file.write((char*)&razmer,sizeof(razmer));
	for(int i=0; i<razmer; i++)
		file.write((char*)&array[i],sizeof(array[i]));
	file.close();
	delete [] array;
}

void fileVivod(){
	int razmer;
	ifstream file("save.bin", ios::binary);
	file.read((char*)&razmer,sizeof(int));
	
	scan_info tStruct;
	
	int chislo;
	
	do{
		cout<<"Номер записи: ";
		cin>>chislo;
		if(chislo>=razmer) cout<<"-1"<<endl;
	} while(chislo>razmer);	
	
	cout<<"0"<<endl;
	
	for(int i=0; i<chislo; i++)
		file.read((char*)&tStruct, sizeof(tStruct));

	cout<<"name="<<tStruct.model<<endl;
	cout<<"prize="<<tStruct.price<<endl;
	cout<<"x_size="<<tStruct.x_size<<endl;
	cout<<"y_size="<<tStruct.y_size<<endl;
	cout<<"optr="<<tStruct.optr<<endl;
	cout<<"gray="<<tStruct.grey<<endl;
	
	}
	
int main(){
	int size;
	char sort;
	cout<<"size="; 
	cin>>size;
	cin.get();
	scan_info* array = new scan_info[size];
	for(int i=0; i<size; i++){
		cout<<"name="; 		
		cin.getline(array[i].model,25);
		cout<<"prize="; 	
		cin>>array[i].price;
		cout<<"x_size="; 	
		cin>>array[i].x_size;
		cout<<"y_size="; 	
		cin>>array[i].y_size;
		cout<<"optr="; 		
		cin>>array[i].optr;
		cout<<"gray="; 		
		cin>>array[i].grey;
		cin.get();
	}
	zapisFile(size,array);
	fileVivod();
	return 0;
}
