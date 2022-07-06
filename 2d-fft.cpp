#include<iostream>
#include<complex>
#include<cmath>
using namespace std;

typedef complex<double> cd;

cd* fft(cd *arr,int m,intn)
{


}
int main()
{
	cd arr[2][2]={{4,6},{3,4}};
	int rows,cols;
	rows = sizeof(arr)/sizeof(arr[0]);
	cols = sizeof(arr[0])/sizeof(arr[0][0]);
	cout<<"rows size:"<<rows<<endl;
	cout<<"cols size:"<<cols<<endl;

	cd result = fft(arr,rows,cols);
	for(int i=0;i<rows;i++)
		for(int j=0;j<cols;j++)
			cout<<result<<endl;

}
