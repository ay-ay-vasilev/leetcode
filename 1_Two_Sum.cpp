#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		map<int, int> numMap;
		int i = 0;
		for (const auto& num : nums)
			numMap[num] = i++;

		i = 0;
		for (const auto& num : nums)
		{
			if (numMap.count(target - num) && numMap[target - num] != i)
				return { i, numMap[target - num] };
			++i;
		}
		return {};
	}
};