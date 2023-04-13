#include <vector>
#include <limits>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.size() == 0) return nullptr;

		bool allNull = true;
		for (const auto& list : lists)
		{
			if (!list)
				continue;
			allNull = false;
			break;
		}
		if (allNull) return nullptr;

		ListNode* head = new ListNode();
		ListNode* result = head;
		vector<int> nonNullLists;

		while (true)
		{
			nonNullLists.clear();
			for (int i = 0; i < lists.size(); i++)
				if (lists[i]) nonNullLists.push_back(i);

			if (nonNullLists.empty())
				break;

			int minVal = INT_MAX;
			int minIndex = 0;
			for (const auto& listIndex : nonNullLists)
			{
				if (lists[listIndex]->val < minVal)
				{
					minVal = lists[listIndex]->val;
					minIndex = listIndex;
				}
			}
			result->val = minVal;
			lists[minIndex] = lists[minIndex]->next;

			if (nonNullLists.size() == 1 && lists[minIndex] == nullptr)
			{
				break;
			}
			result->next = new ListNode();
			result = result->next;

		}
		return head;
	}
};