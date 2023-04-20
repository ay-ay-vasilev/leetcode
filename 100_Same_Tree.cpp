struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	bool checkNode(TreeNode* p, TreeNode* q)
	{
		if (!p && !q) return true;
		if (!p && q || p && !q || p->val != q->val) return false;
		return checkNode(p->left, q->left) && checkNode(p->right, q->right);
	}

	bool isSameTree(TreeNode* p, TreeNode* q) {
		return checkNode(p, q);
	}
};