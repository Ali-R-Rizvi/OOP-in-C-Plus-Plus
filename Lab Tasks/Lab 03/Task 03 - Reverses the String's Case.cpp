#include "iostream"
#include <string>

using namespace std;

char* reverseCase(const char* str)
{
	int count = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		count++;
	}

	if (count == 0)
	{
		return NULL;
	}
	else
	{
		char* newArray = new char[count];
		int j = 0;
		for (int i = 0; str[i] != '\0'; i++)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
			{
				*(newArray + j) = str[i] - 32;
				j++;
			}
			else if (str[i] >= 'A' && str[i] <= 'Z')
			{
				*(newArray + j) = str[i] + 32;
				j++;
			}
			else
			{
				*(newArray + j) = str[i];
				j++;
			}
		}

		return newArray;
	}
}

int main()
{
	string input;

	cout << "Please Enter a String: ";
	getline(cin, input);

	char* reverseArray = reverseCase(&input[0]);

	if (reverseArray[0] == '\0')
	{
		cout << "Array has nothing";
	}
	else
	{
		for (int i = 0; reverseArray[i] != '\0'; i++)
		{
			cout << *(reverseArray + i);
		}
	}
	

	delete[] reverseArray;
	return 0;
}