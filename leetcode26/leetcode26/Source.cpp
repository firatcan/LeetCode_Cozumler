#include<iostream>
#include<vector>
using namespace std;
int removeDuplicates(vector<int>& nums) 
{
	int len = 0;
	int numsSize = nums.size();
	if (numsSize == 0)
		return numsSize;
	if (numsSize == 1)
		return numsSize;
	for (auto iter=nums.begin();iter!=nums.end()-1;)
	{
		auto iterArtiBir = iter+1;
		if (*iter == *iterArtiBir)
		{
			nums.erase(iterArtiBir);
		}
		else
			iter++;
	}
	return nums.size();
}
void main()
{
	vector<int> nums;
	nums.push_back(0);
	nums.push_back(0);
	nums.push_back(1);
	int len = removeDuplicates(nums);
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << endl;
	}
	cout << "------------" << endl;
	cout << "len: " << len << endl;
	system("pause");
}