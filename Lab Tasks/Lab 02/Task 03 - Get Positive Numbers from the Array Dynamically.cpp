#include <iostream>
#include <math.h>

using namespace std;

int *getPositiveNumbers(const int ar[], const int size, int &newArrraySize)
{
	int  posCount = 0, j = 0;

	for (int i = 0; i < size; i++)
	{
		if (ar[i] > 0)
		{
			posCount++;
		}
	}

	int *posArray = new int[posCount];

	newArrraySize = posCount;
	*posArray = NULL;

	for (int i = 0; i < size; i++)
	{
		if (ar[i] > 0)
		{
			posArray[j] = ar[i];
			j++;
		}
	}

	return posArray;

}

int main()
{
	int sizeOfArray = 0, sizeOfPos = 0;

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

	getPositiveNumbers(array, sizeOfArray, sizeOfPos);
	int *posArray = new int[sizeOfPos];
	posArray = getPositiveNumbers(array, sizeOfArray, sizeOfPos);;

	cout << endl << "Count of Positive Numbers Are: " << sizeOfPos << endl;

	if (posArray[0] == NULL)
	{
		cout << "No Positive Numbers Exist in the Array!!!" << endl;
	}
	else
	{
		cout << endl << "Positive Number Array is: " << endl;
		for (int i = 0; i < sizeOfPos; i++)
		{
			cout << i + 1 << ") " << posArray[i] << "\n";
		}
	}

	delete[]array;
	return 0;
}
