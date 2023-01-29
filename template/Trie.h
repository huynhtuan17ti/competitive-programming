#include <bits/stdc++.h>
using namespace std;

const int NUM_ALPHABET = 27;
struct TrieNode {
	int w_count; // word counting
	int index;
	int child[NUM_ALPHABET];

	static vector<TrieNode> Trie;
	
	TrieNode() {
		w_count = 0;
		for(int i = 0; i < NUM_ALPHABET; ++i)
			child[i] = -1;
		index = (int)Trie.size();
	}

	static void addNewNode() {
		TrieNode new_node;
		Trie.emplace_back(new_node);
	}

	static void addString(string s) {
		int cur_index = 0;
		for(int i = 0; i < (int)s.length(); ++i) {
			int v = s[i] - 'a';
			if(Trie[cur_index].child[v] == -1) {
				addNewNode();
				Trie[cur_index].child[v] = (int)Trie.size() - 1;
			}
			cur_index = Trie[cur_index].child[v];
		}
		++Trie[cur_index].w_count;
	}
};