#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	float *ptrX = NULL;
	float *ptrY = NULL;

	float *x = new float(4.5);
	float *y = new float(9.3);

	ptrX = x;
	ptrY = y;

	cout << "Address of x: " << &x << endl;
	cout << "Address of ptrX: " << &ptrX << endl;
	cout << "Value of ptrX: " << *ptrX << endl;
	cout << "Value of memory location to which ptrX points: " << ptrX << endl << endl;

	cout << "Address of y: " << &y << endl;
	cout << "Address of ptrY: " << &ptrY << endl;
	cout << "Value of ptrY: " << *ptrY << endl;
	cout << "Value of memory location to which ptrY points: " << ptrY << endl;


	delete ptrX;
	delete ptrY;

	return 0;
}
