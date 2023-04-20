#include "stdc++.h"

using namespace std;

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
	bool isNodeValid(TreeNode* node, long lower, long upper)
	{
		if (!node) return true;

		if (node->val >= upper) return false;
		if (node->val <= lower) return false;

		return isNodeValid(node->left, lower, node->val) && isNodeValid(node->right, node->val, upper);
	}

	bool isValidBST(TreeNode* root) {
		return isNodeValid(root, LONG_MIN, LONG_MAX);
	}
};