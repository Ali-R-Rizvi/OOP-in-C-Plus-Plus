#include "iostream"

using namespace std;

//declaring a class
class Algebra
{
public:
	//data members of the class
	int a, b;
};

int main()
{
	//declaring objects of Algebra
	Algebra o1, o2;

	cout << "Address of object o1	= " << &o1 << endl;
	cout << "Address of o1.a		= " << &o1.a << endl;
	cout << "Address of o1.b		= " << &o1.b << endl << endl;

	cout << "Address of object o2	= " << &o2 << endl;
	cout << "Address of o2.a		= " << &o2.a << endl;
	cout << "Address of o2.b		= " << &o2.b << endl << endl;

	cout << "Size of class Algebra  =\t" << sizeof(o1) << endl;
	cout << "Size of object o1      =\t" << sizeof(o1) << endl;
	cout << "Size of object o2      =\t" << sizeof(o2) << endl;

	return 0;
}