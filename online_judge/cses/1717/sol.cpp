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

int powMod(int a, int b, int mod = MOD) {
	if(b == 0)	return 1;
	if(b == 1)	return a;

	int t = powMod(a, b/2, mod);
	t = 1LL * t * t % mod;
	if(b%2)
		t = 1LL * t * a % mod;
	return t;
}

int main() {
	io
	int n; cin >> n;
	vector<int> f(n+1);
	f[0] = 1;
	for(int i = 1; i <= n; ++i)
		f[i] = 1LL * f[i-1] * i % MOD;
	
	// derangement formula
	ll ans = 0;
	for(int i = 0; i <= n; i++) {
		if(i%2) ans -= powMod(f[i], MOD - 2);
		else ans += powMod(f[i], MOD - 2);
		ans = (ans + MOD) % MOD;
	}
	ans = ans * f[n] % MOD;
	cout << ans << '\n';
}
