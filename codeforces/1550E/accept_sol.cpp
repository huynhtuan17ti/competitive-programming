#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int n, k;
string s;

bool check(int d){
	vector<int> lst(k, n);
	vector<vector<int>> pos(n + 1, vector<int>(k, n + 1));
	for (int i = n - 1; i >= 0; --i){
		if (s[i] != '?'){
			lst[s[i] - 'a'] = i;
		}
		int cur = n;
		forn(j, k){
			pos[i][j] = (i + d <= cur ? i + d : pos[i + 1][j]);
			cur = min(cur, lst[j]);
		}
		cur = n;
		for (int j = k - 1; j >= 0; --j){
			if (i + d > cur) pos[i][j] = pos[i + 1][j];
			cur = min(cur, lst[j]);
		}
	}
	vector<int> dp(1 << k, n + 1);
	dp[0] = 0;
	forn(mask, 1 << k) if (dp[mask] < n + 1){
		forn(i, k) if (!((mask >> i) & 1))
			dp[mask | (1 << i)] = min(dp[mask | (1 << i)], pos[dp[mask]][i]);
	}
	return dp[(1 << k) - 1] <= n;
}

int main() {
    freopen("test.inp", "r", stdin);
    freopen("test.ans", "w", stdout);
	cin >> n >> k;
	cin >> s;
	int l = 1, r = n;
	int res = 0;
	while (l <= r){
		int m = (l + r) / 2;
		if (check(m)){
			res = m;
			l = m + 1;
		}
		else{
			r = m - 1;
		}
	}
	cout << res << endl;
	return 0;
}