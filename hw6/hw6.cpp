//hw6.cpp

#include <iostream>
#include <assert.h>

using namespace std;

class matrix;
class vector;

class matrix
{
private:
	int size;//add data members
	int** array;
	static int count;
public:
	matrix(){
		size = 0;
		array = new int*[size];

		for (int i = 0; i<size; i++)
			array[i] = new int[size];

		count++;
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
		count++;
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
		count++;
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
	friend vector &MmultV(matrix &m, vector &v);
	friend vector VmultM(vector &v, matrix &m);
	
	static int getCount(){
		return count;
	}
	//add copy constructor, copy assignment operator¡C
	~matrix(){// release the matrix using delete
		for (int i = 0; i < size; i++)
			delete[] array[i];

		delete[] array;
		
		count--;
	}
};

class vector
{
private:
	int size;//add data members
	int* array;
	static int count;
public:
	vector(){
		size = 0;
		array = new int[size];
		count++;
	}
	//copy constructor
	vector(const vector &other){
		this->size = other.size;
		this->array = new int[size];

		for (int i = 0; i < size; i++){
		    array[i] = other.array[i];
		}
		count++;
	}
	//copy assignment operator
	vector& operator=(const vector& other)
	{
		size = other.size;
		array = new int[size];
		for (int i = 0; i < size; i++)
			array[i] = other.array[i];
	
		return *this;
	}
	vector(int temp){
		
		size = temp;
		array = new int[size];
		count++;
	}
	void setElement(int i, int j){
		array[i]=j;
	}
	int getElement(int i){
		return array[i];
	}
	void printSelf(){
		for (int i = 0; i<size; i++)
			cout << array[i] << " ";
		cout << endl;
	}
	friend vector &MmultV(matrix &m, vector &v);
	friend vector VmultM(vector &v, matrix &m);
	//add copy constructor, copy assignment operator¡C
	static int getCount(){
		return count;
	}

	~vector(){// release the matrix using delete
		delete[] array;
		count--;
	}
};

int matrix::count = 0;
int vector::count = 0;

vector &MmultV(matrix &m, vector &v){
	vector *temp = new vector(m.size);
	int value = 0;
	
	for (int i = 0; i < m.size; i++){
		for (int j = 0; j < m.size; j++){
			value = m.array[i][j] * v.array[j] + value;
		}
		temp->array[i] = value;
		value = 0;
	}

	return *temp; 
}
vector VmultM(vector &v, matrix &m){
	vector *temp = new vector(m.size);
	int value = 0;
	
	for (int i = 0; i < m.size; i++){
		for (int j = 0; j < m.size; j++){
			value = m.array[j][i] * v.array[j] + value;
		}
		temp->array[i] = value;
		value = 0;
	}

	return *temp;
}

void main()
{
	// obtain the matrix size from user
	int size;
	cout<<"Please input the size of the matrix and vector."<<endl;
	cin>>size;

	// create the matrix and vector object
	matrix* m = new matrix(size);
	vector* v = new vector(size);

	// assign the values to the created matrix and vector
	for(int i=0; i<size; i++)
		for(int j=0; j<size; j++)
		{
			if(i==j)
				m->setElement(i,j,10);	
			else
				m->setElement(i,j,1);	
		}

	for(int i=0; i<size; i++)
		v->setElement(i,i+1);

	//show the matrix and vector on the screen
	cout<<"m = "<<endl;
	for (int i = 0; i<size; i++)
	{
		for(int j=0; j<size; j++)
			cout<<m->getElement(i,j)<<" ";

		cout<<endl;
	}

	cout<<"v = "<<endl;
	for (int i = 0; i<size; i++)
		cout<<v->getElement(i)<<" ";

	cout<<endl;

	//test the standard constructors
	matrix* mArr1 = new matrix[10];	//calling default constructor
	matrix mArr2[5];				//calling default constructor
	matrix m1;						//calling default constructor
	matrix* m2 = new matrix(*m);	//calling copy constructor
	matrix m3 = matrix(*m);			//calling copy constructor
	m1 = *m;						//calling copy assignment operator
	vector* vArr1 = new vector[10];	//calling default constructor
	vector vArr2[5];				//calling default constructor
	vector v1;						//calling default constructor
	vector* v2 = new vector(*v);	//calling copy constructor
	vector v3 = vector(*v);			//calling copy constructor
	v1 = *v;						//calling copy assignment operator

	//test MmultV and VmultM
	vector& ans1 = MmultV(*m,*v);
	cout<<"ans1="<<endl;
	ans1.printSelf();

	vector ans2 = VmultM(*v,*m);
	cout<<"ans2="<<endl;
	ans2.printSelf();
	
	//test counting object
	cout<<"You have create "<<matrix::getCount()<<" matrices and "
		<<vector::getCount()<<" vectors in this program."<<endl;
		
	// delete the dynamic allocated object
	delete m;
	delete [] mArr1;
	delete m2;
	delete v;
	delete [] vArr1;
	delete v2;

	//test counting object
	cout<<"After deleting, there are "<<matrix::getCount()<<" matrices and "
		<<vector::getCount()<<" vectors in this program."<<endl;
	system("pause");
}

