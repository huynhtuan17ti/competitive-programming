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

int getNumDivisors(const vii &p) {
	int res = 1;
	for(auto [u, v]: p) {
		res = 1LL * res * (v + 1) % MOD;
	}
	return res;
}

int getSumDiviors(const vii &p) {
	int res = 1;
	for(auto [u, v]: p) {
		int cur = 1LL * (powMod(u, v+1) - 1) * powMod(u-1, MOD - 2) % MOD;
		res = 1LL * res * cur % MOD;
	}
	return res;
}

int getProdDivisors(const vii &p) {
	int res = 1;
	int cur_num_divisors = 1;
	for(auto [u, v]: p) {
		int sum_v = 1LL * v * (v + 1) / 2 % (MOD - 1);
		res = 1LL * powMod(res, v + 1) * powMod(powMod(u, sum_v), cur_num_divisors) % MOD;
		cur_num_divisors = 1LL * cur_num_divisors * (v + 1) % (MOD - 1);
	}
	return res;
}

int main() {
	io
	int n; cin >> n;
	vii p(n);
	for(auto &[u, v]: p)
		cin >> u >> v;
	cout << getNumDivisors(p) << ' ' << getSumDiviors(p) << ' ' << getProdDivisors(p) << '\n';
}
