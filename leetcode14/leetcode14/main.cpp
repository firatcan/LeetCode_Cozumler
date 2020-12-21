#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs) 
{
    if (strs.empty())
        return "";

    string prefix = strs[0];

    for (int i = 1; i < strs.size(); i++) 
    {
        while (strs[i].find(prefix) != 0) 
        {
            prefix = prefix.substr(0, prefix.size() - 1);
        }
    }
    return prefix;
}
void main()
{
	vector<string> strs;
	strs.push_back("flower");
	strs.push_back("flow");
	strs.push_back("flight");

	string longestString = longestCommonPrefix(strs);
	cout << "longest common prefix : " << longestString << endl;
	system("pause");
}