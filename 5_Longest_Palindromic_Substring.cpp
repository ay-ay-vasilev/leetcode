#include <string>

using namespace std;

string longestPalindrome(string s) {
	int i = 0, l = 0, r = 0, lhold = l, rhold = r, n = s.size();

	while (i < n)
	{
		l = i, r = i;
		while (r < (n - 1) && s[r] == s[r + 1]) r++;
		i = r + 1;

		while (l > 0 && r < (n - 1) && s[l - 1] == s[r + 1]) l--, r++;

		if (r - l > rhold - lhold)
		{
			lhold = l;
			rhold = r;
		}
	}
	return s.substr(lhold, rhold - lhold + 1);
}