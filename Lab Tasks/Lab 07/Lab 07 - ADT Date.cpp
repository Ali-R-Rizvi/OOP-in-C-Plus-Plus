// Lab 07
// ADT - Date

#include <iostream>
#include <math.h>
#include <string>

using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;

public:

	//Setters

	void setDay(int d)
	{
		if (d >= 1 && d <= 31)
		{
			this->day = d;
		}
		else
		{
			this->day = 1;
		}
	}

	void setMonth(int m)
	{
		if (m >= 1 && m <= 12)
		{
			this->month = m;
		}
		else
		{
			this->month = 1;
		}
	}

	void setYear(int y)
	{
		if (y >= 1900)
		{
			this->year = y;
		}
		else
		{
			this->year = 1900;
		}
	}

	//Getters

	int getDay() const
	{
		return day;
	}

	int getMonth() const
	{
		return month;
	}

	int getYear() const
	{
		return year;
	}

	// Constructors

	Date(int day, int month, int year) // Parameterized Constructor Taking 3 Parameters
	{
		setDay(day);
		setMonth(month);
		setYear(year);
	}

	Date(int month, int year) // Parameterized Constructor Taking 1 Parameters
	{
		setDay(1);
		setMonth(month);
		setYear(year);
	}

	Date() // Default Constructor
	{
		setDay(1);
		setMonth(1);
		setYear(1900);
	}

	// Overloaded Operators

	Date operator++() // Pre-Increment Operator
	{
		if ((this->day == 31 && this->month==1) || (this->day == 31 && this->month == 3) || (this->day == 31 && this->month == 5) || (this->day == 31 && this->month == 7) || (this->day == 31 && this->month == 8) || (this->day == 31 && this->month == 10))
		{
			this->day = 1;
			this->month++;
		}

		else if ((this->day == 30 && this->month == 4) || (this->day == 30 && this->month == 6) || (this->day == 30 && this->month == 9) || (this->day == 30 && this->month == 11))
		{
			this->day = 1;
			this->month++;
		}

		else if ((this->day == 28 && this->month == 2) && (this->day == 29 && this->month == 2) )
		{
			this->day = 1;
			this->month++;
		}

		else if (this->day == 31 && this->month == 12)
		{
			this->day = 1;
			this->month = 1;
			this->year++;
		}

		else
		{
			this->day++;
		}

		return *this;
	}

	Date operator++(int) // Post-Increment Operator
	{
		Date temp(*this);

		if ((this->day == 31 && this->month == 1) || (this->day == 31 && this->month == 3) || (this->day == 31 && this->month == 5) || (this->day == 31 && this->month == 7) || (this->day == 31 && this->month == 8) || (this->day == 31 && this->month == 10))
		{
			this->day = 1;
			this->month++;
		}

		else if ((this->day == 30 && this->month == 4) || (this->day == 30 && this->month == 6) || (this->day == 30 && this->month == 9) || (this->day == 30 && this->month == 11))
		{
			this->day = 1;
			this->month++;
		}

		else if ((this->day == 28 && this->month == 2) && (this->day == 29 && this->month == 2))
		{
			this->day = 1;
			this->month++;
		}

		else if (this->day == 31 && this->month == 12)
		{
			this->day = 1;
			this->month = 1;
			this->year++;
		}

		else
		{
			this->day++;
		}

		return temp;
	}

	Date operator--() // Pre-Decrement Operator
	{
		if (this->day == 1 && this->month == 1) // For January 
		{
			this->day = 31;
			this->month = 12;
			this->year--;
		}

		else if (this->day == 1 && this->month == 2) // For February 
		{
			this->day = 31;
			this->month = 1;
		}

		else if (this->day == 1 && this->month == 3) // For March
		{
			this->day = 28;
			this->month = 2;
		}

		else if (this->day == 1 && this->month == 4) // For April
		{
			this->day = 31;
			this->month = 3;
		}

		else if (this->day == 1 && this->month == 5) // For May
		{
			this->day = 30;
			this->month = 4;
		}

		else if (this->day == 1 && this->month == 6) // For June
		{
			this->day = 31;
			this->month = 5;
		}

		else if (this->day == 1 && this->month == 7) // For July
		{
			this->day = 30;
			this->month = 6;
		}
		
		else if (this->day == 1 && this->month == 8) // For August
		{
			this->day = 31;
			this->month = 7;
		}

		else if (this->day == 1 && this->month == 9) // For September
		{
			this->day = 31;
			this->month = 8;
		}

		else if (this->day == 1 && this->month == 10) // For October
		{
			this->day = 30;
			this->month = 9;
		}

		else if (this->day == 1 && this->month == 11) // For November
		{
			this->day = 31;
			this->month = 10;
		}

		else if (this->day == 1 && this->month == 12) // For December
		{
			this->day = 30;
			this->month = 11;
		}
		
		else
		{
			this->day--;
		}

		return *this;
	}

	Date operator--(int) // Post-Decrement Operator
	{
		Date temp(*this);

		if (this->day == 1 && this->month == 1) // For January 
		{
			this->day = 31;
			this->month = 12;
			this->year--;
		}

		else if (this->day == 1 && this->month == 2) // For February 
		{
			this->day = 31;
			this->month = 1;
		}

		else if (this->day == 1 && this->month == 3) // For March
		{
			this->day = 28;
			this->month = 2;
		}

		else if (this->day == 1 && this->month == 4) // For April
		{
			this->day = 31;
			this->month = 3;
		}

		else if (this->day == 1 && this->month == 5) // For May
		{
			this->day = 30;
			this->month = 4;
		}

		else if (this->day == 1 && this->month == 6) // For June
		{
			this->day = 31;
			this->month = 5;
		}

		else if (this->day == 1 && this->month == 7) // For July
		{
			this->day = 30;
			this->month = 6;
		}

		else if (this->day == 1 && this->month == 8) // For August
		{
			this->day = 31;
			this->month = 7;
		}

		else if (this->day == 1 && this->month == 9) // For September
		{
			this->day = 31;
			this->month = 8;
		}

		else if (this->day == 1 && this->month == 10) // For October
		{
			this->day = 30;
			this->month = 9;
		}

		else if (this->day == 1 && this->month == 11) // For November
		{
			this->day = 31;
			this->month = 10;
		}

		else if (this->day == 1 && this->month == 12) // For December
		{
			this->day = 30;
			this->month = 11;
		}

		else
		{
			this->day--;
		}

		return temp;
	}

	int operator-(const Date& obj) // Overloaded - Operator
	{
		int d1 = 0, d2 = 0;

		d1 = this->day + this->month * 30 + this->year * 365;
		d2 = obj.day + obj.month * 30 + obj.year * 365;

		return d1 - d2;
	}

	bool operator+() // Unary + Operator
	{
		if ((this->day == 5 && this->month == 2) || (this->day == 23 && this->month == 3) || (this->day == 1 && this->month == 5) || (this->day == 14 && this->month == 8) || (this->day == 25 && this->month == 12))
		{
			return true;
		}

		else
		{
			return false;
		}
	}
	friend ostream& operator<<(ostream& output, const Date &object);
	friend istream& operator>>(istream& input, Date &object);
};

ostream& operator<<(ostream& output, const Date &object)
{
	if (object.month == 1)
	{
		output <<"January " <<object.day << ", " << object.year;
	}

	if (object.month == 2)
	{
		output << "February " << object.day << ", " << object.year;
	}

	if (object.month == 3)
	{
		output << "March " << object.day << ", " << object.year;
	}
	
	if (object.month == 4)
	{
		output << "April " << object.day << ", " << object.year;
	}

	if (object.month == 5)
	{
		output << "May " << object.day << ", " << object.year;
	}

	if (object.month == 6)
	{
		output << "June " << object.day << ", " << object.year;
	}

	if (object.month == 7)
	{
		output << "July " << object.day << ", " << object.year;
	}

	if (object.month == 8)
	{
		output << "August " << object.day << ", " << object.year;
	}

	if (object.month == 9)
	{
		output << "September " << object.day << ", " << object.year;
	}

	if (object.month == 10)
	{
		output << "October " << object.day << ", " << object.year;
	}

	if (object.month == 11)
	{
		output << "November " << object.day << ", " << object.year;
	}

	if (object.month == 12)
	{
		output << "December " << object.day << ", " << object.year;
	}

	return output;
}

istream& operator>>(istream& input, Date &object)
{
	cout << "Enter Day: ";
	input >> object.day;
	object.setDay(object.day);

	cout << "Enter Month: ";
	input >> object.month;
	object.setMonth(object.month);

	cout << "Enter Year: ";
	input >> object.year;
	object.setYear(object.year);

	return input;
}

int main()
{
	Date obj1, obj2(1, 1, 2000), obj3, obj4(1, 3, 2004), obj5;
	
	//cin >> obj1;
	//cout << obj1 << endl;

	cout << "No. of Days: " << obj4 - obj2 << endl;
	obj3 = --obj2;
	cout << obj2 << endl;
	cout << obj3 << endl;

	obj5 = obj4--;
	cout << obj4 << endl;
	cout << obj5 << endl;

	return 0;
}
