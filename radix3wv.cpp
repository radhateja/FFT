#include<iostream>
#include<complex>
#include<cmath>

using namespace std;
#define pi 3.14159265359

typedef complex<double> cd;

cd* fft(cd* arr, int length)
{
	cd *W=new cd [length];
	cd *W1=new cd [length];

	if(length==1)
		return arr;

	double theta = -2*pi/length;

	for(int i=0;i<length;i++)
	W[i]=cd(cos(theta*i),sin(theta*i));
	
	
	double theta1 = -4*pi/length;

	for(int i=0;i<length;i++)
	W1[i]=cd(cos(theta1*i),sin(theta1*i));
	

	cd *a_1=new cd [length/3];
	cd *a_2=new cd [length/3];
	cd *a_3=new cd [length/3];

	for(int i=0;i<length/3;i++)
	{
		a_1[i] = arr[3*i];
	        a_2[i] = arr[3*i+1];	
		a_3[i] = arr[3*i+2];
	}

	cd *res_1;
	cd *res_2;
	cd *res_3;

	res_1 = fft(a_1,length/3);
	res_2 = fft(a_2,length/3);
	res_3 = fft(a_3,length/3);
        
	cd *temp = new cd [length];

	for(int j=0;j<length/3;j++)
	{
		temp[j] = res_1[j] + (W[j] * res_2[j])+(W1[j]*res_3[j]);
		temp[j+length/3] = res_1[j] + (W[j+length/3] * res_2[j])+(W1[j+length/3]*res_3[j]);
		temp[j+2*(length/3)] = res_1[j] + (W[j+2*(length/3)] * res_2[j])+(W1[j+2*(length/3)]*res_3[j]);
	}

	return temp;
}


int main()
{
	cd arr[]={1,2,3,4,5,6,7,8,9};
	int length = sizeof(arr)/sizeof(arr[0]);
	cd *res = fft(arr,length);
	for(int i=0;i<length;i++)
	cout<<res[i]<<endl;

}

