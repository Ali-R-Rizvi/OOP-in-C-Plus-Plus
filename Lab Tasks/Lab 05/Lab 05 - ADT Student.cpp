// Lab - 05
// ADT - Student

#include "iostream"
#include<string>

using namespace std;

class Student
{
private:

	int regNo;
	string firstName;
	string lastName;
	string program;
	float cgpa;

public:
	//Mutators & Accessors
	//Getters
	int getRegNo()
	{
		return regNo;
	}

	string getFirstName()
	{
		return firstName;
	}

	string getLastName()
	{
		return lastName;
	}

	string getProgram()
	{
		return program;
	}

	float getCgpa()
	{
		return cgpa;
	}

	//Setters

	void setRegNo(int n)
	{
		if (n >= 501 && n <= 565)
		{
			this->regNo = n;
		}
		else
		{
			this->regNo = 0;
		}
	}
	void setFirstName(string a)
	{
		this->firstName = a;
	}
	void setLastName(string b)
	{
		this->lastName = b;
	}
	void setProgram(string p)
	{
		this->program = p;
	}
	void setCgpa(float f)
	{
		if (f >= 0.00 && f <= 4.00)
		{
			this->cgpa = f;
		}
		else
		{
			this->cgpa = -1;
		}
	}
	Student()
	{

	}
	Student(int regNum, string fname, string lname, string prog)
	{
		setRegNo(regNum);
		setFirstName(fname);
		setLastName(lname);
		setProgram(prog);
		setCgpa(-1);
		cout << endl << "Parameterized Constructor (Taking 4 Parameters)" << endl;
	}

	Student(int regNum, string fname, string prog)
	{
		setRegNo(regNum);
		setFirstName(fname);
		setLastName("");
		setProgram(prog);
		setCgpa(-1);
		cout << endl << "Parameterized Constructor (Taking 3 Parameters)" << endl;
	}

	Student(int regNum, string fname, string lname, string prog, float cgpa)
	{
		setRegNo(regNum);
		setFirstName(fname);
		setLastName(lname);
		setProgram(prog);
		setCgpa(cgpa);
		cout << endl << "Parameterized Constructor(Taking 5 Parameters)" << endl;
	}

	Student(const Student& obj)
	{
		cout << endl << "Copy Constructor" << endl;
		regNo = obj.regNo;
		firstName = obj.firstName;
		lastName = obj.lastName;
		program = obj.program;
		cgpa = obj.cgpa;
	}

	~Student()
	{
		cout << "Destructor executed..." << endl;
	}

	

	//Member Functions

	void set(int regNum, string fName, string lName, string programs, float cgpa)
	{
		setRegNo(regNum);
		setFirstName(fName);
		setLastName(lName);
		setProgram(programs);
		setCgpa(cgpa);
	}

	void read()
	{

		cout << "Enter Registration Number of Student: ";
		cin >> regNo;
		setRegNo(regNo);

		cout << "Enter First Name of Student: ";
		cin >> firstName;
		setFirstName(firstName);

		cout << "Enter Last Name of Student: ";
		cin >> lastName;
		setLastName(lastName);

		cout << "Enter Program of Student: ";
		cin >> program;
		setProgram(program);

		cout << "Enter CGPA of Student: ";
		cin >> cgpa;
		setCgpa(cgpa);

	}

	void write()
	{
		cout << "---------------------------------------------------------------------------------------------" << endl;
		cout << "Registration No: " << regNo << "\t";
		cout << "First Name: " << firstName << "\t";
		cout << "Last Name: " << lastName << "\t";
		cout << "Program: " << program << "\t";
		cout << "CGPA: " << cgpa << "\t";
		cout << "\n";
		cout << "---------------------------------------------------------------------------------------------" << endl;
	}

	bool isFirstSemester()
	{
		if (cgpa == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	float getPercentage()
	{
		if (cgpa >= 0.00)
		{
			float x = 0.00;
			x = (cgpa / 4) * 100;
			return x;
		}
		else
		{
			return -1;
		}
	}

	bool isPromoted()
	{
		if (cgpa >= 2.00)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

int main()
{
	Student obj1;
	obj1.setRegNo(551);
	obj1.setFirstName("Asghar");
	obj1.setLastName("Ali");
	obj1.setProgram("Botany");
	obj1.setCgpa(4.111);
	obj1.write();


	Student obj11(555, "Ali", "Raza", "IT"); //Object 1 Using Parameterized Constructor that takes 4 Parameters  
	obj11.write();

	Student obj2(556, "Ahmad", "CS");//Object 2 Using Parameterized Constructor that takes 3 Parameters
	obj2.write();

	Student obj3(557, "Shehryar", "Khan", "CS", 6);//Object 3 Using Parameterized Constructor that takes 5 Parameters
	obj3.write();

	Student obj4 = obj3;;//Object 4 Using Copy Constructor 
	obj4.write();

	Student obj5;
	obj5.set(557, "Afeef", "Wadood", "SE", 3.11);
	obj5.write();

	Student obj6;
	obj6.read();
	obj6.write();

	if (obj3.isFirstSemester() == 1)
	{
		cout << "First Semester: " << endl;
	}
	else
	{
		cout << "Not First Semester: ";
	}

	float x = obj3.getPercentage();
	cout << "Percentage: " << x << endl;

	if (obj3.isPromoted() == 1)
	{
		cout << "Promoted " << endl;
	}
	else
	{
		cout << "Not Promoted ";
	}
	return 0;
}
