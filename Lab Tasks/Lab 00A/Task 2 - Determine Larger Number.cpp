#include "iostream"

using namespace std;
int main()
{
 float num1=0,num2=0,first=0,second=0;
 cout << "Please Enter Number 1: ";
 cin>>num1;
 
 cout << "Please Enter Number 2: ";
 cin>>num2;
 
 if(num1>num2)
 {
 	cout<<"Number 1 is Larger than Number 2"<<endl;
 	first=num1;
 	second=num2;
 }
 else if(num1<num2)
 {
 	cout<<"Number 1 is Smaller than Number 2"<<endl;
 	first=num2;
 	second=num1;
 }
 
 cout<<"In Ascending Order: "<<endl;
 cout<<"First Number is: "<<second <<endl;
 cout<<"Second Number is: " <<first<<endl;
	
	return 0;
}
