// Lab 10
// Carpet Calculator

#include "iostream"

using namespace std;

class FeetInches
{
private:
	int feet;			// To hold a number of feet
	int inches;			// To hold a number of inches

	void simplify()
	{
		if (inches >= 12)
		{
			feet += (inches / 12);
			inches = inches % 12;
		}
		else if (inches < 0)
		{
			feet -= ((abs(inches) / 12) + 1);
			inches = 12 - (abs(inches) % 12);
		}
	}

public:
	// Constructor
	FeetInches(int f = 0, int i = 0)
	{
		feet = f;
		inches = i;
		simplify();
	}

	FeetInches(const FeetInches & right)
	{
		feet = right.feet;
		inches = right.inches;
		simplify();
	}

	// Mutator functions
	void setFeet(int f)
	{
		feet = f;
	}

	void setInches(int i)
	{
		inches = i;
		simplify();
	}

	// Accessor functions
	int getFeet() const
	{
		return feet;
	}

	int getInches() const
	{
		return inches;
	}

	FeetInches operator + (const FeetInches & right)
	{
		FeetInches temp;

		temp.inches = inches + right.inches;
		temp.feet = feet + right.feet;
		temp.simplify();

		return temp;
	}

	FeetInches operator - (const FeetInches & right)
	{
		FeetInches temp;

		temp.inches = inches - right.inches;
		temp.feet = feet - right.feet;
		temp.simplify();

		return temp;
	}

	FeetInches operator * (const FeetInches & right)
	{
		FeetInches temp;

		temp.inches = inches * right.inches;
		temp.feet = feet * right.feet;
		temp.simplify();

		return temp;
	}

	FeetInches operator ++ ()
	{
		++inches;
		simplify();

		return *this;
	}

	FeetInches operator ++ (int)
	{
		FeetInches temp(feet, inches);

		inches++;
		simplify();

		return temp;
	}

	FeetInches operator -- ()
	{
		--inches;
		simplify();

		return *this;
	}

	FeetInches operator -- (int)
	{
		FeetInches temp(feet, inches);

		inches--;
		simplify();

		return temp;
	}

	bool operator > (const FeetInches & right)
	{
		bool status;

		if (feet > right.feet)
			status = true;
		else if (feet == right.feet && inches > right.inches)
			status = true;
		else
			status = false;

		return status;
	}

	bool operator < (const FeetInches & right)
	{
		return !(*this > right);
	}

	bool operator >= (const FeetInches & right)
	{
		bool status;

		if (feet >= right.feet)
			status = true;
		else if (feet == right.feet && inches >= right.inches)
			status = true;
		else
			status = false;

		return status;
	}

	bool operator <= (const FeetInches & right)
	{
		return !(*this >= right);
	}

	bool operator == (const FeetInches & right)
	{
		bool status;

		if (feet == right.feet && inches == right.inches)
			status = true;
		else
			status = false;

		return status;
	}

	bool operator != (const FeetInches & right)
	{
		return !(*this == right);
	}

	friend ostream& operator << (ostream&, const FeetInches&);
	friend istream& operator >> (istream&, FeetInches&);
};

ostream& operator << (ostream & out, const FeetInches & obj)
{
	out << "Feet = " << obj.feet << "\tInches = " << obj.inches << endl;

	return out;
}

istream& operator >> (istream & in, FeetInches & obj)
{
	cout << "Enter Feet:\t";
	in >> obj.feet;

	cout << "Enter Inches:\t";
	in >> obj.inches;

	return in;
}

class RoomDimension
{
private:
	FeetInches length;
	FeetInches width;

public:

	// Getters

	FeetInches getLength()
	{
		return length;
	}

	FeetInches getWidth()
	{
		return width;
	}

	// Setters

	void setLength(FeetInches l)
	{
		this->length = l;
	}
	
	void setWidth(FeetInches w)
	{
		this->width = w;
	}


	RoomDimension(FeetInches l1,FeetInches w1) : length(l1) ,  width(w1) // Constructor
	{
		
	}

	FeetInches totalArea()
	{
		FeetInches a;
		/*a.getFeet = length.getFeet()* width.getFeet();
		a.getInches = length.getInches() * width.getInches();*/

		a = length * width;
		return a;
	}

	void display()
	{
		cout << "---------------------------------------------------------" << endl;
		cout << "Length: " << length << endl;
		cout << "Width: " << width << endl;
		cout << "Total Area: " << totalArea() << endl;
		cout << "---------------------------------------------------------" << endl;
	}
};

class RoomCarpet
{
private:
	RoomDimension roomSize;
	float costPerSquareFoot;

public:

	// Getters

	RoomDimension getRoomSize()
	{
		return roomSize;
	}

	float getCostPerSquareFoot()
	{
		return costPerSquareFoot;
	}

	// Setters

	void setRoomSize(RoomDimension r)
	{
		this->roomSize = r;
	}

	void setCostPerSquareFoot(float c)
	{
		this->costPerSquareFoot = c;
	}

	RoomCarpet(RoomDimension r, float c):roomSize(r)
	{
		this->costPerSquareFoot = c;
	}

	float totalCarpetCost()
	{
		float c = 0.00;
		c = (costPerSquareFoot * roomSize.getLength().getFeet() * roomSize.getWidth().getFeet());;
		return  c;
	}

	void display()
	{
		cout << "Room Size: " << endl;
		roomSize.display();
		cout << "Room Area: " << roomSize.totalArea() << endl;
		cout << "Cost Per Square Foot: " << costPerSquareFoot << endl;
		cout << "Total Cost of Carpet: " << totalCarpetCost() << endl;
	}
};

int main()
{
	FeetInches o1(1, 2), o2(3, 5);

	RoomDimension obj1(o1,o2);


	RoomCarpet obje1(obj1,83.5);
	obje1.display();
	

	return 0;
}
