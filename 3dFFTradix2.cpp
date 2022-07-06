#include<iostream>
using namespace std;
#include<complex>
typedef complex<double> cd;
#define pi 3.14159265359
cd *fft(cd*,int);

/********3D-FFt Procedure********/

void threedFFT(int length,cd (*arr)[2])
{

cd *res[length];

for(int i=0;i<length;i++)
	res[i] = fft(arr[i],length);	//calling 1D-FFT and storing in res

for(int i=0;i<length;i++)
	for(int j=0;j<length;j++)
		arr[i][j]=res[j][i];	//returned value storing in arr after transposing

cd *res1[length];

for(int i=0;i<length;i++)
	res1[i] = fft(arr[i],length);	//calling 1D-FFT and storing in res1

for(int i=0;i<length;i++)
	for(int j=0;j<length;j++)
		arr[i][j]=res1[j][i];	//returned value storing in arr after transposing


cd *res2[length];
for(int i=0;i<length;i++)
	res2[i]=fft(arr[i],length);	//calling 1D-FFT and storing in res2

for(int i=0;i<length;i++)
	for(int j=0;j<length;j++)
		arr[i][j]=res2[j][i];	//returned value storing in arr after transposing

for(int i=0;i<length;i++)
	for(int j=0;j<length;j++)
		cout<<arr[i][j]<<"  ";
		cout<<endl;		//printing 3d-FFT values of given input
}
/*********1D-FFT*********/

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
/***********main Function***********/
int main()
{
cd arr[2][2][2]={{{cd(1,0),cd(2,0)},{cd(3,0),cd(4,0)}},{{cd(5,0),cd(6,0)},{cd(7,0),cd(8,0)}}};	  //input 
int length=sizeof(arr[0][0])/sizeof(arr[0][0][0]);//calculating the length of the given input 
cout<<length<<endl;

for(int i=0;i<length;i++)
	threedFFT(length,arr[i]);//calling threedFFT() function by passing 2d-array and length
}
