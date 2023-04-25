#include "stdc++.h"

using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		if (nums.empty()) return 0;
		if (nums.size() == 1) return 1;

		map<int, int> hashTable;
		for (const auto& num : nums)
			hashTable[num]++;

		int length = 1;
		int maxLength = 1;
		auto lastElement = hashTable.begin();
		for (auto it = ++hashTable.begin(); it != hashTable.end(); ++it)
		{
			if ((*it).first == (*lastElement).first + 1) ++length;
			else
			{
				if (length > maxLength) maxLength = length;
				length = 1;
			}
			lastElement = it;
		}
		if (length > maxLength) maxLength = length;
		return maxLength;
	}
};