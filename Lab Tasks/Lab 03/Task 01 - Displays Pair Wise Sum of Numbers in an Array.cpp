#include "iostream"

using namespace std;

int* pairWiseSum(const int ar[], const int size, int& newArraySize)
{
	int j = 0, k = 0;

	if (size == 0 || size < 0)
	{
		newArraySize = 0;
		return NULL;
	}

	if (size % 2 == 0)
	{
		newArraySize = size / 2;
	}

	else if (size % 2 != 0)
	{
		newArraySize = (size / 2) + 1;
	}

	int* sum = new int[newArraySize];

	for (int i = 0; i < newArraySize; i++)//Initialization of Array
	{
		*(sum + i) = 0;
	}
	
	if (size % 2 == 0) //For Even Size
	{
		for (int i = 0; i < newArraySize; i++)
		{
			*(sum + j) = ar[k] + ar[k + 1];
			k = k + 2;
			j = j + 1;
		}
		return sum;
	}
	
	if (size % 2 != 0) //For Odd Size
	{
		for (int i = 0; i < newArraySize; i++)
		{
			if (i == newArraySize - 1)
			{
				*(sum + j) = ar[k];
			}
			else
			{
				*(sum + j) = ar[k] + ar[k + 1];
				k = k + 2;
				j = j + 1;
			}
		}
		return sum;
	}
}

int main()
{
	int sizeOfArray = 0, newSize = 0;

	cout << "Enter Size of the Array: ";
	cin >> sizeOfArray;

	if (sizeOfArray == 0 || sizeOfArray < 0)
	{
		cout << "ERROR!! Array Size is Not Valid." << endl;
		exit;
	}
	else
	{
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

		pairWiseSum(array, sizeOfArray, newSize);


		cout << endl << "Size of New Array is: " << newSize << endl;
		int* sumArray = new int[newSize];

		sumArray = pairWiseSum(array, sizeOfArray, newSize);

		cout << "---------------------------------------------" << endl;
		cout << "New Pair Wise Sum Array is: " << endl;
		for (int i = 0; i < newSize; i++)
		{
			cout << *(sumArray + i) << "\t";
			cout << "\n";
		}
		cout << "---------------------------------------------" << endl;
		delete (array);
		delete (sumArray);
	}
	return 0;
}