#include "stdc++.h"

using namespace std;

class Solution {
public:
	vector<vector<char>> matrix;
	string targetWord = "";
	int n, m;

	bool solve(int i, int j, int letterNum)
	{
		if (letterNum == targetWord.size())
			return true;

		if (i < 0 || i >= n || j < 0 || j >= m || matrix[i][j] != targetWord[letterNum])
			return false;

		letterNum++;
		char temp = matrix[i][j];
		matrix[i][j] = '*';

		bool result =
			solve(i - 1, j, letterNum) ||
			solve(i + 1, j, letterNum) ||
			solve(i, j - 1, letterNum) ||
			solve(i, j + 1, letterNum);
		matrix[i][j] = temp;
		return result;

	}

	bool exist(vector<vector<char>>& board, string word)
	{
		n = board.size();
		m = board[0].size();
		targetWord = word;
		matrix = board;

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (solve(i, j, 0)) return true;
		return false;
	}
};