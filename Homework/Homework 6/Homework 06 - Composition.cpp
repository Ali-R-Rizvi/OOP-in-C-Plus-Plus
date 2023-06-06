// Homework 06
// Composition
// ADT - NumDays
// ADT - TimeOff

#include <iostream>
#include<stdio.h>
#include<string>

using namespace std;

// ADT - NumDays

class NumDays
{
private:

	float workHours;     // Variable Declaration

public:

	NumDays(float hours)  // Parameterized Constructor
	{
		this->workHours = hours;
	}

	// Getters

	float getDays() const
	{
		return workHours / 8.00;
	}

	float getHours() const
	{
		return workHours;
	}

	// Setters

	void setDays(float days)
	{
		this->workHours = days * 8.00;
	}

	void setWorkHours(float hours)
	{
		this->workHours = hours;
	}

	// Overloaded Operators

	NumDays operator+(const NumDays& obj)  // 1- Overloaded + Operator
	{
		NumDays temp(0);

		temp.workHours = this->workHours + obj.workHours;

		return temp;
	}

	NumDays operator-(const NumDays& obj)  // 2- Overloaded - Operator
	{
		NumDays temp(0);

		temp.workHours = this->workHours - obj.workHours;

		return temp;
	}

	NumDays operator++()  // 3- Overloaded Pre-Increment Operator
	{
		this->workHours = this->workHours + 1.00;
		
		return *this;
	}

	NumDays operator++(int)  // 4- Overloaded Post-Increment Operator
	{
		NumDays temp(*this);

		this->workHours = this->workHours + 1.00;

		return temp;
	}

	NumDays operator--()  // 5- Overloaded Pre-Decrement Operator
	{
		this->workHours = this->workHours - 1.00;

		return *this;
	}

	NumDays operator--(int)  // 6- Overloaded Post-Decrement Operator
	{
		NumDays temp(*this);

		this->workHours = this->workHours - 1.00;

		return temp;
	}

	friend ostream& operator<<(ostream &print, const NumDays &obj)
	{
		print << "-----------------------------------------" << endl;

		print << "Work Hours: " << obj.workHours << endl;
		print << "No. of Days in Work Hours are: " << obj.getDays() << endl;

		print << "-----------------------------------------" << endl;

		return print;
	}

	friend istream& operator>>(istream& in, NumDays &obj)
	{
		cout << "Enter Work Hours: " << endl;
		in >> obj.workHours;
		obj.setWorkHours(obj.workHours);
	}
};

// ADT - TimeOff

class TimeOff
{
private:

	string employeeName;
	int employeeId;
	NumDays maxSickDays;
	NumDays sickTaken;
	NumDays maxVacation;
	NumDays vacTaken;
	NumDays maxUnpaid;
	NumDays unpaidTaken;

public:

	TimeOff(string name, int id, float maxSickDay = 0.00, float sickTake = 0.00, float maxVac = 0.00, float vacTake = 0.00, float maxUnpay = 0.00, float unPaidTake = 0.00) : maxSickDays(maxSickDay), sickTaken(sickTake), maxVacation(maxVac), vacTaken(vacTake), maxUnpaid(maxUnpay), unpaidTaken(unPaidTake)
	{
		this->employeeName = name;
		this->employeeId = id;

		if (maxVacation.getHours() > 240.0) 
		{
			this->maxVacation.setDays(240.0);
		}

	}

	// Getters

	string getEmployeeName() const
	{
		return employeeName;
	}

	int getEmployeeId() const
	{
		return employeeId;
	}

	NumDays getMaxSickDays() const
	{
		return maxSickDays;
	}

	NumDays getSickTaken() const
	{
		return sickTaken;
	}

	NumDays getMaxVacation() const
	{
		return maxVacation;
	}

	NumDays getVacTaken() const
	{
		return vacTaken;
	}

	NumDays getMaxUnpaid() const
	{
		return maxUnpaid;
	}

	NumDays getUnpaidTaken() const
	{
		return unpaidTaken;
	}

	// Setters

	void setEmployeeName(string name)
	{
		this->employeeName = name;
	}

	void setEmployeeId(int id)
	{
		this->employeeId = id;
	}

	void setMaxSickDays(float days)
	{
		float x = 0.00;
		x = days / 30;
		maxSickDays.setWorkHours(x * 8);  
	}

	void setSickTaken(float days)
	{
		sickTaken.setWorkHours(days * 8);
	}

	void setMaxVacation(float days)
	{
		float x = 0.00;
		x = days / 30;
		if (days / 8 > 240.0)
		{
			maxVacation.setWorkHours(240);
		}
		else
		{
			maxVacation.setWorkHours(x * 12);
		}
	}

	void setVacTaken(float days)
	{
		vacTaken.setWorkHours(days * 8+12);;
	}

	void setMaxUnpaid(float days)
	{
		maxUnpaid.setWorkHours(days * 8);
	}

	void setUnpaidTaken(float days)
	{
		unpaidTaken.setWorkHours(days * 8);
	}

	// Overloaded Operator

	friend ostream &operator <<(ostream & print, const TimeOff& obj)
	{
		print << endl << "----------------------------------------------------" << endl;
		print << "Employee's Name: " << obj.getEmployeeName() << endl;
		print << "Employee's ID: " << obj.employeeId << endl;
		print << "Maximum Sick Days: " << obj.maxSickDays.getDays() << endl;
		print << "Sick Days Taken: " << obj.sickTaken.getDays() << endl;
		print << "Maximum Vacation Days: " << obj.maxVacation.getDays() << endl;
		print << "Vacation Days Taken: " << obj.vacTaken.getDays() << endl;
		print << "Maximum Unpaid Days: " << obj.maxUnpaid.getDays() << endl;
		print << "Unpaid Days Taken: " << obj.unpaidTaken.getDays() << endl;
		print << "----------------------------------------------------" << endl;

		return print;
	}

	friend istream &operator >>(istream &in, TimeOff& obj)
	{
		cout << "Enter Employee's Name: ";
		in >> obj.employeeName;
		obj.setEmployeeName(obj.employeeName);

		cout << "Enter Employee's ID: ";
		in >> obj.employeeId;
		obj.setEmployeeId(obj.employeeId);

		cout << "Enter Maximum Sick Days: ";
		float maxSickDays;
		in >> maxSickDays;
		obj.setMaxSickDays(maxSickDays);

		cout << "Enter Sick Days Taken: ";
		float sickTaken;
		in >> sickTaken;
		obj.setSickTaken(sickTaken);

		cout << "Enter Maximum Vacation Days: ";
		float maxVacation;
		in >> maxVacation;
		obj.setMaxVacation(maxVacation);

		cout << "Enter Vacation Days Taken: ";
		float vacTaken;
		in >> vacTaken;
		obj.setVacTaken(vacTaken);

		cout << "Enter Maximum Unpaid Days: ";
		float maxUnpaid;
		in >> maxUnpaid;
		obj.setMaxUnpaid(maxUnpaid);

		cout << "Enter Unpaid Days Taken: ";
		float unpaidTaken;
		in >> unpaidTaken;
		obj.setUnpaidTaken(unpaidTaken);

		return in;
	}
};

int main()
{
	/*NumDays obj1(0);
	obj1.setDays(56.0);
	float x = obj1.getDays();
	cout << "Number of Days in 16 Hours Are: " << x << endl;
	cout << obj1;
	
	TimeOff obj2("ali",2);
	cin >> obj2;
	cout << obj2;*/

	int x = 0, id = 0;
	string name;

	cout << "Enter Name of the Employee: ";
	getline(cin, name);
	
	cout << "Enter ID of the Employee : ";
	cin >> id;

	cout << "How Many Number of Months Employee has Worked for the Company: ";
	cin >> x;

	float y = x * 30;

	TimeOff obj8(name,id);
	obj8.setMaxSickDays(y);
	obj8.setMaxVacation(y);

	cout << obj8;
	return 0;
}
