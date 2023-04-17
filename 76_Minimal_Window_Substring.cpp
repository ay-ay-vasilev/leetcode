#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
	string minWindow_v0(string s, string t) {
		string result = "";
		unordered_map<char, int> targetHashTable, windowHashTable;
		unordered_set<char> targetSet, windowSet;
		int left = 0, right = 0, m = s.size(), n = t.size();
		char newLetter = s[0];
		for (const auto& l : t) { ++targetHashTable[l]; targetSet.insert(l); }
		bool isWindowHashTableBigger = false;

		while (right < m)
		{
			newLetter = s[right];
			if (targetHashTable.find(newLetter) != targetHashTable.end())
			{
				windowSet.insert(newLetter);
				++windowHashTable[newLetter];

				while (left < right)
				{
					newLetter = s[left];
					if (targetHashTable.find(newLetter) == targetHashTable.end()) { ++left; continue; }
					if (windowHashTable[newLetter] > targetHashTable[newLetter])
					{
						--windowHashTable[newLetter];
						if (windowHashTable.find(newLetter) == windowHashTable.end())
							windowSet.erase(newLetter);
						++left;
						continue;
					}
					break;
				}
			}
			if (targetSet == windowSet)
			{
				isWindowHashTableBigger = true;
				for (const auto& letter : targetSet)
				{
					if (windowHashTable[letter] < targetHashTable[letter])
					{
						isWindowHashTableBigger = false;
						break;
					}
				}

				if (isWindowHashTableBigger && (result.empty() || result.size() > (right - left + 1)))
					result = s.substr(left, right - left + 1);
			}
			++right;
		}
		return result;
	}

	string minWindow_v1(string s, string t) {
		unordered_map<char, int> windowHashTable;
		int left = 0, subsLeft = 0, right = 0, count = 0, minSubsLen = INT_MAX;
		for (const auto& l : t) { ++windowHashTable[l]; }
		bool isWindowHashTableBigger = false;

		while (right < s.length())
		{
			if (windowHashTable[s[right]] > 0) count++;
			--windowHashTable[s[right]];
			if (count == t.length())
			{
				while (left < right && windowHashTable[s[left]] < 0) { ++windowHashTable[s[left++]]; }
				if (right - left + 1 < minSubsLen) { minSubsLen = right - left + 1; subsLeft = left; }
			}
			++right;
		}
		return minSubsLen == INT_MAX ? "" : s.substr(subsLeft, minSubsLen);
	}

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

