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
	int solve(TreeNode* node, int depth)
	{
		if (!node) return depth;

		int left = 0, right = 0;

		if (node->left) left = solve(node->left, depth + 1);
		if (node->right) right = solve(node->right, depth + 1);
		return max(max(left, right), depth + 1);
	}

	int maxDepth_v0(TreeNode* root) {
		return solve(root, 0);
	}

	int maxDepth(TreeNode* root) {
		if (!root) return 0;
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
};