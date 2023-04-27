#include "stdc++.h"

using namespace std;

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int best = INT_MIN;
		int minProduct = 1, maxProduct = 1;

		for (const auto& num : nums)
		{
			if (num < 0) swap(minProduct, maxProduct);

			minProduct = min(minProduct * num, num);
			maxProduct = max(maxProduct * num, num);

			best = max(best, maxProduct);
		}
		return best;
	}
};