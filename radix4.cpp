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

vector<cd> w2(n), w3(n), w4(n);
	for (int i = 0; i < n; i++) 
	{
		double alpha1 = -2 * M_PI * i / n;
		w2[i] = cd(cos(alpha1), sin(alpha1));
		
		double alpha2 = -4 * M_PI * i / n;
		w3[i] = cd(cos(alpha2), sin(alpha2));
		
		double alpha3 = -8 * M_PI * i / n;
		w4[i] = cd(cos(alpha3), sin(alpha3));
	}

vector<cd> A1(n / 4), A2(n / 4), A3(n/4), A4(n/4);
	for (int i = 0; i < n / 4; i++) 
	{

		A1[i] = a[i * 4];

		A2[i] = a[i * 4 + 1];
		
		A3[i] = a[i*4+2];
		
		A4[i]= a[i*4+3];
	}

vector<cd> res1,res2, res3, res4 ;
	res1 = fft(A1);

	res2 = fft(A2);
	
	res3 = fft(A3);
	
	res4 = fft(A4);

vector<cd> result(n);

	for (int k = 0; k < n / 4; k++) 
	{
		result[k] = res1[k] + (w2[k] * res2[k]) + (w3[k] * res3[k]) + (w4[k] * res4[k]) ;
		result[k + n / 4] =res1[k] - (w2[k] * res2[k]) - (w3[k] * res3[k]) - (w4[k] * res4[k]) ;
	        result[k + n/4 + 4] = res1[k] + (w2[k] * res2[k]) + (w3[k] * res3[k]) + (w4[k] * res4[k]) ;
		result[k + n / 4 + 8] =res1[k] - (w2[k] * res2[k]) - (w3[k] * res3[k]) - (w4[k] * res4[k]) ;		
		
	}
	return result;
	
}

int main()
{
	vector<cd> a{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	int len=a.size();
	vector<cd> b = fft(a);
	for (int i = 0; i < len; i++)
		cout << b[i] << endl;

}

