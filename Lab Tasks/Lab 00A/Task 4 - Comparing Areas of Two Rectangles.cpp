#include "iostream"

using namespace std;
int main()
{
	int len1=0,len2=0,wid1=0,wid2=0,area1=0,area2=0;
	
	cout << "Please Enter Length of First Rectangle: ";
	cin >> len1;
    
    cout << "Please Enter Width of First Rectangle: ";
	cin >> wid1;
	
	cout << "Please Enter Length of Second Rectangle: ";
	cin >> len2;
    
    cout << "Please Enter Width of Second Rectangle: ";
	cin >> wid2;

    area1=len1*wid1;
    area2=len2*wid2;
    
    cout<< "Area of First Rectangle is: "<<area1<<endl;
    cout<< "Area of Second Rectangle is: "<<area2<<endl;
    
    if(area1==area2)
    {
    	cout<<"Area of Both Rectangles are Same";
	}
	
	else if(area1>area2)
    {
    	cout<<"Area of First Rectangle is Greater";
	}
	
	else if(area1<area2)
    {
    	cout<<"Area of Second Rectangle is Greater";
	}
	 return 0;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
