#include "stdc++.h"

using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		if (s[0] == '0') return 0;
		if (s.size() == 1) return 1;

		int n = s.size();
		vector<int> v(n, 0);

		v[0] = 1;
		v[1] = (s[0] == '1' || s[0] == '2' && s[1] < '7' ? 1 : 0) + (s[1] != '0');

		for (int i = 2; i < n; ++i)
		{
			if (s[i] == '0' && (s[i - 1] > '2' || s[i - 1] == '0')) return 0;
			v[i] = s[i] != '0' ? v[i - 1] : 0;
			if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] < '7') v[i] += v[i - 2];
		}

		return v[n - 1];
	}
};