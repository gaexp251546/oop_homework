//物件導向程式語言 作業三 資工碩一  溫展榛 m10515050
#include <iostream>

using namespace std;

class matrix
{
public:
	int size;//add data members
	int** array;

	void init(int temp){
		size = temp;
		array = new int*[size];

		for (int i = 0; i<size; i++)
			array[i] = new int[size];
	}

	void transpose(){
		int count = 1;
		for (int j = 0; j < size; j++){
			for (int i = 0; i < size; i++){
				array[i][j] = count;	
				count = count + 1;
			}
		}
	}
	void destroy(){// release the matrix using delete
		for (int i = 0; i<size; i++)
			delete[] array[i];

		delete[] array;
	}
};

void main()
{
	int size;
	cout << "Please input the size of the square matrix." << endl;
	cin >> size;

	matrix m;// create the matrix object

	m.init(size);// using init to setup the matrix object
	
	int count = 1;
	for (int i = 0; i<size; i++)
	{
		for (int j = 0; j<size; j++)
		{
			m.array[i][j] = count;	//this will not work. correct it
			count++;
		}
	}
	for (int i = 0; i<size; i++)// show the matrix on the screen
	{
		for (int j = 0; j<size; j++)
			cout << m.array[i][j] << " ";	

		cout << endl;
	}

	m.transpose();// call transpose() to calculate its transpose

	for (int i = 0; i<size; i++)// show the matrix after transpose on the screen
	{
		for (int j = 0; j<size; j++)
			cout << m.array[i][j] << " ";	

		cout << endl;
	}

	m.destroy();// call destroy to free the object

	system("pause");
}