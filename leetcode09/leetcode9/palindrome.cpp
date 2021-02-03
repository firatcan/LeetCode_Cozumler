#include<iostream>
#include<stdlib.h>
#include<vector>
//palindrome number 

using namespace std;
bool isPalindrome(int x)
{
	vector<int> palindromeNum;
	if (x < 0)
		return false;
	while (x > 0)
	{
		palindromeNum.push_back(x % 10);
		x /= 10;
	}
	int size = palindromeNum.size();
	for (int i = 0; i < size; i++)
	{
		if (palindromeNum[i] != palindromeNum[size - 1 - i])
			return false;
	}
	return true;
}
int main()
{
	int number = 11;
	if (isPalindrome(number) == true)
		cout << "\n" << number << " is palindrome number\n";
	else
		cout << "\n" << number << " is not palindrome number\n";
	system("pause");
	return 0;
}