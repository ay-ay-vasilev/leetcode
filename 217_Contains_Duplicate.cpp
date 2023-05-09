#include "stdc++.h"

using namespace std;

class Solution {
public:
	bool containsDuplicate(vector<int>& nums)
	{
		unordered_map<int, int> dict;

		for (const auto& num : nums)
		{
			if (dict.count(num))
				return true;
			dict[num] = 1;
		}
		return false;
	}
};