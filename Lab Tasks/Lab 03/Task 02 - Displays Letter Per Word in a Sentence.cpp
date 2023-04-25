// Lab 03
// Task 02 - Displays Letter Per Word in a Sentence

#include <iostream>
#include<stdio.h>
#include <string>

using namespace std;

void letterPerWord(const char* str)
{
	int count = 0;
	cout << "Word" << "\t\t" << "Number of Characters" << endl;
	cout << "-----------------------------------------------------" << endl;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ')
		{
			cout << str[i];
			count++;
		}
		if (str[i] == ' ')
		{
			cout << "\t\t" <<count<< endl;
			count = 0;
		}
		if (str[i+1] == '\0')
		{
			cout << "\t\t" << count << endl;
			count = 0;
		}
	}

	
}

int main()
{
	string input;

	cout << "Please Enter a String: ";
	getline(cin, input);

	letterPerWord(&input[0]);

	return 0;
}
