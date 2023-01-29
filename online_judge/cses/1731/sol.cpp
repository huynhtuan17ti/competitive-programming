#include <bits/stdc++.h>  
using namespace std;
 
const int MOD = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define mp make_pair
#define fi first
#define se second
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
const int MAXN = 3e5 + 5;

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

vector<TrieNode> TrieNode::Trie;

int main() {
	io
	string s; cin >> s;
	int k; cin >> k;
	
	TrieNode::addNewNode();
	for(int i = 0; i < k; ++i) {
		string inp; cin >> inp;
		TrieNode::addString(inp);
	}

	int n = (int)s.length();
	vector<int> dp(n+1, 0);
	dp[n] = 1;

	for(int i = n-1; i >= 0; --i) {
		int cur_index = 0;
		for(int j = i; j < n; ++j) {
			int v = s[j] - 'a';
			if(TrieNode::Trie[cur_index].child[v] == -1) break;
			cur_index = TrieNode::Trie[cur_index].child[v];
			if(TrieNode::Trie[cur_index].w_count > 0)
				dp[i] = (dp[i] + dp[j+1]) % MOD;
		}
	}
	cout << dp[0] << '\n';
}
