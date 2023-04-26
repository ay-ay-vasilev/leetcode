#include "stdc++.h"

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	bool hasCycle(ListNode* head) {
		while (head && head->val != INT_MAX)
		{
			head->val = INT_MAX;
			head = head->next;
		}
		if (head) return true;
		return false;
	}
};