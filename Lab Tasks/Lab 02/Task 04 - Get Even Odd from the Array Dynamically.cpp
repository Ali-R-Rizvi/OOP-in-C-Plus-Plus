// Lab 02
// Task 04 - Get Even Odd from the Array Dynamically

#include <iostream>
#include <math.h>

using namespace std;

void getEvenOdd(const int ar[], const int n_ar, int* &even, int& n_even, int* &odd, int& n_odd)
{
	int  evenCount = 0, oddCount = 0, j = 0, k = 0;

	for (int i = 0; i < n_ar; i++)
	{
		if (ar[i] % 2 == 0)
		{
			evenCount++;
		}
		if (ar[i] % 2 != 0)
		{
			oddCount++;
		}
	}

	even = new int[evenCount];
	odd = new int[oddCount];
	n_even = evenCount;
	n_odd = oddCount;
	*even = NULL;
	*odd = NULL;

	for (int i = 0; i < n_ar; i++)
	{
		if (ar[i] % 2 == 0)
		{
			even[j] = ar[i];
			j++;
		}
		if (ar[i] % 2 != 0)
		{
			odd[k] = ar[i];
			k++;
		}
	}

}

int main()
{
	int sizeOfArray = 0, sizeOfEven = 0, sizeOfOdd = 0;
	int *evenArray, *oddArray;

	cout << "Enter Size of the Array: ";
	cin >> sizeOfArray;

	int *array = new int[sizeOfArray];

	for (int i = 0; i < sizeOfArray; i++)
	{
		cout << "Enter Array Element No. " << i + 1 << ": ";
		cin >> array[i];
	}

	cout << endl << "Your Input Array is: " << endl;
	for (int i = 0; i < sizeOfArray; i++)
	{
		cout << array[i] << "\n";
	}

	getEvenOdd(array, sizeOfArray, evenArray, sizeOfEven, oddArray, sizeOfOdd);

	cout << endl << "Count of Even Numbers Are: " << sizeOfEven << endl;
	cout << "Count of Odd Numbers Are: " << sizeOfOdd << endl;

	if (evenArray[0] == NULL)
	{
		cout << "Even Number Array is Empty!!!" << endl;
	}
	else
	{
		cout << endl << "Even Number Array is: " << endl;
		for (int i = 0; i < sizeOfEven; i++)
		{
			cout << i + 1 << ") " << evenArray[i] << "\n";
		}
	}

	if (oddArray[0] == NULL)
	{
		cout << "Odd Number Array is Empty!!!" << endl;
	}
	else
	{
		cout << endl << endl << "Odd Number is: " << endl;
		for (int i = 0; i < sizeOfOdd; i++)
		{
			cout << i + 1 << ") " << oddArray[i] << "\n";
		}
	}

	delete[]array;
	
	return 0;
}
