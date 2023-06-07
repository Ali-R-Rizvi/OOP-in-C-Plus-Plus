#include "iostream"
#include "iomanip"

using namespace std;

int main()
{
	int choice = 0;
	float speed = 0.00, distance = 0.00;
	float time = 0.0000;

	cout << "Medium                 Speed" << endl;
	cout << "1-Air                  1,100 feet per second " << endl;
	cout << "2-Water                4,900 feet per second" << endl;
	cout << "3-Steel                16,400 feet per second" << endl;


	cout << "Enter Your Choice(from 1 to 3): ";
	cin >> choice;

	while (choice <= 0 || choice >= 4)
	{
		cout << "Wrong Choice!! Enter Choice Again: ";
		cin >> choice;
	}
	if (choice == 1)
	{
		speed = 1100;
	}
	if (choice == 2)
	{
		speed = 4900;
	}
	if (choice == 3)
	{
		speed = 16400;
	}
	cout << "Enter Distance: ";
	cin >> distance;


	time = distance / speed;

	cout << "Time Taken is: " << fixed << setprecision(4) << time;
	return 0;
}
