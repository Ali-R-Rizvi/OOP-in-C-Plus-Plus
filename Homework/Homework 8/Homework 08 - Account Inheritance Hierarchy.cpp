// Homework 08
// Account Inheritance Hierarchy

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class Account
{
protected:

	string firstName;
	string lastName;
	double currentBalance;

public:

	// Getters

	string getFirstName()
	{
		return firstName;
	}

	string getLastName()
	{
		return lastName;
	}

	double getCurrentBalance()
	{
		return currentBalance;
	}

	// Setters

	void setFirstName(string f)
	{
		this->firstName = f;
	}

	void setLastName(string l)
	{
		this->lastName = l;
	}

	void setCurrentBalance(double c)
	{
		this->currentBalance = c;
	}

	// Member Functions

	Account(string firstName, string lastName, double currentBalance)
	{
		this->firstName = firstName;
		this->lastName = lastName;
		this->currentBalance = currentBalance;
	}

	virtual string getAcctType() const
	{
		return "Account";
	}

	virtual double debitTransaction(double debitAmount)
	{
		currentBalance = currentBalance - debitAmount;
		return currentBalance;
	}
	
	virtual double creditTransaction(double creditAmount) 
	{
		currentBalance = currentBalance + creditAmount;
		return currentBalance;
	}

	void print() 
	{
		cout << firstName << " " << lastName << " " << getAcctType() << " " << currentBalance << endl;
	}
};

class CheckingAccount : public Account 
{
public:

	// Member Functions

	CheckingAccount(string firstName = "", string lastName = "", double currentBalance = 0.00) : Account(firstName, lastName, currentBalance) 
	{

	}

	virtual string getAcctType() const 
	{
		return "CheckingAccount";
	}

	virtual double debitTransaction(double debitAmount) 
	{
		chargeFee();
		return Account::debitTransaction(debitAmount);
	}

	virtual double creditTransaction(double creditAmount) 
	{
		double newBalance1 = Account::creditTransaction(creditAmount);

		if (newBalance1 < 100.00)  
		{
			chargeFee();
		}

		return newBalance1;
	}

private:

	void chargeFee()
	{
		if (currentBalance < 100.0) // Minimum Balance is 100.00
		{
			currentBalance = currentBalance - 10.0; // Transaction Fee of Amount 10 is Charged
		}
	}
};

class SavingsAccount : public Account 
{
private:
	
	int numTransactions = 0;

public:

	// Member Functions

	SavingsAccount(string firstName = "", string lastName = "", double currentBalance = 0.00) : Account(firstName, lastName, currentBalance) 
	{

	}

	virtual string getAcctType() const 
	{
		return "SavingsAccount";
	}

	virtual double debitTransaction(double debitAmount) 
	{
		if (numTransactions < 2) // Maximum Transactions are 2
		{
			Account::debitTransaction(debitAmount);
			payInterest();
			numTransactions++;
		}

		return currentBalance;
	}

	virtual double creditTransaction(double creditAmount) 
	{
		if (numTransactions < 2) // Maximum Transactions are 2
		{
			Account::creditTransaction(creditAmount);
			payInterest();
			numTransactions++;
		}

		return currentBalance;
	}

private:

	void payInterest() 
	{
		currentBalance =currentBalance + (currentBalance * 0.02); // 2% = 0.02 Interest Rate
	}
};

int main() 
{
	Account* ac1 = new CheckingAccount("Saud", "Yaseen", 200.0);
	Account* ac2 = new SavingsAccount("Hunain", "Shahid", 1000.0);

	cout << "*** Two Accounts ***" << endl;
	ac2->print();
	ac1->print();
	cout << "\n" << endl;

	cout << "=== Test for CheckingAccount ===" << endl;
	cout << "(1) Debitting 150.00 -- The balance is " << ac1->debitTransaction(150.0) << endl;
	cout << "(2) Debitting 5.00 -- The balance is " << ac1->debitTransaction(5.0) << endl;
	cout << "(3) Crediting 200.00 -- The balance is " << ac1->creditTransaction(200.0) << endl;
	cout << "(*) Final account information" << endl;
	ac1->print();
	cout << "\n" << endl;
    

	cout << "=== Test for SavingsAccount ===" << endl;
	cout << "(1) Debitting 150.00 -- The balance is " << ac2->debitTransaction(150.0) << endl;
	cout << "(2) Crediting 200.00 -- The balance is " << ac2->creditTransaction(200.0) << endl;
	cout << "(3) Debitting 5.00 -- The balance is " << ac2->debitTransaction(5.0) << endl;
	cout << "(*) Final account information" << endl;
	ac2->print();

	delete ac1;
	delete ac2;
	
	return 0;
}
