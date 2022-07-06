#include<iostream>
using namespace std;


int main()
{
	float x,z;
	int a;

        cout<<"Enter a floating point number: "<<endl;
	cin>>x;
        z = x;
	a = x;
	
	x = x-a;
        
	x*=10;
        
	if(x>=5.0)
	{
		a+=1;
		cout<<z<<" in fixed point representation is: "<<a<<endl;
	}
	else
	cout<<z<<" in fixed point representation is: "<<a<<endl;
}
