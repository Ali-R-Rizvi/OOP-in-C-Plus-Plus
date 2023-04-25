#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int sizeOfArray = 0;
	int sum = 0;
	cout << "Enter Size of the Array: ";
	cin >> sizeOfArray;

	int *array = new int[sizeOfArray];

	for (int i = 0; i < sizeOfArray; i++)
	{
		cout << "Enter Array Element No. " << i + 1 << ": ";
		cin >> array[i];
		sum = sum + array[i];
	}

	cout << endl << "Your Input Array is: " << endl;
	for (int i = 0; i < sizeOfArray; i++)
	{
		cout << array[i] << "\n";
	}

	cout << endl << "Sum of All Array Elements is: " << sum;

	delete[]array;
	
	return 0;
}
