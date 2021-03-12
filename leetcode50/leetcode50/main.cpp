#include<iostream>
using namespace std;

double myPow(double x, int n) 
{
	if (x == 0 || x == 1)
		return 1.0;
	return pow(x, n);
}

void main()
{
	cout << "res: " << myPow(2.1, 3) << endl;//(x,n) x^n
	system("pause");
}