#include<iostream>
#include<fstream>

using namespace std;

int main(){
	//try{throw x}...catch(){}..
	try{
		int size = 0;
		int *data = NULL;
		int min,max,ans;
		int myans = 1;

		ifstream file;
		file.open("input.txt");
        file >> min;
		file >> max;
		file >> ans;

		while (myans != ans){
			cout << "please guess an integer number between" << min << " and " << max << endl;
			cin >> myans;
			if (myans > ans&myans <= max){
				max = myans;
			}
			else if (myans < ans&myans >= min){
				min = myans;
			}
			else if (myans == ans){
				cout << "bingo" << endl;
				break;
			}
			else{
				throw "error";//¥á¥X¿ù»~µ¹catch
			}
         }
     }
     catch (const char* str){
		cout <<  str << endl;
	}
    system("pause");
	return 0;
}
