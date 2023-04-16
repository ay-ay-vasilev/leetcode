#include <vector>
#include <memory>
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> matrix(m, vector<int>(n, 0));

		matrix[0] = vector<int>(n, 1);
		for (int i = 1; i < m; ++i) matrix[i][0] = 1;

		int sum = 0;
		for (int i = 1; i < m; ++i)
		{
			for (int j = 1; j < n; ++j)
			{
				matrix[i][j] += matrix[i - 1][j] + matrix[i][j - 1];
			}
		}
		return matrix[m - 1][n - 1];
	}
};

int main()
{
	const auto solution = make_unique<Solution>();
	const auto result = solution->uniquePaths(3, 7);

	cout << result;

	return 0;
}