#include <vector>

using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		int mid = 0;


		while (left < right)
		{
			mid = (left + right) / 2;

			if (nums[left] == target) return left;
			if (nums[right] == target) return right;
			if (nums[mid] == target) return mid;

			if (nums[mid] > nums[right])
			{
				if (target < nums[left] || target > nums[mid]) left = mid + 1;
				else right = mid - 1;
			}
			else if (nums[left] > nums[mid])
			{
				if (target > nums[right] || target < nums[mid]) right = mid - 1;
				else left = mid + 1;
			}
			else
			{
				if (target < nums[mid]) right = mid - 1;
				else left = mid + 1;
			}
		}

		if (left > 0 && left < nums.size() && nums[left] == target) return left;
		if (right > 0 && right < nums.size() && nums[right] == target) return right;
		if (left == right && nums[left] == target) return left;
		return -1;
	}
};