#include<iostream>
#include<complex>
#include<cmath>
#define pi 3.14159265359

using namespace std;
typedef complex<double> cd;

cd **fft2d(cd**,int);
//cd *fft1d(cd*,int);
//cd **transpose(cd**,int);
cd *fft(cd* , int);

int main()
{
	cd **dp = new cd* [8];
        cd **res = new cd* [8];
	
	for(int i=0;i<2;i++)
	{
		dp[i] = new cd[4];
		//res[i] = new cd[2];
	}
	
	cout<<"Enter 8 elements into 3D array:"<<endl;
	/************
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			for(int k=0;k<2;k++)
			{
				cin>>dp[i][j][k];
			}
		}
	}
	*************/
	dp[2][2][2] = {{{1,2},{3,4}},{{5,6},{7,8}}};
	int length = sizeof(dp[0][0])/sizeof(dp[0][0][0]);
        res = fft2d(dp,length);

        for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			for(int k=0;k<2;k++)
			{
				cout<<"res="<<res[i][j][k]<<endl;	
			}
		}
	}
	
}

cd **fft2d(cd **dp,int length)
{
	cd *ptr1[length/4];
	cd **dp1 = new cd* [length/4];
	cd **dp2 = new cd* [length/4];

	for(int i=0;i<length/4;i++)
		dp1[i] = new cd [length/4];
	for(int i=0;i,length/4;i++)
		dp2[i] = new cd [length/4];

	for(int i=0;i<length/4;i++)
		ptr1[i] = fft(dp[i],length/4);
	
	for(int i=0;i<length/4;i++)
		for(int j=0;j<length/4;j++)
		{
		//cout<<"ptr="<<*ptr1[j]<<endl;
			dp[i][j]=ptr1[i][j];
		}
	/*******transpose**********/	
	for(int i=0;i<length/4;i++)
		for(int j=0;j<length/4;j++)
			dp1[j][i] = dp[i][j];
	/*************************/
	for(int i=0;i<length/4;i++)
		ptr1[i] = fft(dp1[i],length/4);

	for(int i=0;i<length/4;i++)
		for(int j=0;j<length/4;j++)
		{
		//cout<<"ptr="<<*ptr1[j]<<endl;
			dp1[j][i]=ptr1[i][j];
		}
   
	/*******transpose**********/	
	for(int i=0;i<length/4;i++)
		for(int j=0;j<length/4;j++)
			dp1[j][i] = dp[i][j];
	/*************************/
	for(int i=0;i<length/4;i++)
		ptr1[i] = fft(dp1[i],length/4);

	for(int i=0;i<length/4;i++)
		for(int j=0;j<length/4;j++)
		{
		//cout<<"ptr="<<*ptr1[j]<<endl;
			dp1[j][i]=ptr1[i][j];
		}

	for(int i=0;i<length/4;i++)
		for(int j=0;j<length/4;j++)
			cout<<"dp1[i][j]="<<dp[i][j]<<endl;
	
	return dp1;
}



/*cd *fft1d(cd *sp,int length)
{
        
	cd *res1 = fft(sp,length);
	
        for(int i=0;i<length;i++)
        cout<<"res1="<<res1[i]<<endl;
	return res1;
}*/

cd *fft(cd* arr, int length)
{
        cd *W=new cd [length];

        if(length==1)
        	return arr;

        double theta = -2*pi/length;

        for(int i=0;i<length;i++)
       		 W[i]=cd(cos(theta*i),sin(theta*i));

        cd *a_even=new cd [length/2];
        cd *a_odd=new cd [length/2];

        for(int i=0;i<length/2;i++)
        {
                a_even[i] = arr[2*i];
               a_odd[i] = arr[2*i+1];
        }

        cd *res_even;
        cd *res_odd;

        res_even = fft(a_even,length/2);
        res_odd = fft(a_odd,length/2);

        cd *temp = new cd [length];

        for(int j=0;j<length/2;j++)
        {
                temp[j] = res_even[j] + (W[j] * res_odd[j]);
                temp[j+length/2] = res_even[j] - (W[j] * res_odd[j]);
        }

        return temp;
}

