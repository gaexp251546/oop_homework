//hw4.cpp

#include <iostream>

using namespace std;
// Please provide the matrix class 
class matrix
{
private:
	int size;//add data members
	int** array;
public:
	matrix(){
		size = 0;
		array = new int*[size];

		for (int i = 0; i<size; i++)

			array[i] = new int[size];
	}
	//copy constructor
	matrix(const matrix &other){
		this->size = other.size;
		this->array = new int*[size];

		for (int i = 0; i < size; i++){
			array[i] = new int[size];
		}

		for (int i = 0; i < size; i++){
			for (int j = 0; j < size; j++){
				array[i][j] = other.array[i][j];
			}
		}
    }
	//copy assignment operator
	matrix& operator=(const matrix& other)
	{
		size = other.size;
		array = new int*[size];

		for (int i = 0; i < size; i++){
			array[i] = new int[size];
		}
		for (int i = 0; i < size; i++){
			for (int j = 0; j < size; j++){
				array[i][j] = other.array[i][j];
			}
		}
		return *this;
	}
	matrix(int temp){
		size = temp;
		array = new int*[size];

		for (int i = 0; i<size; i++)
			array[i] = new int[size];
	}
	void setElement(int i, int j, int k){
		array[i][j] = k;
	}
	int getElement(int i, int j){
		return array[i][j];
	}
	void printSelf(){
		for (int i = 0; i<size; i++)
		{
			for (int j = 0; j<size; j++)
				cout << array[i][j] << " ";

			cout << endl;
		}
	}
	//add copy constructor, copy assignment operator¡C
	~matrix(){// release the matrix using delete
		for (int i = 0; i < size; i++)
			delete[] array[i];

		delete[] array;
	}
};


void main()
{
	// obtain the matrix size from user
	int size;
	cout << "Please input the size of the square matrix." << endl;
	cin >> size;

	// create the matrix object
	matrix* m = new matrix(size);

	// assign the values to the created matrix
	for (int i = 0; i<size; i++)
	for (int j = 0; j<size; j++)
	{
		if (i == j)
			m->setElement(i, j, 10);
		else
			m->setElement(i, j, 1);
	}
	// show the matrix on the screen
	cout << "m = " << endl;
	for (int i = 0; i<size; i++)
	{
		for (int j = 0; j<size; j++)
			cout << m->getElement(i, j) << " ";

		cout << endl;
	}
	//testing standard constructors
	matrix* mArr1 = new matrix[10];	//calling default constructor
	matrix mArr2[5];				//calling default constructor
	matrix m1;						//calling default constructor
	matrix* m2 = new matrix(*m);	//calling copy constructor
	matrix m3 = matrix(*m);			//calling copy constructor

	m1 = *m;						//calling copy assignment operator

	//show the testing matrix objects
	cout << "m1 = " << endl;
	m1.printSelf();
	cout << "*m2 = " << endl;
	m2->printSelf();
	cout << "m3 = " << endl;
	m3.printSelf();

	// delete the dynamic allocated object
	delete m;//1.error
	delete[] mArr1;
	delete m2;//3.error
	system("pause");
}

