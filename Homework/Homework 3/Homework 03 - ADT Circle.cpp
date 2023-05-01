// Homework 03
// ADT - Circle

#include <iostream>
#include <math.h>

using namespace std;

class Circle 
{
private:

	int x;
	int y;
	float radius;
	static const double PI;

public:
	//Mutators & Accessors
	//Getters
	int getX()
	{
		return x;
	}

	int getY()
	{
		return y;
	}

	float getRadius()
	{
		return radius;
	}

	//Setters

	void setX(int x)
	{
		if (x >= -50 && x <= 50)
		{
			this->x = x;
		}
		else
		{
			this->x = 0;
		}
	}

	void setY(int y)
	{
		if (y >= -50 && y <= 50)
		{
			this-> y = y;
		}
		else
		{
			this->y = 0;
		}
	}
	
	void setRadius(float r)
	{
		if (r >= 1.00 && r <= 10.00)
		{
			this->radius = r;
		}
		else
		{
			this->radius = 5.00;
		}
	}

	// Construtors

	Circle(int a, int b, float rad)
	{
		setX(a);
		setY(b);
		setRadius(rad);
		cout << endl << "Parameterized Constructor(Taking 3 Parameters)" << endl;
	}

	Circle(int xa, int ya)
	{
		setX(xa);
		setY(ya);
		radius = 5.00;
		cout << endl << "Parameterized Constructor(Taking x and y as Parameters)" << endl;
	}

	Circle(int i, float r)
	{
		setX(i);
		setY(0);
		setRadius(r);
		cout << endl << "Parameterized Constructor(Taking x and radius as Parameters)" << endl;
	}

	Circle()
	{
		x = 0;
		y = 0;
		radius = 5.00;
		cout << endl << "Default Constructor" << endl;
	}

	Circle(const Circle& obj) //Copy Constructor
	{
		x = obj.x;
		y = obj.y;
		radius = obj.radius;
		cout << endl << "Copy Constructor" << endl;
	}

	~Circle() //Destructor
	{
		cout << "Destructor executed..." << endl;
	}

	//Member Functions

	void setCircle(int g, int h, float radii)
	{
		setX(g);
		setY(h);
		setRadius(radii);
	}

	void getCircle()
	{
		cout << "Enter x-coordinate of the Circle: ";
		cin >> x;
		setX(x);

		cout << "Enter y-coordinate of the Circle: ";
		cin >> y;
		setY(y);

		cout << "Enter Radius of the Circle: ";
		cin >> radius;
		setRadius(radius);
	}

	void putCircle()
	{
		cout << "-----------------------------------------" << endl;
		cout << "X-Coordinate: " << x << "\t";
		cout << "Y-Coordinate: " << y << "\t";
		cout << "Radius: " << radius << "\t";
		cout << endl<< "-----------------------------------------" << endl;
		cout << "\n";
	}

	float getArea()
	{
		float area=0.00;
		area = (PI)*(radius*radius);
		return area;
	}

	float getDiameter()
	{
		return (radius * 2);
	}

	float getCircumference()
	{
		float circumference = 0.00;
		circumference = 2 * PI*radius;
		return circumference;
	}

	Circle addCircle(const Circle &object)
	{
		Circle temp;
		temp.x = this->x + object.x;
		temp.y = this->y + object.y;
		temp.radius = this->radius + object.radius;
		return temp;
	}

	bool isEqual(const Circle &object)
	{
		if (this->x == object.x && this->y == object.y && this->radius == object.radius)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int findCircle(const Circle object[], const int size)
	{
		int index=0;
		for (int i = 0; i < size; i++)
		{
			if (this->x == object[i].x && this->y == object[i].y && this->radius == object[i].radius)
			{
				index = 1;
				break;
			}
			else
			{
				index = -1;
			}
		}
		return index;
	}

	void updateObject(Circle object[], const int size)
	{
		for (int i = 0; i < size; i++)
		{
			if (this->x == object[i].x && this->y == object[i].y)
			{
				object[i].radius = this->radius ;
			}
		}
	}
};

const double Circle::PI = 3.14159;

int main()
{
	Circle object1,object5(2,3,4),object6(2,3,4);
	object1.getCircle();
	cout << "Area: " << object1.getArea() << endl;
	cout << "Circumference: " << object1.getCircumference() << endl;
	cout << "Diameter: " << object1.getDiameter() << endl;

	object1.putCircle();

	Circle object2(2,4);
	object2.putCircle();

	Circle object3[3] = { Circle(3,4,8), Circle(3,4,7), Circle(45,4,9) };

	cout << "Equality: " << object5.isEqual(object6) << endl;
	object3->updateObject(object3,3);
	for (int i = 0; i < 3; i++)
	{
		object3[i].putCircle();
	}
	
	Circle ob1(2,3,4),ob2(5,6,7);
	Circle ob3=ob1.addCircle(ob2);
	ob3.putCircle();

	return 0;
}
