#include <iostream>
#include <vector>
#include <unordered_map>


std::vector<int> twoSum(std::vector<int>& nums, int target)
{
	std::unordered_map<int, int> tmp;
	for(int i = 0; i < nums.size(); i++)
	{
		if(tmp.count(target - nums[i]))
			return {tmp[target - nums[i]], i};
		tmp[nums[i]] = i;
	}
	return {-1,-1};
}

int main ()
{
	std::vector<int> data{2, 7, 11, 15};
	int target{9};
	std::vector<int> result = twoSum(data, target);
	for(auto e : result) std::cout << e+1 << " ";
	
	std::cout<<"\n";
}