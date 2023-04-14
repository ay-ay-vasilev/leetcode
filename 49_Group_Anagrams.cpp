#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs)
	{
		unordered_map<string, vector<string>> map;
		for (const auto& str : strs)
		{
			auto sortedStr = str;
			sort(sortedStr.begin(), sortedStr.end());
			map[sortedStr].push_back(str);
		}

		vector<vector<string>> result;
		for (const auto& sortedStr : map)
		{
			result.push_back(map[sortedStr.first]);
		}

		return result;
	}
};