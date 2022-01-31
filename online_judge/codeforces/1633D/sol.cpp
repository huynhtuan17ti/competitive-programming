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
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
const int MAXN = 1000;
 
int G[MAXN + 5];
 
void prepare(){
	fill(G, G+MAXN+1, 1000000);
	G[1] = 0;
	for(int i = 1; i <= MAXN; i++)
		for(int x = 1; x <= i; x++)
			if(i + (i/x) <= MAXN)
				G[i + (i/x)] = min(G[i + (i/x)], G[i] + 1);
 
	int maxValue = 0;
	for(int i = 1; i <= MAXN; i++)
		maxValue = max(maxValue, G[i]);
	//cout << maxValue << '\n';
}
 
void solve(){
	int n, k;
	cin >> n >> k;
	vector <int> b(n+1);
	for(int i = 1; i <= n; i++)
		cin >> b[i];
	vector <int> c(n+1);
	for(int i = 1; i <= n; i++)
		cin >> c[i];
	k = min(k, 15*n);
	vector <vector <ll>> dp(n+1, vector <ll> (k+1, 0));
	dp[0][0] = 0;
 
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= k; j++)
			dp[i][j] = dp[i-1][j];
		for(int j = k; j >= G[b[i]]; j--){
			dp[i][j] = max(dp[i][j], dp[i-1][j-G[b[i]]] + c[i]);
		}
	}
 
	ll ans = 0;
	for(int p = 0; p <= k; p++)
		ans = max(ans, dp[n][p]);
	cout << ans << '\n';
}
 
int main(){
	io
	prepare();
	int t; cin >> t;
	while(t--){
		solve();
	}
}