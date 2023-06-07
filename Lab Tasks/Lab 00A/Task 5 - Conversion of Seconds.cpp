#include "iostream"

using namespace std;
int main()
{
	int sec=0,min=0,hour=0,day=0;
	
	cout << "Please Enter Seconds: ";
	cin >> sec;
	
	if (sec>=86400)
    {
    	day=sec/86400;
    	cout<<"Number of Days Are: "<<day;
	}
	
	else if (sec>=3600)
    {
    	hour=sec/3600;
    	cout<<"Number of Hours Are: "<<hour;
	}
    
    
    else if (sec>=60)
    {
    	min=sec/60;
    	cout<<"Number of Minutes Are: "<<min;
	}
	
	 return 0;
}
