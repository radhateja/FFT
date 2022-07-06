#include<iostream>
#include<complex>
#include<vector>
using namespace std;

typedef complex<double> cd;

vector<cd>fft(vector<cd> &a)
{
	int n = a.size();
cout<<"size of a="<<n<<endl;
	if (n == 1)
		return vector<cd>(1, a[0]);

vector<cd> w(n),w1(n);
	for (int i = 0; i < n; i++) 
	{
		double alpha = -2 * M_PI * i / n;
		w[i] = cd(cos(alpha), sin(alpha));
		cout<<"twiddle"<<i<<w[i]<<endl;
		
	//	double alpha1 = -4 * M_PI * i / n;
	//	w1[i] = cd(cos(alpha1), sin(alpha1));
	//	cout<<"twiddle1"<<i<<w1[i]<<endl;
	}

	for(int i=0;i<n;i++)
	{	double alpha1 = -4 * M_PI * i / n;
		w1[i] = cd(cos(alpha1), sin(alpha1));
		cout<<"twiddle2"<<i<<w1[i]<<endl;
	}
vector<cd> A(n / 3), A1(n / 3), A2(n/3);
	for (int i = 0; i < n / 3; i++) 
	{

		A[i] = a[i*3];

		A1[i] = a[i*3+1];

		A2[i] =a[i*3+2];

		//cout<<"1st array="<<A3r[i]<<endl<<"2nd array="<<A3r1[i]<<endl<<"3rd array="<<A3r2[i]<<endl;
	}

	cout<<"1st array"<<endl;
	for(int i=0;i<n/3;i++)
	{
		cout<<A[i]<<endl;
	}


	cout<<"2nd array"<<endl;
	for(int i=0;i<n/3;i++)
	{
		cout<<A2[i]<<endl;
	}


	cout<<"3rd array"<<endl;
	for(int i=0;i<n/3;i++)
	{
		cout<<A2[i]<<endl;
	}

vector<cd> resA,resA1,resA2;
	resA = fft(A);

	resA1 = fft(A1);

	resA2 = fft(A2);

vector<cd> res(n);
	
	cout<<"printing the values of for radix-3: "<<endl;

	for (int k = 0; k < n / 3; k++) 
	{
		res[k] = resA[k] + w[k] * resA1[k] + w1[k]*resA2[k];
		res[k + n / 3] = resA[k] + w[k] *resA1[k] + w1[k]*resA2[k];
		res[k + 2*(n/3) ]=resA[k] + w[k]*resA1[k] + w1[k]*resA2[k];
	}
	return res;
	
}


int main()
{
	vector<cd> a{1,2,3,4,5,6,7,8,9};
	int len=a.size();
	
	vector<cd> b = fft(a);
	for (int i = 0; i < len; i++)
	cout <<"X["<<i<<"]=>"<<b[i] << endl;

}

