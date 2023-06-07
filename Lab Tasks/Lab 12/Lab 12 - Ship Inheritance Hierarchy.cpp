// Lab 12
// Ship Inheritance Hierarchy 

#include <iostream>
#include<stdio.h>
#include<string>

using namespace std;

// ADT - Ship

class Ship
{
private:

	string name;     // Variable Declaration
	string year;

public:

	Ship(string name = "", string year = "") // 1- Parameterized Constructor
	{
		this->name = name;
		this->year = year;
	}
		

	// Getters

	string getName() const
	{
		return name;
	}

	string getYear() const
	{
		return year;
	}

	// Setters

	void setName(string n)
	{
		this->name = n;
	}

	void setYear(string y)
	{
		this->year = y;
	}

	virtual void print()  // 4- Virtual Print Function
	{
		cout << "Name of Ship: " << name << endl;
		cout << "Year of Built: " << year << endl;
	}
};

// ADT - CruiseShip

class CruiseShip :public Ship
{
private:

	int maxNum;

public:

	CruiseShip(int maxNum = 0, string n = "", string y = "") :Ship(n, y)  // 1- Parameterized Constructor
	{
		this->maxNum = maxNum;
	}

	// Getters

	int getMaxmimumNoOfPassengers() const
	{
		return maxNum;
	}

	// Setters

	void setMaxmimumNoOfPassengers(int n)
	{
		this->maxNum = n;
	}

	void print()  // 4- Virtual Print Function
	{
		Ship::print();
		cout << "Maximum Number of Passengers: " << maxNum << endl;
	}
};


// ADT - CargoShip

class CargoShip :public Ship
{
private:

	int cap;

public:

	CargoShip(int cap = 0, string n = "", string y = "") :Ship(n, y)  // 1- Parameterized Constructor
	{
		this->cap = cap;
	}

	// Getters

	int getCargoCapacity() const
	{
		return cap;
	}

	// Setters

	void setCargoCapacity(int c)
	{
		this->cap = c;
	}

	void print()  // 4- Virtual Print Function
	{
		cout << "Name of Ship: " << Ship::getName() << endl;
		cout << "Cargo Capacity in Tonnage: " << cap << endl;
	}
};

// ADT - BattleShip

class BattleShip :public Ship
{
private:

	int missile;

public:

	BattleShip(int missile = 0, string n = "", string y = "") :Ship(n, y)  // 1- Parameterized Constructor
	{
		this->missile = missile;
	}

	// Getters

	int getTotalNoOfMissile() const
	{
		return missile;
	}

	// Setters

	void setTotalNoOfMissile(int m)
	{
		this->missile = m;
	}

	void print() // 4- Virtual Print Function
	{
		cout << "Name of Ship: " << Ship::getName() << endl;
		cout << "Total Number of Missiles: " << missile << endl;
	}
};

int main()
{
	Ship* arr[4];

	arr[0] = new Ship("King", "2001");
	arr[1] = new CruiseShip(71, "William", "2006");
	arr[2] = new CargoShip(5000, "The Wood", "2003");
	arr[3] = new BattleShip(81, "Commander", "2002");
	
	for (int i = 0; i < 4; i++)
	{
		cout << "----------------------" << endl;
		arr[i]->print();
		cout << "----------------------" << endl;
	}

	for (int i = 0; i < 4; i++)
	{
		delete arr[i];
	}

	return 0;
}

