// Lab 06
// ADT - Item

#include <iostream>
#include <string>

using namespace std;

class Item
{
private:

	int id;
	string name;
	int quantity;
	float cost;

public:

	//Getters

	int getId()
	{
		return id;
	}

	string getName()
	{
		return name;
	}

	int getQuantity()
	{
		return quantity;
	}

	float getCost()
	{
		return cost;
	}

	//Setters

	void setId(int id)
	{
		if (id >= 0)
		{
			this->id = id;
		}
		else
		{
			this->id = 0;
		}
	}

	void setName(string name)
	{
		this->name = name;
	}

	void setQuantity(int quantity)
	{
		if (quantity >= 0)
		{
			this->quantity = quantity;
		}
		else
		{
			this->quantity = 0;
		}
	}

	void setCost(float cost)
	{
		if (cost >= 1.00)
		{
			this->cost = cost;
		}
		else
		{
			this->cost = 0.00;
		}
	}

	// Construtors

	Item(int id, string name, int quantity, float cost) // 1- Parameterized Constructor Taking 4 Parameters
	{
		setId(id);
		setName(name);
		setQuantity(quantity);
		setCost(cost);
	}
	Item(){}
	Item(int id, string name, int quantity) // 2- Parameterized Constructor Taking 3 Parameters
	{
		setId(id);
		setName(name);
		setQuantity(quantity);
		setCost(0.00);
	}

	Item(int id, string name, float cost) // 3- Parameterized Constructor Taking 3 Parameters
	{
		setId(id);
		setName(name);
		setQuantity(0);
		setCost(cost);
	}


	Item(const Item& obj) // 4- Copy Constructor
	{
		id = obj.id;
		name = obj.name;
		quantity = obj.quantity;
		cost = obj.cost;
	}

	~Item() // 5- Destructor
	{
		cout << "Destructor executed..." << endl;
	}

	//Member Functions

	void setItem(int id, string name, int quantity, float cost)
	{
		setId(id);
		setName(name);
		setQuantity(quantity);
		setCost(cost);
	}

	void getItem()
	{
		cout << "Enter Item's Item Number: ";
		cin >> id;
		setId(id);

		cout << "Enter Item's Name: ";
		cin >> name;
		setName(name);

		cout << "Enter Quantity of the Item: ";
		cin >> quantity;
		setQuantity(quantity);

		cout << "Enter Per Unit Cost of the Item: ";
		cin >> cost;
		setCost(cost);
	}

	void putItem()
	{
		cout << "-----------------------------------------" << endl;
		cout << "Items's ID: " << id << "\n";
		cout << "Item's Name: " << name << "\n";
		cout << "Item's Quantity: " << quantity << "\n";
		cout << "Item's Per Unit Cost: " << cost << "\n";
		cout << endl << "-----------------------------------------" << endl;
		cout << "\n";
	}


	float getTotalCost()
	{
		if (quantity >= 1)
		{
			float totalCost = 0.00;
			totalCost = (quantity * cost);
			return totalCost;
		}
		else
		{
			return 0.0f;
		}
	}

	bool isEqual(const Item& object) const
	{
		if (this->id == object.id && this->name == object.name && this->quantity == object.quantity && this->cost == object.cost)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void updateName(Item object[], const int size)
	{
		for (int i = 0; i < size; i++)
		{
			if (this->id == object[i].id)
			{
				object[i].name = this->name;
			}
		}
	}

	Item getMinimumCostItem(Item *object, const int size)
	{
		if (size == 0) 
		{
			cout << "ERROR!!! Array Size Must be Greater than Zero" << endl;
		}

		float min = object[0].cost;
		int index = 0;

		for (int i = 0; i < size; i++)
		{
			if (object[i].cost < min)
			{
				min = object[i].cost;
				index = i;
			}
		}

		return object[index];
	}

	float getAveragePrice(Item object[], const int size) 
	{
		float sum = 0.0;
		int count = 0;

		for (int i = 0; i < size; i++) 
		{
			if (object[i].getQuantity() >= 1) 
			{
				sum = sum + object[i].getCost();
				count++;
			}
		}

		if (count > 0) 
		{
			return sum / count;
		}
		else 
		{
			return 0.0; 
		}
	}
};


int main()
{
	Item obj1[4] = { Item(1, "Biscuit", 5, 5.00),Item(2, "Oil", 8, 89),Item(3, "Flour", 2, 9.12), Item(4, "Plastic", 1, 2222) };

	for (int i = 0; i < 4; i++)
	{
		obj1[i].putItem();
	}

	Item obj2(2, "y", 3, 4), obj3(0,"",0,0);
	cout << "Minimum Cost is: " << endl;
	obj3=obj3.getMinimumCostItem(obj1, 4);
	obj3.putItem();
	
	Item obj4[3] = { Item(2,"Cleaner",45,67.98),Item(2,"Stick",56,98.99) };
	obj2.updateName(obj4, 2);
	
	for (int i = 0; i < 2; i++)
	{
		obj4[i].putItem();
	}
	
	return 0;
}
