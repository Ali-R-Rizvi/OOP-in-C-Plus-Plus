// Homework 05
// ADT - IntegerSet

#include <iostream>

using namespace std;

class IntegerSet
{
private:

	int *set;
	const int maximumSize;

public:

	IntegerSet(int size) : maximumSize(size)  // Parameterized Constructor Taking 1 Input
	{
		set = new int[size];

		for (int i = 0; i < this->maximumSize; i++)
		{
			set[i] = 0;
		}
	}

	IntegerSet(const IntegerSet& obj) : maximumSize(obj.maximumSize) // Deep Copy Constructor
	{
		set = new int[maximumSize];

		for (int i = 0; i < maximumSize; i++)
		{
			this->set[i] = obj.set[i];
		}
	}

	~IntegerSet() // Destructor
	{
		delete[]set;
	}

	// Overloaded Operators

	friend ostream& operator<<(ostream& output, const IntegerSet& obj) // 1- Stream Insertion Operator
	{
		int count = 0;

		output << "___________________________________________________________________" << endl;

		for (int i = 0; i < obj.maximumSize; i++)
		{
			if (obj.set[i] == 1)
			{
				output << i << "\t";
				count++;
			}
		}

		if (count == 0)
		{
			output << "-----------";
		}
		output << endl << "___________________________________________________________________" << endl;

		return output;
	}

	IntegerSet operator=(const IntegerSet& obj) // 2- Overloaded Assignment Operator
	{
		if (this != &obj) // Self-Assignment Check
		{
			if (this->maximumSize == obj.maximumSize) // For Equal Size
			{
				for (int i = 0; i < maximumSize; i++)
				{
					this->set[i] = obj.set[i];
				}
			}
			else
			{
				cout << "ERROR!!! Both Objects have Different Sizes of " << this->maximumSize << " and " << obj.maximumSize << " respectively" << endl;
			}
		}

		return *this;
	}

	bool operator==(const IntegerSet& obj) // 3- Overloaded == Operator
	{
		if (this->maximumSize != obj.maximumSize)
		{
			return false;
		}
		else
		{
			for (int i = 0; i < this->maximumSize; i++)
			{
				if (this->set[i] != obj.set[i])
				{
					return false;
				}
			}
		}

		return true;
	}

	IntegerSet operator!() const // 4- Overloaded ! Operator
	{
		IntegerSet temp(this->maximumSize);

		for (int i = 0; i < this->maximumSize; i++)
		{
			if (this->set[i] == 0)
			{
				temp.set[i] = 1;
			}
			else
			{
				temp.set[i] = 0;
			}
		}

		return temp;
	}

	// Member Functions

	void insertElement(int k) // 1- Inserts Element at k Index
	{
		if (k >= 0 && k < maximumSize) 
		{
			set[k] = 1;
		}
		else
		{
			cout << "ERROR!!! The Index Given for Inserting Element is Out of Range" << endl;
		}
	}

	void deleteElement(int k) // 2- Deletes Element at k Index
	{
		if (k >= 0 && k < maximumSize)
		{
			set[k] = 0;
		}
		else
		{
			cout << "ERROR!!! The Index Given for Deleting Element is Out of Range" << endl;
		}
	}
	
	IntegerSet unionOfSets(const IntegerSet& obj) // 3- Takes Union of Sets
	{
		IntegerSet temp(maximumSize);
		
		if (this->maximumSize == obj.maximumSize)
		{
			for (int i = 0; i < maximumSize; i++)
			{
				if (this->set[i] == 1 || obj.set[i] == 1)
				{
					temp.set[i] = 1;
				}

				else
				{
					temp.set[i] = 0;
				}
			}
		}
		else
		{
			cout << "ERROR!!! Both Sets Have Different Sizes" << endl;
		}

		return temp;
	}

	IntegerSet intersectionOfSets(const IntegerSet& obj) // 4- Takes Intersection of Sets
	{
		IntegerSet temp(maximumSize);

		if (this->maximumSize == obj.maximumSize)
		{
			for (int i = 0; i < maximumSize; i++)
			{
				if (this->set[i] == 1 && obj.set[i] == 1)
				{
					temp.set[i] = 1;
				}

				else
				{
					temp.set[i] = 0;
				}
			}
		}
		else
		{
			cout << "ERROR!!! Both Sets Have Different Sizes" << endl;
		}

		return temp;
	}

	bool findElement(int key) // 5- Finds the Element
	{
		if (key >= 0 && key < maximumSize) 
		{
			if (set[key] == 1)
			{
				return true;
			}
		}

		return false;
	}

};

int main()
{
	IntegerSet set1(10);
	set1.insertElement(0);
	set1.insertElement(1);
	set1.insertElement(3);
	set1.insertElement(4);
	set1.insertElement(7);
	set1.insertElement(9);
	cout << set1; // Output: 0 1 3 4 7 9

	IntegerSet set2 = set1, set3(0), set4(10); // Creates a copy of set1 using the copy constructor
	set2.deleteElement(4);
	cout << set2; // Output: 0 1 3 7 9 

	cout << set1; // Output: 0 1 3 4 7 9 (set1 should not be affected by changes to set2)
	
	cout << set3;

	if (set1 == set2)
	{
		cout << "Set 1 and Set 2 are Equal" << endl;
	}
	else
	{
		cout << "Set 1 and Set 2 are Unequal" << endl;
	}

	cout << "Using ! Operator" << endl;
	set4 = !set1;
	cout << set4;
	
	cout << endl << "Union of Set 1 and Set 4" << endl;
	IntegerSet set5 = set1.unionOfSets(set4);
	cout << set5;

	cout << endl << "Intersection of Set 1 and Set 4" << endl;
	IntegerSet set6 = set1.intersectionOfSets(set4);
	cout << set6;

	if (set2.findElement(4) == 1)
	{
		cout << "Element 4 is Present in Set 2" << endl;
	}
	else
	{
		cout << "Element 4 is not Present in Set 2" << endl;
	}

	return 0;
} 

