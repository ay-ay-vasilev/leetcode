#include <vector>

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