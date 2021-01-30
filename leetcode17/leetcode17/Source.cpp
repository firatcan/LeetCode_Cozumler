#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

map<string, string> add()
{
	map<string, string> digitsAndLetters;

	digitsAndLetters.insert(make_pair("2", ("abc")));
	digitsAndLetters.insert(make_pair("3", ("def")));
	digitsAndLetters.insert(make_pair("4", ("ghi")));
	digitsAndLetters.insert(make_pair("5", ("jkl")));
	digitsAndLetters.insert(make_pair("6", ("mno")));
	digitsAndLetters.insert(make_pair("7", ("prs")));
	digitsAndLetters.insert(make_pair("8", ("tuv")));
	digitsAndLetters.insert(make_pair("9", ("wxyz")));

	return digitsAndLetters;
}
bool accepted(string digits)
{
	string notAccept = "*+0 #";
	for (int i = 0; i < notAccept.length(); i++)
	{
		if (digits.find(notAccept[i]) != string::npos )
			return false;
	}
	return true;
}

void combAdd(map<string, string> digitsAndLetters, char digit, vector<string>& letters)
{

	
}

vector<string> letterCombinations(string digits) 
{
	vector<string> letters;
	if (digits.size() == 0)
		return letters;
	if (accepted(digits) == false)	
		return letters;

	map<string, string> digitsAndLetters;
	digitsAndLetters = add();

	int digitsMaxSize = digits.size();
	int digitsSize = 1;
	string digit = "";
	for (int i = 0; i < digits.size(); i++)
	{
		digit = digits[i];
		auto iter = digitsAndLetters.find(digit);
		digitsSize *= iter->second.size();
		digit = "";
	}

	int loopNumber = 1;
	letters.resize(digitsSize, "");
	for (int i = 0; i < digitsMaxSize; i++)
	{
		digit = digits[i];
		auto iter = digitsAndLetters.find(digit);
		loopNumber = digitsSize / iter->second.size();
		for (int k = 0; k < iter->second.size(); k++) //abc,def,ghi,...
		{
			for (int j = 0; j < loopNumber; j++)//boyutlarinin carpimi
			{
				letters[j+k*loopNumber] += iter->second[k];
			}
		}
		digitsSize /= iter->second.size();
		digit = "";
	}

	for (int i = digitsMaxSize - 1; i >= 0; i--)
	{
		combAdd(digitsAndLetters, digits[i],letters);
	}

	return letters;
}
void main()
{
	string digits = "23";
	vector<string> letters;

	letters = letterCombinations(digits);



	cout << endl;
	for (int i = 0; i < letters.size(); i++)
	{
		cout << letters[i] << " , ";
	}
	cout << endl;

	system("pause");
}

/*
		string digit;
		digit += digits[i];
		auto iter = digitsAndLetters.find(digit);
		string second = iter->second;
		for (int j = 0; j < second.length(); j++)
		{
			for (int k = 0; k < newResize / maxLetterSize; k++)
			{
				letters[j*maxLetterSize] += second[j];
			}
		}
		newResize /= maxLetterSize;
*/