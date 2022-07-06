#include<iostream>
#include<complex>
#include<vector>
using namespace std;

typedef complex<double> cd;

vector<cd> fft(vector<cd> a)
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
	return res;
	
}

int main()
{
	vector<cd> a{1,1,1,1};
	int len=a.size();
	vector<cd> b = fft(a);
	for (int i = 0; i < len; i++)
		cout << b[i] << endl;

}

