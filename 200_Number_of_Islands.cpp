#include "stdc++.h"

using namespace std;

class Solution {
public:
	void checkIsland(vector<vector<char>>& grid, int i, int j)
	{
		int n = grid.size(), m = grid[0].size();

		if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '0')
			return;

		grid[i][j] = '0';

		checkIsland(grid, i - 1, j);
		checkIsland(grid, i + 1, j);
		checkIsland(grid, i, j - 1);
		checkIsland(grid, i, j + 1);
	}

	int numIslands(vector<vector<char>>& grid)
	{
		int n = grid.size(), m = grid[0].size();
		int result = 0;

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (grid[i][j] == '1')
				{
					++result;
					checkIsland(grid, i, j);
				}
			}
		}
		return result;
	}
};