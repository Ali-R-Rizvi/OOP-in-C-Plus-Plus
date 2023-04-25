#include "iostream"

using namespace std;

class Algebra
{
	//data members of the class
	int a, b;

public:

	//Default Constructor
	Algebra()
	{
		cout << "Default Constructor" << endl;

		a = b = 0;
	}

	//Parameterized Constructor
	Algebra(int a1, int b1)
	{
		cout << "Parameterized Constructor" << endl;

		a = a1;
		b = b1;
	}

	//Copy Constructor
	Algebra(const Algebra& obj)
	{
		cout << "Copy Constructor" << endl;

		a = obj.a;
		b = obj.b;
	}

	//Destructor
	~Algebra()
	{
		cout << "Destructor" << endl;
	}

	//function to set object's data
	void setData(int a1, int b1)
	{
		a = a1;
		b = b1;
	}

	//function to take input for object's data
	void input()
	{
		cout << "Enter a = ";
		cin >> a;

		cout << "Enter b = ";
		cin >> b;
	}

	//function to display object's data on screen
	void print()
	{
		cout << "a = " << a << "\tb = " << b << endl;
	}
};

int main()
{
	Algebra obj1;			//creating object through default constructor

	Algebra obj2(1, 2);		//creating object through parameterized constructor

	Algebra obj3(obj2);		//creating object through copy constructor

	Algebra obj4 = obj3;	//creating object through copy constructor


	obj1.print();	//0	0
	obj2.print();	//1	2
	obj3.print();	//1	2
	obj4.print();	//1	2

	return 0;
}