#include "stdc++.h"

using namespace std;

class Solution {
public:
	int findMin(vector<int>& nums)
	{
		if (nums.size() == 1) return nums[0];

		int left = 0, right = nums.size() - 1;
		int mid;

		while (left < right)
		{
			mid = left + (right - left) / 2;
			if (nums[right] >= nums[mid]) right = mid;
			else left = mid + 1;
		}
		return nums[left];
	}
};