// Homework 01
// ADT - Employee

#include "iostream"
#include<string>

using namespace std;

class Employee
{
private:
	string name;
	int id;
	string department;
	string position;

public:
	Employee(string employeeName, int employeeId, string employeeDepartment, string employeePosition)
	{
		name = employeeName;
		id = employeeId;
		department = employeeDepartment;
		position = employeePosition;
		cout << endl << "Parameterized Constructor(Taking 4 Parameters)" << endl;
	}

	Employee(string employName, int employId)
	{
		name = employName;
		id = employId;
		department = "";
		position = "";
		cout << endl << "Parameterized Constructor(Taking 2 Parameters)" << endl;
	}

	Employee()
	{
		name = "";
		id = 0;
		department = "";
		position = "";
		cout << endl << "Default Constructor" << endl;
	}

	Employee(const Employee& obj)
	{
		name = obj.name;
		id = obj.id;
		department = obj.department;
		position = obj.position;
		cout << endl << "Copy Constructor" << endl;
	}

	~Employee()
	{
		cout << "Destructor executed..." << endl;
	}

	//Getters
	string getName()
	{
		return name;
	}

	int getId()
	{
		return id;
	}

	string getDepartment()
	{
		return department;
	}

	string getPosition()
	{
		return position;
	}

	//Setters

	void setName(string n)
	{
		name = n;
	}
	void setId(int i)
	{
		id = i;
	}
	void setDepartment(string dep)
	{
		department = dep;
	}
	void setPosition(string p)
	{
		position = p;
	}

	//Member Functions

	void setInfo(string name, int id, string department, string position)
	{
		setName(name);
		setId(id);
		setDepartment(department);
		setPosition(position);
	}

	void getInfo()
	{
		cout << "Enter Name of the Employee: ";
		cin >> name;
		setName(name);

		cout << "Enter ID of the Employee: ";
		cin >> id;
		setId(id);

		cout << "Enter Department of the Employee: ";
		cin >> department;
		setDepartment(department);

		cout << "Enter Position of the Employee: ";
		cin >> position;
		setPosition(position);

	}

	void putInfo()
	{
		cout << name << "\t";
		cout << id << "\t";
		cout << department << "\t";
		cout << position << "\t";
		cout << "\n";
	}
};

int main()
{
	cout << "Name" << "\t" << "        Id Number" << "\t" << "Department" << "\t" << "Position" << endl; //Heading

	Employee obj1("Naveed Ali", 1230, "Computer Science", "Assistant Professor"); //Object 1 Using Parameterized Constructor that takes 4 Parameters  
	obj1.putInfo();

	Employee obj2("Nouman Abdullah", 1231); //Object 2 Using Parameterized Constructor that takes 2 Parameters
	obj2.setDepartment("Software Engineering");
	obj2.setPosition("Lecturer");
	obj2.putInfo();

	Employee obj3;  //Object 3 Using Default Constructor
	obj3.setName("Naeem Ahmad");
	obj3.setId(1241);
	obj3.setDepartment("Computer Science");
	obj3.setPosition("Lecturer");
	obj3.putInfo();

	Employee obj4; //Object 4 Using Copy Constructor 
	cout << "Copy Construstor" << endl;
	obj4 = obj3; //Using Copy Constructor
	obj4.putInfo();

	Employee obj5; //Object 5 Using Setters and Getters
	obj5.setName("Ali Raza");
	obj5.setId(30);
	obj5.setDepartment("IT");
	obj5.setPosition("Student");
	obj5.getName();
	obj5.getId();
	obj5.getDepartment();
	obj5.getPosition();
	obj5.putInfo();

	
	Employee obj6; //Object 6 Using getInfo and putInfo(Member Functions)
	obj6.getInfo();
	
	obj6.putInfo(); //Displaying All Objects Again
	obj5.putInfo();
	obj4.putInfo();
	obj3.putInfo();
	obj2.putInfo();
	obj1.putInfo();
	return 0;
}
