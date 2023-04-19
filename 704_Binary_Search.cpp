#include "stdc++.h"

using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left < right)
		{
			int mid = (left + right) / 2;
			if (nums[mid] < target)
				left = mid + 1;
			else right = mid;
		}
		if (nums[left] == target) return left;
		return -1;
	}
};