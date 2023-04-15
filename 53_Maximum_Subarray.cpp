#include <vector>

using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int maxSum = nums[0];
		int sum = nums[0];

		for (int i = 1; i < nums.size(); ++i)
		{
			if (sum < 0)
			{
				if (nums[i] > sum)
				{
					sum = nums[i];
				}
			}
			else
			{
				sum += nums[i];
			}

			if (maxSum < sum) maxSum = sum;
		}

		return maxSum;
	}
};