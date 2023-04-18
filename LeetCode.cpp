#include "stdc++.h"

using namespace std;

class Solution {
public:
	vector<vector<char>> matrix;
	string targetWord = "";
	int n, m;

	bool solve(int i, int j, int letterNum, vector<vector<int>> visits)
	{
		if (letterNum == targetWord.size())
			return true;

		if (i < 0 || i >= n || j < 0 || j >= m)
			return false;


		if (matrix[i][j] != targetWord[letterNum] || visits[i][j])
			return false;

		letterNum++;
		char temp = matrix[i][j];
		matrix[i][j] = '*';
		visits[i][j] = 1;

		bool result = solve(i - 1, j, letterNum, visits) || solve(i + 1, j, letterNum, visits) || solve(i, j - 1, letterNum, visits) || solve(i, j + 1, letterNum, visits);
		matrix[i][j] = temp;
		return result;

	}

	bool exist(vector<vector<char>>& board, string word)
	{
		n = board.size();
		m = board[0].size();
		targetWord = word;
		matrix = board;

		vector<vector<int>> visits(n, vector<int>(m, 0));

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (solve(i, j, 0, visits)) return true;
		return false;
	}
};

int main()
{
	const auto solution = make_unique<Solution>();

	vector<vector<char>> board
	{
		{'A', 'A', 'A', 'A', 'A', 'A'},
		{'A', 'A', 'A', 'A', 'A', 'A'},
		{'A', 'A', 'A', 'A', 'A', 'A'},
		{'A', 'A', 'A', 'A', 'A', 'A'},
		{'A', 'A', 'A', 'A', 'A', 'B'},
		{'A', 'A', 'A', 'A', 'B', 'A'}
	};
	string target = "AAAAAAAAAAAAABB";

	const auto result = solution->exist(board, target);

	cout << result;

	return 0;
}