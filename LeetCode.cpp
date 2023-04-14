#include <vector>
#include <memory>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<vector<int>> result;
	void solve(int i, vector<int>& arr, vector<int>& temp, int target)
	{
		if (target == 0)
		{
			result.push_back(temp);
			return;
		}

		if (target < 0)
			return;

		if (i >= arr.size())
			return;

		solve(i + 1, arr, temp, target);

		temp.push_back(arr[i]);
		solve(i, arr, temp, target - arr[i]);
		temp.pop_back();
	}

	vector<vector<int>> combinationSum(vector<int>& arr, int target)
	{
		result.clear();
		vector<int> temp;
		solve(0, arr, temp, target);
		return result;
	}
};

int main()
{
	const auto solution = make_unique<Solution>();
	vector<int> vec{ 2, 3, 5 };
	int target = 8;
	const auto result = solution->combinationSum(vec, target);
	
	for (const auto vec : result)
	{
		for (const auto num : vec)
		{
			cout << num << " ";
		}
		cout << "\n";
	}

	return 0;
}