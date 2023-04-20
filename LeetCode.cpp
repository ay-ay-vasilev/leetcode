#include "stdc++.h"

using namespace std;

class Solution {
public:
	vector<vector<char>> matrix;
	string targetWord = "";
	int n, m;

	string minWindow(string s, string t) {
		unordered_map<char, int> windowHashTable;
		int left = 0, count = 0, minSubsLeft = 0, minSubsLen = INT_MAX;
		for (const auto& l : t) { ++windowHashTable[l]; }
		bool isWindowHashTableBigger = false;

		for (int right = 0; right < s.length(); ++right)
		{
			if (windowHashTable[s[right]]-- > 0) count++;
			if (count == t.length())
			{
				while (left < right && windowHashTable[s[left]] < 0) { ++windowHashTable[s[left++]]; }
				if (right - left + 1 < minSubsLen) { minSubsLen = right - left + 1; minSubsLeft = left; }
			}
		}
		return minSubsLen == INT_MAX ? "" : s.substr(minSubsLeft, minSubsLen);
	}
};

int main()
{
	const auto solution = make_unique<Solution>();

	cout << "Hello world!";

	return 0;
}