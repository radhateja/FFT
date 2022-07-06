#include<iostream>
#include<complex>
#include<vector>
using namespace std;
//int transpose[10][10]

typedef complex<double> cd;
vector<cd>fft(vector<cd> a)
{
	int n = a.size();

	if (n == 1)
		return vector<cd>(1, a[0]);

vector<cd> w(n);
	for (int i = 0; i < n; i++) 
	{
		double alpha = -2 * M_PI * i / n;
		w[i] = cd(cos(alpha), sin(alpha));
	}

vector<cd> Aeven(n / 2), Aodd(n / 2);
	for (int i = 0; i < n / 2; i++) 
	{

		Aeven[i] = a[i * 2];
		Aodd[i] = a[i * 2 + 1];
	}

vector<cd> reseven,resodd;
	reseven = fft(Aeven);
	resodd = fft(Aodd);

vector<cd> res(n);

	for (int k = 0; k < n / 2; k++) 
	{
		res[k] = reseven[k] + w[k] * resodd[k];
		res[k + n / 2] = reseven[k] - w[k] * resodd[k];
	}
vector< vector<cd> >transpose(a.size(), vector<cd>(a.size()));
int row=a.size();
int column=a.size();
 	for (int i = 0; i < row; ++i)
   	{
      		for (int j = 0; j < column; ++j)
        	{
        		transpose[j][i] = res[i][j];
			res[i][j] = transpose[i][j];
        	}
	}
	return res;
}


void display(vector<cd> a,int len)
	{
		cout<<"Answer for 2d-fft"<<endl;
		for(int i=0;i<len;i++)
			cout<<a[i]<<endl;
			
	}
/***********
vector<cd>trans(vector<cd> a,int len)
{
//vector<cd>transpose(len);
vector< vector<double> >transpose(a.size(), vector<double>(a.size()));
int row=a.size();
int column=a.size();
   for (int i = 0; i < row; ++i)
   {
      for (int j = 0; j < column; ++j)
      {
       transpose[j][i] = a[i][j];
      }
   }
	return transpose;
}
***********/


int main()
{
	int n;
	vector<cd> a{{4,6},{3,4}};
	vector<cd> b{};

	int l=a.size();
	cout<<"length:"<<l<<endl;
	
	a= fft(a);
	display(a,l);

	//trans(a,l);

	b= fft(a);
	display(b,l);
}

