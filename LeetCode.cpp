#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	if (nums.size() < 3)
	{
		return {};
	}
	if (nums[0] > 0)
	{
		return {};
	}
	vector<vector<int>> result;
	unordered_map<int, int> map;
	for (int i = 0; i < nums.size(); ++i)
	{
		map[nums[i]] = i;
	}

	for (int i = 0; i < nums.size() - 2; ++i)
	{
		for (int j = i + 1; j < nums.size() - 1; ++j)
		{
			int third = -(nums[i] + nums[j]);
			if (map.count(third) && map.find(third)->second > j)
				result.push_back({ nums[i], nums[j], third });
			j = map.find(nums[j])->second;
		}
		i = map.find(nums[i])->second;
	}
	return result;
}


int main()
{
	vector<int> test = { -1, 0, 1, 2, -1, -4 };
	const auto results = threeSum(test);
	cout << "[ ";
		for (const auto& triplet : results)
		{
			cout << "[";
			for (const auto& num : triplet)
			{
				cout << num << " ";
			}
			cout << "]" << " ";
		}
	cout << "]" << "\n";
	return 0;
}