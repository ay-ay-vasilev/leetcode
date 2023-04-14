#include <vector>
#include <memory>
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

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

int main()
{
	const auto solution = make_unique<Solution>();
	vector<string> vec{ "eat","tea","tan","ate","nat","bat" };
	const auto result = solution->groupAnagrams(vec);

	for (const auto& vec : result)
	{
		for (const auto& el : vec)
			cout << el << " ";
		cout << "\n";
	}

	return 0;
}