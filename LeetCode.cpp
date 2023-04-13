#include <vector>
#include <limits>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

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

int main()
{
	vector<ListNode*> lists;

	vector<int> list0 = { 1, 4, 5 };
	vector<int> list1 = { 1, 3, 4 };
	vector<int> list2 = { 2, 6 };
	ListNode* head;
	ListNode* result;

	head = new ListNode();
	result = head;
	for (int i = 0; i < list0.size(); i++)
	{
		result->val = list0[i];
		if (i != list0.size() - 1)
		{
			result->next = new ListNode();
			result = result->next;
		}
	}
	lists.push_back(head);

	head = new ListNode();
	result = head;
	for (int i = 0; i < list1.size(); i++)
	{
		result->val = list1[i];
		if (i != list1.size() - 1)
		{
			result->next = new ListNode();
			result = result->next;
		}
	}
	lists.push_back(head);

	head = new ListNode();
	result = head;
	for (int i = 0; i < list2.size(); i++)
	{
		result->val = list2[i];
		if (i != list2.size() - 1)
		{
			result->next = new ListNode();
			result = result->next;
		}
	}
	lists.push_back(head);


	const auto test = mergeKLists(lists);

	return 0;
}