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
		unordered_map<char, int> um
		{
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
			// ���� �� ���� ũ��
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

#pragma region Valid Parentheses
	bool isValid(string s) {
		if (s.length() == 1) return false;

		unordered_map<char, char> um
		{
			{')' ,'('},
			{'}', '{'},
			{']', '['}
		};

		stack<char> st;
		for (auto c : s)
		{
			if (st.empty())
			{
				st.push(c);
			}
			else
			{
				if (um.find(c) != um.end())
				{
					char temp = st.top();
					st.pop();
					if (temp != um[c])
					{
						return false;
					}
				}
				else
				{
					st.push(c);
				}
			}
		}

		if (st.empty() == false)
			return false;

		return true;
	}
#pragma endregion

#pragma region Merge Two Sorted Lists
	struct ListNode {
		int val;
		ListNode* next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode* next) : val(x), next(next) {}
	};

	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		ListNode* ret = new ListNode();
		ListNode* pret = ret;

		if (list1 == nullptr) return list2;
		if (list2 == nullptr) return list1;

		while (list1 != nullptr && list2 != nullptr)
		{
			int val1 = list1->val;
			int val2 = list2->val;

			if (val1 <= val2)
			{
				pret->next = list1;
				list1 = list1->next;
			}
			else
			{
				pret->next = list2;
				list2 = list2->next;
			}
			pret = pret->next;
		}

		if (list1 != nullptr)
		{
			pret->next = list1;
		}
		if (list2 != nullptr)
		{
			pret->next = list2;
		}

		return ret->next;
	}
#pragma endregion

# pragma region Remove Duplicates from sorted array
	int removeDuplicates(vector<int>& nums) {
		int prevNum = nums[0];
		vector<int> temp { prevNum };

		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] != prevNum)
			{
				temp.push_back(nums[i]);
				prevNum = nums[i];
			}
		}

		nums = temp;
		return temp.size();
	}
#pragma endregion

#pragma region Remove Element
	int removeElement(vector<int>& nums, int val) {
		int temp = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] != val)
			{
				nums[temp] = nums[i];
				temp++;
			}
		}
		return temp;
	}
#pragma endregion

#pragma region Find the Index of the First Occurrence in a String
	int strStr(string haystack, string needle) {
        int index = 0;
		int needleLength = needle.length();

		for (int i = 0; i < haystack.length(); i++)
		{
			string substr = haystack.substr(i, needleLength);
			if (substr == needle)
			{
				return i;
			}
		}
		return -1;
    }
#pragma endregion

#pragma region Search Insert Position
int searchInsert(vector<int>& nums, int target) {
        int ret = 0;
		if (target < nums[0]) return 0;

		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == target)
			{
				return ret;
			}
			else
			{
				if (i < nums.size() - 1 &&
					nums[i] < target && nums[i+1] >= target)
				{
					return ++ret;
				}
			}
			++ret;
		}
		return ret;
    }
#pragma endregion

/// TOP Interview 150
#pragma region Merge Sorted Array
void mergesortedarray(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	if (m == 0)
	{
		nums1 = nums2;
		return;
	}

	vector<int> temp;
	for (int i = 0; i < m; i++)
	{
		temp.push_back(nums1[i]);
	}
	for (int i = 0; i < n; i++)
	{
		temp.push_back(nums2[i]);
	}
	sort(temp.begin(), temp.end());
	nums1 = temp;
}
#pragma endregion

#pragma region Reove Duplicates form Array II
int removeDuplicatesII(vector<int>& nums) {
	int p1 = 0;
	if (nums.size() <= 1)
		return 1;

	for (int i = 0; i < nums.size(); i++)
	{
		if (p1 - 2 >= 0 && nums[p1 - 2] == nums[i])
		{
			continue;
		}
		nums[p1] = nums[i];
		p1++;
	}
	return p1;
}
#pragma endregion

#pragma region Majority Element
int majorityElement(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	unordered_map<int, int> m;

	for (int i = 0; i < nums.size(); i++)
	{
		m[nums[i]]++;
	}

	int moreHalf = nums.size() / 2;
	for (auto i : m)
	{
		if (i.second > moreHalf)
			return i.first;
	}

	return 0;
}
#pragma endregion

#pragma region Rotate Array
void rotate(vector<int>& nums, int k) {
	queue<int> q;
	
	for (int i = nums.size() - 1; i >= 0; i--)
	{
		q.push(nums[i]);
	}

	for (int i = 0; i < k; i++)
	{
		int temp = q.front();
		q.pop();
		q.push(temp);
	}

	for (int i = nums.size() - 1; i >= 0; i--)
	{
		nums[i] = q.front();
		q.pop();
	}
}
#pragma endregion


};