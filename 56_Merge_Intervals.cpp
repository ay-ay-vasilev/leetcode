#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

	vector<vector<int>> mergeOld(vector<vector<int>>& intervals) {
		int n = (*max_element(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; }))[1] + 1;
		vector<vector<int>> result;
		vector<int> helper(n, 0);

		sort(intervals.begin(), intervals.end(),
			[](const vector<int>& a, const vector<int>& b)
			{
				return a[0] < b[0];
			});

		int numOfIntervals = 0; int helperVal = 0; int startVal = 0;
		for (const auto& interval : intervals)
		{
			startVal = helper[interval[0]];
			helperVal = startVal == 0 ? ++numOfIntervals : startVal;
			for (int i = interval[0]; i <= interval[1]; ++i)
			{
				helper[i] = helperVal;
			}
		}

		helperVal = 0;
		int start = 0; int i = 0;
		for (i = 0; i < n - 1; ++i)
		{
			if (helperVal < helper[i])
			{
				helperVal = helper[i];
				start = i;
			}

			if (helper[i] != 0 && helper[i] != helper[i + 1])
				result.push_back({ start, i });
		}
		if (helper[start] == helper[i]) result.push_back({ start, i });
		else result.push_back({ i, i });

		return result;
	}

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