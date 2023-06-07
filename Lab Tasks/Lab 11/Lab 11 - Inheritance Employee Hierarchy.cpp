// Lab 11
// Inheritance Employee Hierarchy

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

class Employee
{
private:
	string firstname;
	string lastname;
	string SSN;

public:

	Employee(string f, string l, string ssn) // 1- Parameterized Constructor
	{
		this->firstname = f;
		this->lastname = l;
		this->SSN = ssn;
	}

	// Getters

	string getFirstName()
	{
		return firstname;
	}

	string getLastName()
	{
		return lastname;
	}

	string getSSN()
	{
		return SSN;
	}

	// Setters

	void setFirstName(string f)
	{
		this->firstname = f;
	}

	void setLastName(string l)
	{
		this->lastname = l;
	}

	void setSSN(string ssn)
	{
		this->SSN = ssn;
	}

	virtual void print()  // 4- Virtual Print Function
	{
		cout << "Name: " << firstname << " " << lastname << endl;
		cout << "Social Security Number: " << SSN << endl;
	}

	virtual double earnings() = 0;  // 5- Pure Virtual Functions
};

class SalariedEmployee :public Employee
{
private:
	double weeklySalary;

public:

	SalariedEmployee(string f, string l, string ssn, double weeklySalary = 0.00) :Employee(f,l,ssn)  // 1- Parameterized Constructor
	{
		this->weeklySalary = 0.00;
	}

	// Getters

	double getWeeklySalary()
	{
		return weeklySalary;
	}

	// Setters

	void setWeeklySalary(double w)
	{
		this->weeklySalary = w;
	}

	void print()  // 4- Virtual Print Function
	{
		Employee::print();
		cout << "Weekly Salary of the Employee: " << weeklySalary << endl;
	}

	double earnings() // 5- Pure Virtual Functions
	{
		return weeklySalary;
	}
};

class HourlyEmployee :public Employee
{
private:
	double wage;
	double hours;

public:

	HourlyEmployee(string f, string n, string ssn, double wage = 0.00, double hours = 0.00) : Employee(f, n, ssn) // 1- Parameterized Constructor
	{
		this->wage = 0.00;
		this->hours = 0.00;
	}

	// Getters

	double getWage()
	{
		return wage;
	}

	double getHours()
	{
		return hours;
	}

	// Setters

	void setWage(double w)
	{
		this->wage = w;
	}

	void setHours(double h)
	{
		this->hours = h;
	}

	void print()  // 4- Virtual Print Function
	{
		Employee::print();
		cout << "Wage of the Employee: " << wage << endl;
		cout << "Hours of the Employee: " << hours << endl;
	}

	double earnings() // 5- Pure Virtual Functions
	{
		return wage * hours;
	}
};

class CommissionEmployee :public Employee
{
private:
	double grossSales;
	double commissionRate;

public:

	CommissionEmployee(string f, string n, string ssn, double grossSales = 0.00, double commissionRate = 0.00) : Employee(f, n, ssn) // 1- Parameterized Constructor
	{
		this->grossSales = 0.00;
		this->commissionRate = 0.00;
	}

	// Getters

	double getGrossSales()
	{
		return grossSales;
	}

	double getCommissionRate()
	{
		return commissionRate;
	}

	// Setters

	void setGrossSales(double g)
	{
		this->grossSales = g;
	}

	void setCommissionRate(double c)
	{
		this->commissionRate = c;
	}

	void print()  // 4- Virtual Print Function
	{
		Employee::print();
		cout << "Gross Sales of the Employee: " << grossSales << endl;
		cout << "Commission Rate of the Employee: " << commissionRate << endl;
	}

	double earnings() // 5- Pure Virtual Functions
	{
		return commissionRate * grossSales;
	}
};

class basePlusCommissionEmployee :public CommissionEmployee
{
private:
	double baseSalary;

public:

	basePlusCommissionEmployee(string f, string n, string ssn, double baseSalary = 0.00) :CommissionEmployee(f, n, ssn) // 1- Parameterized Constructor
	{
		this->baseSalary = 0.00;
	}

	// Getters

	double getBaseSalary()
	{
		return baseSalary;
	}

	// Setters

	void setBaseSalary(double b)
	{
		this->baseSalary = b;
	}

	void print()  // 4- Virtual Print Function
	{
		CommissionEmployee::print();
		cout << "Base Salary of the Employee: " << baseSalary << endl;
	}

	double earnings() // 5- Pure Virtual Functions
	{
		return CommissionEmployee::earnings() + baseSalary;
	}
};


int main()
{
	Employee* eptr[4];
	
	SalariedEmployee obj2("Ali","Raza","100");
	obj2.print();
	
	HourlyEmployee obj3("Shehryar", "Khan", "150");
	cout << endl << "------------------------------------" << endl;
	obj3.print();

	CommissionEmployee obj4("Malik", "Haider", "170");
	cout << endl << "------------------------------------" << endl;
	obj4.print();

	basePlusCommissionEmployee obj5("Muhammad", "Ali", "180");
	cout << endl << "------------------------------------" << endl;
	obj5.print();

	eptr[0] = &obj2;
	eptr[1] = &obj3;
	eptr[2] = &obj4;
	eptr[3] = &obj5;

	for (int i = 0; i < 4; i++)
	{
		cout << endl << "------------------------------------" << endl;
		eptr[i]->earnings();
		eptr[i]->print();
		cout << endl << "------------------------------------" << endl;
	}
	return 0;
}
