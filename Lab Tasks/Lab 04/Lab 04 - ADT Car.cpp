// Lab 04
// ADT - Car

#include "iostream"
#include "string"

using namespace std;

class Car
{
private:
	
	int yearModel;
	string make;
	int speed;

public:
	//Constrctors
	Car(int yearMod, string maker)
	{
		yearModel = yearMod;
		make = maker;
		speed = 0;
	}

	Car(const Car& CarNew)
	{
		yearModel = CarNew.yearModel;
		make = CarNew.make;
		speed = CarNew.speed;
	}

	Car()
	{

	}

	//Destructor
	~Car()
	{
		cout << "Destructor executed....." << endl;
	}

	// Accessors
	int getYear()
	{
		return yearModel;
	}

	string getMake()
	{
		return make;
	}

	int getSpeed()
	{
		return speed;
	}

	//Mutators
	void setYearModel(int a)
	{
		yearModel = a;
	}

	void setMake(string b)
	{
		make = b;
	}

	void setSpeed(int c)
	{
		speed = c;
	}

	//Member Functions
	int setCar(int yearModel, string maker, int speed)
	{
		setYearModel(yearModel);
		setMake(maker);
		setSpeed(speed);
	}

	void getCar()
	{
		cout << "Enter Model of Car: ";
		cin >> yearModel;
		setYearModel(yearModel);

		cout << "Enter Car Maker Name: ";
		cin >> make;
		setMake(make);

		cout << "Enter Speed of Car: ";
		cin >> speed;
		setSpeed(speed);
	}

	

	void putCar()
	{
		cout << "-------------------------------------------------------" << endl;
		cout << "Model of Car is: " << yearModel << endl;
		cout << "Maker of Car is: " << make << endl;
		cout << "Speed of Car is: " << speed << endl;
		cout << "-------------------------------------------------------" << endl;
	}

	int accelerate()
	{
		return speed + 5;
	}

	int brake()
	{
		return speed - 5;
	}
};

int main()
{
	Car obj1(2001, "Suzuki");
	obj1.putCar();

	Car obj2;
	obj2.setCar(2015, "Toyota Camry", 45);
	obj2.putCar();
	return 0;
}
