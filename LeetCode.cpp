#include <iostream> 
#include <string>
#include <iostream>
#include <vector>

using namespace std;

string longestPalindrome(string s) {
	int n = s.length();
	vector<vector<int>> matrix(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
	{
		matrix[i][i] = 1;
	}
	int longestSubstrLength = 1;
	string longestSubstr(1, s[0]);
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (s[i] == s[j])
			{
				if (matrix[i + 1][j - 1] != 0 || j - i == 1)
				{
					matrix[i][j] = 1;
					if (longestSubstrLength < j - i + 1)
					{
						longestSubstrLength = j - i + 1;
						longestSubstr = s.substr(i, longestSubstrLength);
					}
				}
			}
		}
	}
	return longestSubstr;
}

int main() {
	const auto result = longestPalindrome("aacabdkacaa");
	cout << result << "\n";
	return 0;
}