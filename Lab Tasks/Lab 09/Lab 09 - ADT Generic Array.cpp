// Lab 09
// ADT - Generic Array

#include <iostream>

using namespace std;

template <typename T>
class Array
{
private:

	T* data;         // Data Members
	int size;

public:

	Array()  // 1- Default Constructor
	{
		this->size = 5;
		data = new T[size];

		for (int i = 0; i < this->size; i++)
		{
			data[i] = 0;
		}
	}

	Array(int s)  // 2- Parameterized Constructor
	{
		this->size = s;
		data = new T[s];

		for (int i = 0; i < s; i++)
		{
			data[i] = 0;
		}
	}

	Array(const Array& obj) // 3- Copy Constructor
	{
		this->size = obj.size;
		data = new T[this->size];

		for (int i = 0; i < this->size; i++)
		{
			data[i] = obj.data[i];
		}

	}

	~Array() // 4- Destructor
	{
		delete[]data;
	}

	// Non-Static Member Functions and Operators

	T getSize() const // 1- Get Size
	{
		return size;
	}

	void setElement(int i, T k) // 2- Inserts k Element at i Index
	{
		if (i >= 0 || i < this->size)
		{
			data[i] = k;
		}
		else
		{
			cout << "ERROR!!! Your Given Index is Out of Range" << endl;
		}
	}

	int countElement(T key) const // 3- Count Elements 
	{
		int count = 0;

		for (int i = 0; i < this->size; i++)
		{
			if (data[i] == key)
			{
				count++;
			}
		}

		return count;
	}

	Array operator=(const Array& obj) // 4- Overloaded Assignment Operator
	{
		if (this != &obj)
		{
			if (this->size != obj.size) // For Unequal Size
			{
				delete[] data;
				size = obj.size;
				data = new T[size];

				for (int i = 0; i < size; i++)
				{
					this->data[i] = obj.data[i];
				}
			}

			else if (this->size == obj.size) // For Equal Size
			{
				for (int i = 0; i < size; i++)
				{
					this->data[i] = obj.data[i];
				}
			}
		}

		return *this;
	}

	Array getSubArray(int start_index, int end_index) const // 5- Create New Array
	{
		Array temp(0);
		int j = 0;

		if (start_index < 0 || end_index >= size || start_index > end_index)
		{
			cout << "ERROR!!! Your Given Sub-Array Parameters are INVALID!!!!";

			temp.data = NULL;
			return temp;
		}

		else
		{
			temp.size = end_index - start_index + 1;
			temp.data = new T[temp.size];

			for (int i = start_index; i <= end_index; i++)
			{
				temp.data[j] = data[i];
				j++;
			}
		}

		return temp;
	}

	Array operator+(const Array& obj) const // 6- Overloaded + Operator
	{
		Array temp;
		int count = 0, j = 0;
		int size = 0;

		size = this->size + obj.size;
		temp.size = this->size + obj.size;

		temp.data = new T[size];

		for (int i = 0; i < this->size; i++)
		{
			temp.data[i] = this->data[i];
			count++;
		}

		for (int i = count; i < size; i++)
		{
			temp.data[i] = obj.data[j];
			j++;
		}

		return temp;
	}

	friend ostream& operator<<(ostream& output, const Array& obj) // 7- Stream Insertion Operator
	{
		for (int i = 0; i < obj.size; i++)
		{
			output << obj.data[i] << " ";
		}

		return output;
	}

	friend istream& operator>>(istream& input, Array& obj) // 8- Stream Extraction Operator
	{
		for (int i = 0; i < obj.size; i++)
		{
			input >> obj.data[i];
		}

		return input;
	}

	bool operator==(const Array& obj) const // 9- Overloaded == Operator
	{
		if (this->size != obj.size)
		{
			return false;
		}
		else
		{
			for (int i = 0; i < this->size; i++)
			{
				if (this->data[i] != obj.data[i])
				{
					return false;
				}
			}
		}

		return true;
	}

	T& operator[](int index) // 10- Subscript Operator for Non-Constant Objects
	{
		if (index >= 0 && index <= size)
		{
			return data[index];
		}
		else
		{
			cout << "ERROR!!! Index Out of Bounds." << endl;
			static T x = -1;
			return x;
		}
	}

	T operator[](int index) const // 11- Subscript Operator for Constant Objects
	{
		if (index >= 0 && index <= size)
		{
			return data[index];
		}
		else
		{
			cout << "ERROR!!! Index Out of Bounds." << endl;
			T x = -1;
			return x;
		}
	}

};

int main()
{
	Array<int> obj1(5);

	cout << "Enter 5 Numbers: " << endl;
	cin >> obj1;
	cout << "Output is: " << obj1;

	cout << "\n\n1- Size of Array is: " << obj1.getSize();

	obj1.setElement(4, 7);
	cout << "\n\n2- New Output After Inserting 7 at 4th Index is: " << obj1;

	cout << "\n\n3- Count of 7 in this Array is: " << obj1.countElement(7);

	Array<int>obj2(5);
	obj2 = obj1;
	cout << "\n\n4- Output of Copied Array is: " << obj2;

	Array<int>obj3 = obj2.getSubArray(2, 4);
	cout << "\n\n5- Using getSubArray Function: " << obj3;

	cout << "\n\n6- Getting Value at 1st Index using [] Operator: " << obj3[1];

	Array<int>obj4(7);

	cout << "\n\nEnter 7 Numbers for Other Array: " << endl;
	cin >> obj4;
	cout << "7 Numbers Are: \n" << obj4;

	Array<int>obj5;
	obj5 = obj1 + obj4;

	cout << "\n\n7- Size of Combined Array is: " << obj5.getSize();
	cout << "\n\n8- Combining the Arrays Using + Operator: " << obj5;

	return 0;
}
