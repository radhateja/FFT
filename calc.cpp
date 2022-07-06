#include<iostream>
using namespace std;

class calc:
{
	float x,y,res;
	int a;
        public:
	        calc(float a, float b) : x(a),y(b)
	        calc convert(calc res);
	        calc operator+ (calc num1);
	        calc operator- (calc num1);
	        calc operator* (calc num1);
	        calc operator/ (calc num1);
};

calc calc :: convert(calc res)
{
    calc temp;
    temp.x = res.res;
    temp.a = res.res;
    temp.x = temp.x - temp.a;
    temp.x *= 10;
   
    if(temp.x>=5.0)
    {
	    temp.a+=1;
	    return temp;
    }
    else 
    return temp;
}


