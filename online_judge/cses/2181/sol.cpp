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
const int MAXN = 10;

int dp[1 << MAXN][2];

int main() {
	io
	int n, m;
	cin >> n >> m;

	auto getBit = [&](int val, int bit)-> bool {
		return (val>>bit)&1;
	};

	const int max_state = (1 << n);
	dp[0][0] = 1;
	for(int j = 1; j <= m; ++j) for(int i = 0; i < n; ++i) {
		for(int state = 0; state < max_state; ++state) {
			if(!getBit(state, i)) { // bit = 0 -> covered
				dp[state][1] += dp[state ^ (1 << i)][0]; // horizontal tile
				if(i && !(state & (1 << (i - 1)))) // vertical tile
					dp[state][1] += dp[state ^ (1 << (i - 1))][0];
			}else { // empty
				dp[state][1] += dp[state ^ (1 << i)][0];
			}
			if(dp[state][1] >= MOD) dp[state][1] -= MOD;
		}
		for(int state = 0; state < max_state; ++state) {
			dp[state][0] = dp[state][1];
			dp[state][1] = 0;
		}
	}
	cout << dp[0][0] << '\n';
}
