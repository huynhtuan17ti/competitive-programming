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

int main() {
	io
	ll n; cin >> n;
	int k; cin >> k;
	vector<ll> primes(k);
	for(ll &p: primes)
		cin >> p;
	
	// check if x1 * x2 >= y1 * y2
	auto isGreater = [&](ll x1, ll x2, ll y1, ll y2)-> bool{
		return (ld) x1 / y1 >= (ld) y2 / x2;
	};

	const int MAX_STATE = (1<<k)-1;
	vector<ll> LCM(1<<k);
	LCM[0] = 1;
	for(int state = 1; state <= MAX_STATE; ++state) {
		int most_sign_bit = 32 - __builtin_clz(state) - 1;
		int pre_state = (state^(1<<most_sign_bit));
		ll g = __gcd(LCM[pre_state], primes[most_sign_bit]);
		if(isGreater(LCM[pre_state], primes[most_sign_bit], n, g))
			LCM[state] = -1;
		else LCM[state] = LCM[pre_state] * primes[most_sign_bit] / g;
	}

	ll ans = 0;
	for(int state = 1; state <= MAX_STATE; ++state) {
		int n_bit = __builtin_popcount(state);
		
		ll lcm = LCM[state];
		if(lcm == -1) continue;

		if(n_bit%2)
			ans += n/lcm;
		else ans -= n/lcm;
	}
	cout << ans << '\n';
}
