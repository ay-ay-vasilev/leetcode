#include <vector>

using namespace std;

class Solution {
public:
	int uniquePaths_v0(int m, int n) {
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

	int uniquePaths(int m, int n) {
		vector<int> cur(n, 1);
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				cur[j] += cur[j - 1];
			}
		}
		return cur[n - 1];
	}
};