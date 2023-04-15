#include <vector>
#include <memory>
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int n = nums.size();
		vector<bool> jumps(n, false);
		jumps[0] = 1;

		for (int i = 0; i < nums.size(); ++i)
		{
			if (jumps[i] == false) break;
			if (nums[i] == 0)
			{
				continue;
			}
			for (int j = i + 1; j < nums.size() && j - i <= nums[i]; ++j)
			{
				if (j == n - 1) return true;
				jumps[j] = true;
			}
		}

		return jumps[n - 1];
	}
};

int main()
{
	const auto solution = make_unique<Solution>();
	vector<int> vec{ 0, 2, 3 };
	const auto result = solution->canJump(vec);

	cout << result;

	return 0;
}