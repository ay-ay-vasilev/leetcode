#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> insert_v0(vector<vector<int>>& intervals, vector<int>& newInterval) {
		vector<vector<int>> result = intervals;

		if (intervals.empty())
		{
			result.push_back(newInterval);
			return result;
		}

		int leftInterval = newInterval[0]; int rightInterval = newInterval[1];
		int toDeleteLeft = -1;
		int toDeleteRight = -1;
		int i = 0;
		int biggerThan = 0;

		for (const auto& interval : intervals)
		{
			if
				(
					leftInterval >= interval[0] && leftInterval <= interval[1] ||
					rightInterval >= interval[0] && rightInterval <= interval[1] ||
					leftInterval >= interval[0] && rightInterval <= interval[1] ||
					leftInterval <= interval[0] && rightInterval >= interval[1]
					)
			{
				leftInterval = min(interval[0], leftInterval);
				rightInterval = max(interval[1], rightInterval);

				if (toDeleteLeft == -1) toDeleteLeft = i;
				toDeleteRight = i;
			}

			if (leftInterval >= interval[0] && leftInterval >= interval[1])
			{
				++biggerThan;
			}

			++i;
		}

		if (toDeleteLeft > -1)
		{
			result.erase(result.begin() + toDeleteLeft, result.begin() + toDeleteRight + 1);
			result.insert(result.begin() + toDeleteLeft, { leftInterval, rightInterval });
		}
		else
		{
			result.insert(result.begin() + biggerThan, { leftInterval, rightInterval });
		}

		return result;
	}

	vector<vector<int>> insert_v1(vector<vector<int>>& intervals, vector<int>& newInterval)
	{
		if (intervals.empty()) return { newInterval };
		vector<vector<int>> result;
		bool passed = false;
		for (const auto& interval : intervals)
		{
			if (interval[1] < newInterval[0]) result.push_back(interval);
			else if (interval[0] > newInterval[1])
			{
				if (!passed)
				{
					result.push_back(newInterval);
					passed = true;
				}
				result.push_back(interval);
			}
			else
			{
				newInterval[0] = min(newInterval[0], interval[0]);
				newInterval[1] = max(newInterval[1], interval[1]);
			}
		}
		if (!passed) result.push_back(newInterval);
		return result;
	}

	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
	{
		int n = intervals.size(), i = 0;
		vector<vector<int>> result;
		while (i < n && intervals[i][1] < newInterval[0]) result.push_back(intervals[i++]);

		while (i < n && newInterval[1] >= intervals[i][0])
		{
			newInterval[0] = min(newInterval[0], intervals[i][0]);
			newInterval[1] = max(newInterval[1], intervals[i][1]);
			++i;
		}
		result.push_back(newInterval);

		while (i < n) result.push_back(intervals[i++]);
		return result;
	}
};