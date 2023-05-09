#include "stdc++.h"

using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int sum = 0;
		for (const auto& num : nums) sum ^= num;
		return sum;
	}
};