#include<iostream>
#include<complex>
using namespace std;
typedef complex<double> cd;
#define pi 3.14159265359
cd *fft(cd*,int);

/****>>2-D FFT Procedure<<****/
void TwodFFT(int length,cd (*arr)[2])
{

cd *res[length];

for(int i=0;i<length;i++)
	res[i] = fft(arr[i],length); // calling 1-D FFT function by passing array and length and return is storing in res 
	

for(int i=0;i<length;i++)
	{
	for(int j=0;j<length;j++)
		{
		arr[i][j]=res[i][j]; // the return FFT value is storing back to arr 
		}	
	}
cout<<">>>>1D-FFt Result<<<<"<<endl;
for(int i=0;i<length;i++)
	{
	for(int j=0;j<length;j++)
		{
		cout<<arr[i][j]<<endl;
		}	
	}

cd arr2[length][length];
for(int i=0;i<length;i++)
	{
	for(int j=0;j<length;j++)
		{
		arr2[j][i]=arr[i][j]; // Transposing the arr and storing arr2
		}
	}

cout<<"Transpose of matrix"<<endl;
for(int i=0;i<length;i++)
	{
	for(int j=0;j<length;j++)
		{
		cout<<arr2[i][j]<<endl;
		}
	}

cd *res1[length];

for(int i=0;i<length;i++)
	res1[i] = fft(arr2[i],length); // calling 1-D FFT function by passing array and length and return is storing in res1


for(int i=0;i<length;i++)
	{
	for(int j=0;j<length;j++)
		{
		arr[i][j]=res1[i][j]; // the return FFT value is storing back to arr 

		}
	}

cout<<">>>>2D-fft result<<<<"<<endl;
for(int i=0;i<length;i++)
	{
	for(int j=0;j<length;j++)
		{
		cout<<arr[i][j]<<endl;
		}
	}
}


/********>>>>1-D FFT<<<<**********/
cd* fft(cd *arr,int length)
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
                temp[j+length/2] = res_even[j] + (W[j+length/2] * res_odd[j]);
        }

        return temp;
}



int main()
{
        cd arr[][2]={{4,6},{3,4}};
        int length = sizeof(arr[0])/sizeof(arr[0][0]);
	TwodFFT(length,arr); //calling TwodFFT() funtion by passing 1-D array and length
}

