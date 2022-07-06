#include<iostream>
#include<complex>
#include<cmath>

using namespace std;
#define pi 3.14159265359

typedef complex<double> cd;

cd** fft(cd **arr, int length)
{
	cd *W=new cd [length];

	if(length==1)
		return arr;

	double theta = -2*pi/length;

	for(int i=0;i<length;i++)
		W[i]=cd(cos(theta*i),sin(theta*i));
	
	
	cd *a_1=new cd [length/2];
	cd *a_2=new cd [length/2];

	for(int i=0;i<length/2;i++)
	{
		a_1[i] = arr[2*i];
	        a_2[i] = arr[2*i+1];	
	}

	cd *res_1;
	cd *res_2;

	res_1 = fft(a_1,length/2);
	res_2 = fft(a_2,length/2);
        
	cd *temp = new cd [length];
	for(int i=0;i<length/2;i++)
	for(int j=0;j<length/2;j++)
	{
		temp[i][j] = res_1[i][j] + (W[j] * res_2[i][j]);
		temp[i+length/2][j+length/2] = res_1[j] + (W[j+length/2] * res_2[i][j]);
	}

	return temp;
}


int main()
{
	cd arr[2][2]={{4,6},{3,4}};
	int length = sizeof(arr)/sizeof(arr[0]);
	cd **res = fft(&arr,length);
	for(int i=0;i<length;i++)
	cout<<res[i]<<endl;
	
	cd **res1 = fft(&res,length);
	for(int i=0;i<length;i++)
	cout<<res1[i]<<endl;

}

