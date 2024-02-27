#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

class Solution
{
public:
#pragma region TwoSum
	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int> ret;
		unordered_map<int, int> um;

		for (int i = 0; i < nums.size(); ++i)
		{
			int temp = target - nums[i];
			if (um.find(temp) != um.end())
			{
				ret.push_back(i);
				ret.push_back(um[temp]);
				return ret;
			}
			um[nums[i]] = i;
		}
		return {};
	}
#pragma endregion

#pragma region IsPalindrome
	bool isPalindrome(int x) {
		if (x < 0 || (x != 0 && x % 10 == 0)) return false;

		int reverse = 0;

		while (x > reverse)
		{
			reverse = reverse * 10 + (x % 10);
			x = x / 10;
		}

		if (reverse == x || x == reverse / 10)
			return true;
		return false;
	}
#pragma endregion

#pragma region Roman to Integer
	int romanToInt(string s) {
		int ret = 0;
		unordered_map<char, int> um{
			{'I', 1},
			{'V', 5},
			{'X', 10},
			{'L', 50},
			{'C', 100},
			{'D', 500},
			{'M', 1000}
		};

		for (int i = 0; i < s.length(); i++)
		{
			// 이전 값 보다 크면
			if (um[s[i]] < um[s[i + 1]])
			{
				ret -= um[s[i]];
			}
			else
			{
				ret += um[s[i]];
			}
		}

		return ret;
	}
#pragma endregion

#pragma region Longest Common Prefix
	string longestCommonPrefix(vector<string>& strs) {	
		if (strs.empty()) return "";

		string prefix = strs[0];
		for (int i = 1; i < strs.size(); ++i)
		{
			while (strs[i].find(prefix) != 0)
			{
				prefix = prefix.substr(0, prefix.length() - 1);
			}
		}

		return prefix;
	}
#pragma endregion
};