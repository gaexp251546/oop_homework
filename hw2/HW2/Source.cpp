#include<iostream>
#include<string>

using namespace std;

int main(void){
	int inter = 0,arraynum=0,count=0;
	string *array;
	string choice,temp;
	
	cout << "Please imput the max number of words to be stored: " << endl;
	cin >> inter;
	array = new string[inter];

	while (1){
		cout << "Please imput the word,or command(print/exit):";
		cin >> choice;
		if (choice == "exit"){
			break;}
		if (choice == "print"){
			while (1){     //bubble sort
				for (int i = 0; i <= arraynum; i++){
					if (array[i]>array[i + 1] && array[i] != ""&&array[i+1] != ""){
						temp = array[i];
						array[i] = array[i + 1];
						array[i + 1] = temp;
						++count;}
				}
				if (count == 0){
					break;}
				else{
					count = 0;}
			}
			for (int i = 0; i < arraynum; i++){
				cout << array[i] + "\t";
			}
			cout << endl;
		}
		else{
			if (arraynum == inter){
				cout << "The array is full!!!" << endl;}
			else{
				array[arraynum] = choice;
				arraynum = arraynum + 1;}
		}
	}
	delete[] array;
	system("pause");
	return 0;
}