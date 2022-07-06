#include<iostream>
#include<complex>
#include<cmath>

using namespace std;
#define pi 3.14159265359

typedef complex<double> cd;

cd** fft(cd *arr, int length)
{
	cd **W=new cd [length];

	if(length==1)
	return arr;

	double theta = -2*pi/length;

	for(int i=0;i<length;i++)
		for(int j=0;j<length;j++)
	W[i][j]=cd(cos(theta*i),sin(theta*i));

	cd **a_even=new cd [length/2];
	cd **a_odd=new cd [length/2];

	for(int i=0;i<length/2;i++)
	{
		a_even[i] = *arr[2*i];
	       a_odd[i] = *arr[2*i+1];	
	}

	cd **res_even;
	cd **res_odd;

	res_even = fft(a_even,length/2);
	res_odd = fft(a_odd,length/2);
        
	cd **temp = new cd [length];

	for(int j=0;j<length/2;j++)
		for(int i=0;i<length;i++)
	{
		temp[j][i] = *res_even[j] + ((*W[j]) * (*res_odd[j]));
		temp[j+length/2][i] = *res_even[j] -((*W[j]) * (*res_odd[j]));
	}

	return temp;
}


int main()
{
	cd arr[2][2]={{4, 6},{3, 4}};
	int length = sizeof(arr[0])/sizeof(arr[0][0]);
	cout<<"length:"<<length<<endl;
	cd **res = fft(&arr,length);
	for(int i=0;i<length;i++)
		for(int j=0;j<length;j++)
	cout<<res[i][j]<<endl;

}

