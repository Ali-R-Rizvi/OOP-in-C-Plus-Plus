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

		setA(a1);
		setB(b1);
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

	//setter for data memeber a
	void setA(int a1)
	{
		if (a1 > 0)
			a = a1;
		else
			a = 0;
	}

	//getter for data memeber a
	int getA()
	{
		return a;
	}

	//setter for data memeber b
	void setB(int b1)
	{
		if (b1 > 0)
			b = b1;
		else
			b = 0;
	}

	//getter for data memeber b
	int getB()
	{
		return b;
	}

	//function to set object's data
	void setData(int a1, int b1)
	{
		setA(a1);
		setB(b1);
	}

	//function to take input for object's data
	void input()
	{
		cout << "Enter a = ";
		cin >> a;

		cout << "Enter b = ";
		cin >> b;

		setA(a);
		setB(b);
	}

	//function to display object's data on screen
	void print()
	{
		cout << "a = " << a << "\tb = " << b << endl;
	}
};

int main()
{
	Algebra obj1;				//creating object through default constructor

	Algebra obj2(-1, 2);		//creating object through parameterized constructor

	Algebra obj3(obj2);			//creating object through copy constructor

	obj3.setA(99);

	obj1.print();	//0	0
	obj2.print();	//0	2
	obj3.print();	//1	99

	cout << obj2.getB() << endl;	//2	

	return 0;
}