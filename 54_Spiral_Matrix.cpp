#include <vector>

using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> result;

		int l = 0;
		int i = 0;
		int j = 0;
		int n = matrix.size();
		int m = matrix[0].size();
		int numOfElements = n * m;

		int loops = min(n / 2, m / 2);

		while (l <= loops)
		{
			i = l;
			j = l;

			if (result.size() == numOfElements) return result;
			result.push_back(matrix[i][j]);

			if (result.size() == numOfElements) return result;
			while (j + 1 < m - l) { result.push_back(matrix[i][++j]); }

			if (result.size() == numOfElements) return result;
			while (i + 1 < n - l) { result.push_back(matrix[++i][j]); }

			if (result.size() == numOfElements) return result;
			while (j - 1 >= l) { result.push_back(matrix[i][--j]); }

			if (result.size() == numOfElements) return result;
			while (i - 1 >= l + 1) { result.push_back(matrix[--i][j]); }
			i++;

			l++;
		}

		return result;
	}
};