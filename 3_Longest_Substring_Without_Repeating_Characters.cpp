#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_set<char> subString;
		int left = 0;
		int right = 0;
		int result = 0;
		while (left < s.length() && right < s.length())
		{
			if (subString.find(s[right]) == subString.end())
			{
				subString.insert(s[right]);
				right++;
				if (result < right - left) result = right - left;
			}
			else
			{
				subString.erase(s[left++]);
			}
		}
		return result;
	}
};