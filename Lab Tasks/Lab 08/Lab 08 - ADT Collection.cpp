// Lab 08
// ADT - Collection

#include <iostream>

using namespace std;

class Collection
{
private:
	int *data;
	int size;

public:
	void setData(int d)
	{
		if (d < 0)
		{
			*data = d;
		}
		else
		{
			data = 0; // Default Value for data
		}
	}

	void setSize(int s)
	{
		if (s >= 0)
		{
			size = s;
		}
		else
		{
			size = 0; // No Default Value Given for Size so it can be 0
		}
	}
	Collection(int size) // Parameterized Constructor Taking 1 Parameters
	{
		this->size = size;
		setSize(size);
		data = new int[size];

		for (int i = 0; i < this->size; i++)
		{
			data[i] = 0;
		}

	}

	Collection(int *array, int size) // Parameterized Constructor Taking 2 Parameters
	{
		this->size = size;
		setSize(size);
		data = new int[size];

		for (int i = 0; i < this->size; i++)
		{
			if (array[i] <= 0)
			{
				data[i] = array[i];
			}
			else
			{
				data[i] = 0;
			}
		}

	}

	Collection(const Collection& obj) // Deep Copy Constructor
	{
		this->size = obj.size;
		setSize(obj.size);
		data = new int[this->size];

		for (int i = 0; i < this->size; i++)
		{
			data[i] = obj.data[i];
		}

	}

	~Collection() // Destructor
	{
		delete[]data;
	}

	// Member Functions

	int getSize() const // 1- Get Size
	{
		return size;
	}

	void setElement(int i, int k) // 2- Set k Element at i Index
	{
		if (i >= 0 || i < size) 
		{
			data[i] = k;
		}
		else
		{
			cout << "ERROR!!! Your Given Index is Out of Range" << endl;
		}
	}

	int countElement(int key) const // 3- Count Elements 
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

	Collection operator=(const Collection& obj) // 4- Overloaded Assignment Operator
	{
		if (this != &obj)
		{
			if (this->size != obj.size) // For Unequal Size
			{
				delete[] data;
				size = obj.size;
				data = new int[size];

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

	Collection getSubCollection(int start_index, int end_index) const // 5- Create New Collection
	{
		Collection temp(0);
		int j = 0;

		if (start_index < 0 || end_index >= size || start_index > end_index) 
		{
			cout << "ERROR!!! Your Given Sub-Collection Parameters are INVALID!!!!";
		}

		else 
		{
			temp.size = end_index - start_index + 1;
			temp.data = new int[temp.size];

			for (int i = start_index; i <= end_index; i++) 
			{
				temp.data[j] = data[i];
				j++;
			}
		}

		return temp;
	}

	Collection operator+(const Collection& obj) const // 8- Overloaded + Operator
	{
		Collection temp(0);

		if (this->size != obj.size) 
		{
			cout << "ERROR!!! Both Collections have Different Sizes of " << this->size << " and " << obj.size << " respectively" << endl;
			temp.data = NULL;
			temp.size = 0;
			return temp;
		}

		else 
		{
			temp.size = size;
			temp.data = new int[size];
			for (int i = 0; i < size; i++) 
			{
				temp.data[i] = this->data[i] + obj.data[i];
			}
			return temp;
		}	
	}

	int& operator[](int index) // 9- Subscript Operator for Non-Constant Objects
	{
		if (index >= 0 && index <= size)
		{
			return data[index];
		}
		else
		{
			cout << "ERROR!!! Index Out of Bounds." << endl;
			int x = 99;
			return x;
		}
	}

	int operator[](int index) const // 10- Subscript Operator for Constant Objects
	{
		if (index >= 0 && index <= size)
		{
			return data[index];
		}
		else
		{
			cout << "ERROR!!! Index Out of Bounds." << endl;
			int x = 99;
			return x;
		}
	}

	bool operator-() const // 11- Unary - Operator
	{
		for (int i = 0; i < size; i++)
		{
			if (data[i] >= 0)
			{
				return false;
			}
		}

		return true;
	}

	friend ostream& operator<<(ostream& output, const Collection& obj);
	friend istream& operator>>(istream& input, Collection& obj);
};

ostream& operator<<(ostream& output, const Collection& obj) // 6- Stream Insertion Operator
{
	for (int i = 0; i < obj.size; i++) 
	{
		output << "Element " << i + 1 << ": " << obj.data[i] << endl;
	}
	
	return output;
}

istream& operator>>(istream& input, Collection& obj) // 7- Stream Extraction Operator
{
	int a = 0;

	for (int i = 0; i < obj.size; i++) 
	{
		cout << "Enter Array Element Number " << i + 1 << ": ";
		input >> a;
		if (a < 0)
		{
			obj.data[i] = a;
		}
		else
		{
			obj.data[i] = 0;
		}
	}
	
	return input;
}

int main()
{
	int arr[5] = { -1,-2,-3,-4,5 };

	Collection obj1(arr, 5), obj2(5), obj3(7), obj4(arr, 5);

	obj2 = obj1.getSubCollection(2, 4);

	cout << obj2;
	
	cout << obj1 + obj2;
	cout << obj1 + obj4;

	cout << "Fourth Element of Object 1 is: " << obj1.operator[](4) << endl;
	
	Collection o(5);
	cin >> o;
	cout << o;

	return 0;
}
