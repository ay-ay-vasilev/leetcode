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
	vector<vector<int>> result;
	vector<vector<int>> levelOrder(TreeNode* root)
	{
		if (!root) return result;

		struct TreeNodeWithLevel
		{
			TreeNode* node;
			int level;
		};

		queue<TreeNodeWithLevel> nodeQueue;
		nodeQueue.push({ root, 0 });
		result.push_back({ root->val });

		while (!nodeQueue.empty())
		{
			int curLevel = nodeQueue.front().level + 1;
			TreeNode* left = nodeQueue.front().node->left;
			TreeNode* right = nodeQueue.front().node->right;

			if (left)
			{
				nodeQueue.push({ left, curLevel });
				if (result.size() < curLevel + 1)
					result.push_back({ left->val });
				else
					result[curLevel].push_back(left->val);
			}
			if (right)
			{
				nodeQueue.push({ right, curLevel });
				if (result.size() < curLevel + 1)
					result.push_back({ right->val });
				else
					result[curLevel].push_back(right->val);
			}
			nodeQueue.pop();
		}

		return result;
	}
};