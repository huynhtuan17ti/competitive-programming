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
const int MAXN = 20;
const int inf = 2e9;
int dp[(1<<MAXN)][2];

int main() {
	io
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for(int &u: a)
		cin >> u;
	
	auto getBit = [&](int val, int bit)->bool {
		return (val >> bit) & 1;
	};

	dp[0][0] = 1; dp[0][1] = 0;
	int maxState = (1<<n)-1;
	for(int state = 1; state <= maxState; state++) {
		dp[state][1] = inf;
		dp[state][0] = n;
		for(int i = 0; i < n; i++) {
			if(!getBit(state, i))
				continue;
			int preState = (state ^ (1<<i));
			if(dp[preState][1] + a[i] > x && dp[state][0] >= dp[preState][0] + 1) {
				dp[state][1] = min(dp[state][1], a[i]);
				dp[state][0] = dp[preState][0] + 1;
			}
			if(dp[preState][1] + a[i] <= x && dp[state][0] >= dp[preState][0]) {
				dp[state][1] = min(dp[state][1], dp[preState][1] + a[i]);
				dp[state][0] = dp[preState][0];
			}
		}
	}
	cout << dp[maxState][0];
}
