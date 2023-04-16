#include <vector>
#include <memory>
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		int n = intervals.size();
		if (n == 0) return {};
		vector<vector<int>> result;
		sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {return a[0] < b[0]; });
		result.push_back(intervals[0]);
		for (int i = 1; i < n; ++i)
		{
			if (intervals[i][0] > result.back()[1]) result.push_back(intervals[i]);
			else result.back()[1] = max(intervals[i][1], result.back()[1]);
		}
		return result;
	}
};

int main()
{
	const auto solution = make_unique<Solution>();
	vector<vector<int>> vec{ };
	const auto result = solution->merge(vec);

	for (const auto& vector : result)
	{
		for (const auto& el : vector)
		{
			cout << el << " ";
		}
	}

	return 0;
}