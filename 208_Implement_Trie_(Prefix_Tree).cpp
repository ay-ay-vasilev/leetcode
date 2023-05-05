#include "stdc++.h"

using namespace std;

class TrieV0 {
public:
	TrieV0() {
	}

	void insert(string word) {
		dictionary[word] = 1;
	}

	bool search(string word) {
		if (dictionary.count(word))
			return true;
		return false;
	}

	bool startsWith(string prefix) {
		for (auto& [entry, value] : dictionary)
		{
			if (entry.substr(0, prefix.length()) == prefix)
				return true;
		}
		return false;
	}

	unordered_map<string, int> dictionary;
};

class TrieV1 {
public:
	struct TrieNode {
		TrieNode* child[26];
		bool isEnd;
		TrieNode() {
			isEnd = false;
			for (int i = 0; i < 26; i++)
				child[i] = NULL;
		}
	};
	TrieNode* root;
	TrieV1() {
		root = new TrieNode();
	}

	void insert(string word) {
		TrieNode* curr = root;
		for (int i = 0; i < word.length(); i++) {
			int index = word[i] - 'a';
			if (curr->child[index] == NULL)
				curr->child[index] = new TrieNode();
			curr = curr->child[index];
		}
		curr->isEnd = true;
	}

	bool search(string word) {
		TrieNode* curr = root;
		for (int i = 0; i < word.length(); i++) {
			int index = word[i] - 'a';
			if (curr->child[index] == NULL)
				return false;
			curr = curr->child[index];
		}
		return curr->isEnd;

	}

	bool startsWith(string prefix) {
		TrieNode* curr = root;
		for (int i = 0; i < prefix.length(); i++) {
			int index = prefix[i] - 'a';
			if (curr->child[index] == NULL)
				return false;
			curr = curr->child[index];
		}
		return true;
	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */