#include<iostream>
#include<string>
using namespace std;


string addBinary(string a, string b) 
{
	if (a.length() > b.length()) {
		b.insert(0, a.length() - b.length(), '0');
	}
	else if (b.length() > a.length()) {
		a.insert(0, b.length() - a.length(), '0');
	}

	char carry = '0';
	string res = "";
	for (int i = a.length()-1; i >=0 ; i--)
	{
		if (a[i] == '0' && b[i] == '0') 
		{
			res += carry;
			carry = '0';
		}
		else if (a[i] != b[i])
		{
			if (carry == '0') 
				res += '1';
			else 
			{
				res += '0';
				carry = '1';
			}
		}
		else if (a[i] == '1' && b[i] == '1') 
		{
			if (carry == '0')
			{
				res += '0';
			}
			else 
			{
				res += '1';
			}
			carry = '1';
		}
	}
	if (carry == '1')
		res += '1';
	reverse(res.begin(), res.end());
	return res;
}
/*
Input: a = "11", b = "1"
Output: "100"
		11
		 1
		 

Input: a = "1010", b = "1011"
Output: "10101"
*/
void main() 
{
	string a = "1010";
	string b = "1011";
	//			 101
	cout << "res: " << addBinary(a, b) << endl;
	system("pause");
}