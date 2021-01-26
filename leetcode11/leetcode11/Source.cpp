#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int maxArea(vector<int>& height)
{
	int bas = 0;
	int son = height.size()-1;
	int fark = 0;
	int area = 0;
	vector<int> arr;
	while (bas < son)
	{
		fark = son - bas;
		if (height[bas] < height[son])
		{
			area = fark * height[bas];
			bas++;
		}
		else 
		{
			area = fark * height[son];
			son--;
		}
		arr.push_back(area);
	}
	sort(arr.begin(), arr.end());
	return arr.at(arr.size()-1);
}
void main()
{
	vector<int> boyutlar= { 2,3,4,5,18,17,6 };
	int alan = maxArea(boyutlar);
	cout << "max alan: " << alan << endl;
	system("pause");
}