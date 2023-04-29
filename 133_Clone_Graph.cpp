#include "stdc++.h"

using namespace std;

class Node {
public:
	int val;
	vector<Node*> neighbors;
	Node() {
		val = 0;
		neighbors = vector<Node*>();
	}
	Node(int _val) {
		val = _val;
		neighbors = vector<Node*>();
	}
	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};

class Solution {
public:
	vector<Node*> visits = vector<Node*>(101, nullptr);
	Node* clone(Node* node)
	{
		if (visits[node->val] != nullptr)
		{
			return visits[node->val];
		}

		Node* result = new Node(node->val);
		visits[node->val] = result;

		if (node->neighbors.empty()) return result;

		vector<Node*> clonedNeighbors;
		for (Node* neighbor : node->neighbors)
		{
			if (visits[neighbor->val]) clonedNeighbors.push_back(visits[neighbor->val]);
			else clonedNeighbors.push_back(clone(neighbor));
		}

		result->neighbors = clonedNeighbors;
		return result;
	}

	Node* cloneGraph(Node* node)
	{
		if (!node) return nullptr;
		return clone(node);
	}
};