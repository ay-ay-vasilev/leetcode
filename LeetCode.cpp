#include <vector>
#include <memory>
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

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

int main()
{
	const auto solution = make_unique<Solution>();
	vector<int> vec{ -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	const auto result = solution->maxSubArray(vec);

	cout << result << "\n";

	return 0;
}