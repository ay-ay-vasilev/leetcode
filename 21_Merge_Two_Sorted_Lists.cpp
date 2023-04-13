struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		if (!list1 && !list2)
			return nullptr;

		ListNode* head = new ListNode();
		ListNode* list3 = head;

		while (list1 || list2)
		{
			if (!list1)
			{
				list3->val = list2->val;
				list2 = list2->next;
			}
			else if (!list2)
			{
				list3->val = list1->val;
				list1 = list1->next;
			}
			else
			{
				if (list1->val < list2->val)
				{
					list3->val = list1->val;
					list1 = list1->next;
				}
				else
				{
					list3->val = list2->val;
					list2 = list2->next;
				}
			}

			if (list1 || list2)
			{
				list3->next = new ListNode();
				list3 = list3->next;
			}
		}
		return head;
	}
};