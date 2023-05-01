// Homework 04
// ADT - Rational Number

#include <iostream>
#include <math.h>
#include <string>

using namespace std;

class Rational_Numbers
{
private:
	int numerator;
	int denominator;

public:

	//Setters
	void setNumerator(int numerator)
	{
		this->numerator = numerator;
	}

	void setDenominator(int denominator)
	{
		if (denominator != 0 && denominator > 0)
		{
			this->denominator = denominator;
		}
		else
		{
			this->denominator = 1;
		}
	}

	//Getters

	int getNumerator()
	{
		return numerator;
	}

	int getDenominator()
	{
		return denominator;
	}

	//Constructors

	Rational_Numbers(int numerator, int denominator) //Taking 2 Parameters
	{
		setNumerator(numerator);
		setDenominator(denominator);
	}

	Rational_Numbers(int numerator) //Taking 1 Parameter
	{
		setNumerator(numerator);
		setDenominator(1);
	}


	// Overloaded + Binary Operator
	Rational_Numbers operator+(const Rational_Numbers& object) const
	{
		Rational_Numbers temp(0,0);
		temp.numerator = (numerator*object.denominator) + (denominator* object.numerator);
		temp.denominator = (denominator * object.denominator);
		return temp;
	}

	// Overloaded - Binary Operator
	Rational_Numbers operator-(const Rational_Numbers& object) const
	{
		Rational_Numbers temp(0,0);
		temp.numerator = (numerator*object.denominator) - (denominator* object.numerator);
		temp.denominator = (denominator * object.denominator);
		return temp;
	}

	// Overloaded * Binary Operator
	Rational_Numbers operator*(const Rational_Numbers& object) const
	{
		Rational_Numbers temp(0,0);
		temp.numerator = (numerator*object.numerator);
		temp.denominator = (denominator * object.denominator);
		return temp;
	}

	// Overloaded / Binary Operator
	Rational_Numbers operator/(const Rational_Numbers& object) const
	{
		Rational_Numbers temp(0,0);
		temp.numerator = (numerator*object.denominator);
		temp.denominator = (object.numerator * denominator);

		return temp;
	}

	// Overloaded < Binary Operator
	bool operator<(const Rational_Numbers& object) const
	{
		if ((numerator*object.denominator) < (object.numerator * denominator))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// Overloaded == Binary Operator
	bool operator==(const Rational_Numbers& object) const
	{
		return ((numerator*object.denominator) == (object.numerator * denominator));
	}

	//Overloaded - Operator (unary)
	Rational_Numbers operator- () 
	{
		if (numerator > 0)
		{
			return Rational_Numbers(-numerator, denominator);
		}
		else
		{
			return Rational_Numbers(numerator, denominator);
		}
	}

	//Overloaded != Operator (unary)
	bool operator! () const
	{
		if (this->numerator < 0)
		{
			return true;
		}

		else
		{
			return false;
		}
	}

	friend ostream& operator<<(ostream& output,const Rational_Numbers &object);
	friend istream& operator>>(istream& input, Rational_Numbers &object);
};

ostream& operator<<(ostream& output,const Rational_Numbers &object)
{
	output << object.numerator << "/" << object.denominator;

	return output;
}

istream& operator>>(istream& input, Rational_Numbers &object)
{
	cout << "Enter Numerator: ";
	input >> object.numerator;
	object.setNumerator(object.numerator);

	cout << "Enter Denominator: ";
	input >> object.denominator;
	object.setDenominator(object.denominator);

	return input;
}

int main()
{
	Rational_Numbers object1(0, 0), object2(0, 0), add(0, 0), sub(0, 0), mul(0, 0), div(0, 0);
	cin >> object1;
	cout << "The First Rational Number is: " << object1 << endl;

	//Unary ! Use
	if (!object1)
	{
		cout << "The First Rational Number is NEGATIVE!!!" << endl;
	}
	else
	{
		cout << "The First Rational Number is POSITIVE!!!" << endl;
	}

	cin >> object2;
	cout << "The Second Rational Number is: " << object2 << endl;
	
	//Unary ! Use
	if (!object2)
	{
		cout << "The Second Rational Number is NEGATIVE!!!" << endl;
	}
	else
	{
		cout << "The Second Rational Number is POSITIVE!!!" << endl;
	}



	if (object1 == object2)  //Equality Comparison
	{
		cout << "Entered Rational Numbers are EQUAL!!!" << endl;
	}
	else
	{
		cout << "Entered Rational Numbers are NOT EQUAL!!!" << endl;
		if (object1 < object2)  //Less Than Comparison
		{
			cout << object1 << " is LESS than " << object2 << endl;
		}
		else
		{
			cout << object1 << " is GREATER than " << object2 << endl;
		}
	}

	add = object1 + object2;
	cout << "1- Adding First and Second Rational Numbers: " << add << endl;

	sub = object1 - object2;
	cout << "2- Subtracting First and Second Rational Numbers: " << sub << endl;

	mul = object1 * object2;
	cout << "3- Multiplying First and Second Rational Numbers: " << mul << endl;

	div = object1 / object2;
	cout << "4- Dividing First and Second Rational Numbers: " << div << endl;
	
	cout << endl << "First Rational Number in Negative Form is: " << -object1 << endl;
	cout << "Second Rational Number in Negative Form is: " << -object2 << endl << endl;
	
	
	return 0;
}
