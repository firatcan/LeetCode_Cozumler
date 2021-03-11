#include<iostream>
#include<vector>
#include<map>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) 
{
	multimap<int, int> mapVec;
	vector<int> res;

	for (int i = 0; i < nums.size(); i++)
	{
		mapVec.insert({ nums[i], i });
	}

	auto iter = mapVec.find(target);
	auto iter2 = iter;
	if (iter == mapVec.end())
	{
		res.push_back(-1);
		res.push_back(-1);
		return res;
	}
	res.push_back(iter2->second);//first index
	while (iter!= mapVec.end())
	{
		if (iter->first != target)
		{
			iter--;
			break;
		}
		iter++;
	}
	if (iter == mapVec.end())
		iter--;
	if (iter->first == target)
		res.push_back(iter->second);
	else
		res.push_back(iter2->second);
	return res;
}

int main()
{
	vector<int> nums = { 2,3 };
	int target = 2;
	vector<int> res = searchRange(nums,target);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i];
	}
	cout << endl;
	return 0;
}
