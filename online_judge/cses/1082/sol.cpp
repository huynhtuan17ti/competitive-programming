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

const int TWO_MOD_INV = 500000004;

int main() {
	io
	ll n; cin >> n;
	ll cur = 1, ans = 0;
	auto sum = [&](ll k) -> ll{
		k %= MOD;
		return k * (k + 1) % MOD * TWO_MOD_INV % MOD;
	};
	auto sumRange = [&](ll l, ll r) -> ll {
		return (sum(r) - sum(l - 1) + MOD) % MOD;
	};
	/* ans = sum((n/i) * i) with i from 1 to n
	 * Harmonic Lemma shows that there are at most 2 * sqrt(n) different [n/d] */
	while(cur <= n) {
		ll n_d =  n / cur;
		ll last_same = n / n_d;
		ans = (ans + (n_d % MOD) * sumRange(cur, last_same) % MOD) % MOD;
		cur = last_same + 1;
	}
	cout << ans << '\n';
}
