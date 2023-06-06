// Homework 07
// Package Inheritance Hierarchy 

#include <iostream>
#include<stdio.h>
#include<string>
#include<string.h>

using namespace std;

// ADT - Package

class Package
{
private:

	string senderName;  // Variable Declaration
	string receiverName;
	string senderAddress;
	string receiverAddress;
	string senderCity;
	string receiverCity;
	float weight;
	float costPerOunce;

public:

	Package(string senderName = "", string receiverName = "", string senderAddress = "", string receiverAddress = "", string senderCity = "", string receiverCity = "", float weight = 0.00, float costPerOunce = 0.00) // 1- Parameterized Constructor
	{
		this->senderName = senderName;
		this->receiverName = receiverName;
		this->senderAddress = senderAddress;
		this->receiverAddress = receiverAddress;
		this->senderCity = senderCity;
		this->receiverCity = receiverCity;

		if (weight >= 0)
		{
			this->weight = weight;
		}
		else
		{
			this->weight = 0;
		}

		if (costPerOunce >= 0)
		{
			this->costPerOunce = costPerOunce;
		}
		else
		{
			this->costPerOunce = 0;
		}
	}
		

	// Getters

	string getSenderName() const 
	{
		return senderName;
	}

	string getReceiverName() const 
	{
		return receiverName;
	}

	string getSenderAddress() const 
	{
		return senderAddress;
	}

	string getReceiverAddress() const 
	{
		return receiverAddress;
	}

	string getSenderCity() const 
	{
		return senderCity;
	}

	string getReceiverCity() const 
	{
		return receiverCity;
	}

	float getWeight() const
	{
		return weight;
	}

	float getCostPerOunce() const 
	{
		return costPerOunce;
	}


	// Setters

	void setSenderName(string sName) 
	{
		senderName = sName;
	}

	void setReceiverName(string rName) 
	{
		receiverName = rName;
	}

	void setSenderAddress(string sAddress) 
	{
		senderAddress = sAddress;
	}

	void setReceiverAddress(string rAddress) 
	{
		receiverAddress = rAddress;
	}

	void setSenderCity(string sCity) 
	{
		senderCity = sCity;
	}

	void setReceiverCity(string rCity) 
	{
		receiverCity = rCity;
	}

	void setWeight(float w)
	{
		if (w >= 0) 
		{
			weight = w;
		}
		else
		{
			weight = 0;
		}
	}

	void setCostPerOunce(float c) 
	{
		if (c >= 0) 
		{
			costPerOunce = c;
		}
		else
		{
			costPerOunce = 0;
		}
	}

	// Member Function

	virtual float calculateCost() const 
	{
		return weight * costPerOunce;
	}

	// Additional Member Function

	virtual void print()
	{
		cout << "Name of Sender: " << senderName << endl;
		cout << "Name of Receiver: " << receiverName << endl;
		cout << "Address of Sender: " << senderAddress << endl;
		cout << "Address of Receiver: " << receiverAddress << endl;
		cout << "City of Sender: " << senderCity << endl;
		cout << "City of Receiver: " << receiverCity << endl;
		cout << "Weight of the Package: " << weight << endl;
		cout << "Cost Per Ounce of the Package: " << costPerOunce << endl;
		cout << "Package Shipping Cost: " << Package::calculateCost() << endl;
	}
};

// ADT - TwoDayPackage

class TwoDayPackage :public Package
{
private:

	float flatFee;

public:

	 // 1- Parameterized Constructor
	
	TwoDayPackage(string sender = "", string receiver = "", string senderAddr = "", string receiverAddr = "", string senderCity = "", string receiverCity = "", float weight = 0.00, float costPerOunce = 0.00, float flatFee = 0.00) : Package(sender, receiver, senderAddr, receiverAddr, senderCity, receiverCity, weight, costPerOunce)
	{
		this->flatFee = flatFee;
	}

	// Getters

	float getFlatFee() const
	{
		return flatFee;
	}

	// Setters

	void setFlatFee(float f)
	{
		this->flatFee = f;
	}

	// Member Function

	float calculateCost() const
	{
		return flatFee + Package::calculateCost();
	}

	// Additional Member Function

	void print()
	{
		Package::print();
		cout << "Two Day Delivery Charges of the Package: " << flatFee << endl;
		cout << "Two Day Package Shipping Cost: " << TwoDayPackage::calculateCost() << endl;
	}
};


// ADT - OvernightPackage

class OverNightPackage :public Package
{
private:

	float feePerOunce;

public:

	OverNightPackage(string sender = "", string receiver = "", string senderAddr = "", string receiverAddr = "", string senderCity = "", string receiverCity = "", float weight = 0.00, float costPerOunce = 0.00, float feePerOunce = 0.00) : Package(sender, receiver, senderAddr, receiverAddr, senderCity, receiverCity, weight, costPerOunce)
	{
		this->feePerOunce = feePerOunce;
	}

	// Getters

	float getFeePerOunce() const
	{
		return feePerOunce;
	}

	// Setters

	void setfeePerOunce(float f)
	{
		if(f >= 0)
		{
			this->feePerOunce = f;
		}
		else
		{
			this->feePerOunce = 0;
		}
		
	}

	// Member Function

	float calculateCost() const
	{
		float standardCost = Package::calculateCost(); 
        return standardCost + (feePerOunce * getWeight());
	}

	// Additional Member Function

	void print()
	{
		Package::print();
		cout << "Fee Per Ounce: " << feePerOunce << endl;
		cout << "Over Night Package Shipping Cost: " << OverNightPackage::calculateCost() << endl;
	}
};



int main()
{
	OverNightPackage obj1("Ali", "Ahmad", "103", "104", "Lahore", "Karachi", 45.6, 356.6, 89.1);
	obj1.print();

	return 0;
}
