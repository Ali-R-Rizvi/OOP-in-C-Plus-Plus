// Homework 02
// ADT - Cuboids

#include "iostream"
#include<string>
#include<math.h>

using namespace std;

class Cuboids
{
private:
	float height;
	float width;
	float depth;

public:
	//Mutators &Accessors
	//Getters
	float getHeight()
	{
		return height;
	}

	float getWidth()
	{
		return width;
	}

	float getDepth()
	{
		return depth;
	}

	//Setters

	void setHeight(float h)
	{
		if (h >= 0 && h <= 35.00)
		{
			height = h;
		}
		else
		{
			height = 1;
		}
	}
	void setWidth(float w)
	{
		if (w >= 0 && w <= 35.00)
		{
			width = w;
		}
		else
		{
			width = 1;
		}
	}
	void setDepth(float d)
	{
		if (d >= 0 && d <= 35.00)
		{
			depth = d;
		}
		else
		{
			depth = 1;
		}
	}
	//Constructors
	Cuboids(float h, float w, float d) //Taking 3 Arguments
	{
		setHeight(h);
		setWidth(w);
		setDepth(d);
		cout << endl << "Parameterized Constructor(Taking 3 Parameters)" << endl;
	}

	Cuboids(float hei, float wid) //Taking 2 Parameters
	{
		setHeight(hei);
		setWidth(wid);
		depth = 0;
		cout << endl << "Parameterized Constructor(Taking 2 Parameters)" << endl;
	}


	Cuboids() //Default Constructor
	{
		height = 0;
		width = 0;
		depth = 0;
		cout << endl << "Default Constructor" << endl;
	}

	Cuboids(const Cuboids& obj) //Copy Constructor
	{
		height = obj.height;
		width = obj.width;
		depth = obj.depth;
		cout << endl << "Copy Constructor" << endl;
	}

	~Cuboids() //Destructor
	{
		cout << "Destructor executed..." << endl;
	}



	//Member Functions

	void setCuboids(float height, float width, float depth)
	{
		setHeight(height);
		setWidth(width);
		setDepth(depth);
	}

	void getCuboids()
	{

		cout << "Enter Height of the Cuboid: ";
		cin >> height;
		setHeight(height);

		cout << "Enter Width of the Cuboid: ";
		cin >> width;
		setWidth(width);

		cout << "Enter Depth of the Cuboid: ";
		cin >> depth;
		setDepth(depth);
	}

	void putCuboids()
	{
		cout << height << "\t";
		cout << width << "\t";
		cout << depth << "\t";
		cout << "\n";
	}

	float getSurfaceArea(float height, float width, float depth)
	{
		float x = 0.0;
		x = (2 * (height*width)) + (2 * (height*depth)) + (2 * (width*depth));
		return x;
	}

	float getVolume(float height, float width, float depth)
	{
		float v = 0.0;
		v = height * width*depth;
		return v;
	}
	float getSpaceDiagonal(float height, float width, float depth)
	{
		float s = 0.0, space = 0.0;
		s = (height*height) + (width*width) + (depth*depth);
		space = sqrt(s);
		return space;
	}

	void putCuboidsInfo()
	{
		cout << "Height of the Cuboid is: " << height << endl;
		cout << "Width of the Cuboid is: " << width << endl;
		cout << "Depth of the Cuboid is: " << depth << endl;
		float x = 0.0, y = 0.0, z = 0.0;
		x = getSurfaceArea(height, width, depth);
		y = getVolume(height, width, depth);
		z = getSpaceDiagonal(height, width, depth);
		cout << "Surface Area of the Cuboid is: " << x << endl;
		cout << "Volume of the Cuboid is: " << y << endl;
		cout << "Space Diagonal of the Cuboid is: " << z << endl;
		cout << "--------------------------------------------" << endl;
	}
};

int main()
{
	Cuboids obj(3.3, 4.1, 2.0), obj1(23, 5.5), obj2, obj3, obj4;
	obj.putCuboidsInfo();// 3 Parameters

	obj1.putCuboidsInfo();// 2 Parameters

	obj2.putCuboidsInfo();// Using Default Constructor 

	obj3.getCuboids();  //Taking Input from User
	obj3.putCuboidsInfo();


	obj4 = obj3;    //Copy Constructor
	obj4.putCuboidsInfo();

	return 0;
}
