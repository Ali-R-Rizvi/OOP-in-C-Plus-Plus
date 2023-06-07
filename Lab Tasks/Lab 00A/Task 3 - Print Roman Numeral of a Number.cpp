#include "iostream"

using namespace std;
int main()
{
	int input = 0;
	cout << "Please Enter a Number between 1 and 10: ";
	cin >> input;



	while (input <= 0 || input >= 11)
	{

		cout << "ERROR!! Please Enter a Number between 1 and 10: ";
		cin >> input;
	}

	switch (input)
	{
	case 1:

		cout << "Number 1 is I";
		break;

	case 2:

		cout << "Number 2 is II";
		break;

	case 3:

		cout << "Number 3 is III";
		break;

	case 4:

		cout << "Number 4 is IV";
		break;

	case 5:

		cout << "Number 5 is V";
		break;

	case 6:

		cout << "Number 6 is VI";
		break;

	case 7:

		cout << "Number 7 is VII";
		break;

	case 8:

		cout << "Number 8 is VIII";
		break;

	case 9:

		cout << "Number 9 is IX";
		break;

	case 10:

		cout << "Number 10 is X";
		break;
	}

	 return 0;
}
