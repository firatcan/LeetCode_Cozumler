#include<iostream>
#include<stack>
using namespace std;

bool isValid(string s)
{
	int len = s.length();
	if (len == 0 || len == 1 || len % 2 != 0)
		return false;
	stack<char> acmaParantezler;
	for (int i = 0; i < len; i++)
	{
		if (s[i] != '(' && s[i] != ')' && s[i] != '[' && s[i] != ']' && s[i] != '{' && s[i] != '}')
			return false;
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			acmaParantezler.push(s[i]);
		else
		{
			if (acmaParantezler.size() == 0)
				return false;
			if (s[i] == ')' && acmaParantezler.top() == '(')
				acmaParantezler.pop();
			else if (s[i] == ']' && acmaParantezler.top() == '[')
				acmaParantezler.pop();
			else if (s[i] == '}' && acmaParantezler.top() == '{')
				acmaParantezler.pop();
			else
				return false;
		}
	}
	if (acmaParantezler.size() != 0)
		return false;
	return true;
}
void main()
{
	string s = "([)]";
	bool durum = isValid(s);
	if(durum == true)
		cout << "durum: true" << endl;
	else
		cout << "durum: false" << endl;
	system("pause");
}