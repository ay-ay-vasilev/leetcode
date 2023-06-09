#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		if (matrix.empty()) return;

		int m = matrix.size(), n = matrix[0].size();
		bool zeroFirstRow = false, zeroFirstCol = false;

		if (matrix[0][0] == 0) { zeroFirstRow = true; zeroFirstCol = true; }
		else
		{
			for (int i = 0; i < m; ++i) if (matrix[i][0] == 0) { zeroFirstCol = true; }
			for (int j = 0; j < n; ++j) if (matrix[0][j] == 0) { zeroFirstRow = true; }
		}


		for (int i = 1; i < m; ++i) for (int j = 1; j < n; ++j)
			if (matrix[i][j] == 0) { matrix[0][j] = 0; matrix[i][0] = 0; }

		for (int i = 1; i < m; ++i) for (int j = 1; j < n; ++j)
			if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;

		if (zeroFirstCol) for (int i = 0; i < m; ++i) matrix[i][0] = 0;
		if (zeroFirstRow) for (int j = 0; j < n; ++j) matrix[0][j] = 0;
	}
};