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

const int MAX_VALUE = 1e6;
int factor[MAX_VALUE + 5];

void buildSieve(){
	for(int i = 2; i <= MAX_VALUE; i++)
		factor[i] = i;
	for(int i = 4; i <= MAX_VALUE; i+=2) factor[i] = 2;
	for(int i = 3; i*i <= MAX_VALUE; i++)
		if(factor[i] == i)
			for(int j = i*i; j <= MAX_VALUE; j+=i)
				if(factor[j] == j)
					factor[j] = i;
}

vector<int> getPrimeFactor(int x) {
	vector<int> pf;
	while(x > 1) {
		int p = factor[x];
		pf.push_back(p);
		while(x % p == 0) x /= p;
	}
	return pf;
}

int main() {
	io
	buildSieve();
	int n; cin >> n;

	ll ans = 0;
	
	vector<int> cnt(MAX_VALUE+1);
	auto calc = [&](int x) {
		vector<int> pf = getPrimeFactor(x);
		int k = (int)pf.size();
		const int MAX_STATE = (1<<k)-1;
		for(int state = 1; state <= MAX_STATE; ++state) {
			int mul = 1, n_bit = __builtin_popcount(state);
			for(int i = 0; i < k; ++i) if((state>>i)&1) mul *= pf[i];
			if(n_bit%2) ans += cnt[mul];
			else ans -= cnt[mul];
			cnt[mul]++;
		}
	};

	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		calc(x);
	}
	cout << 1LL*n*(n-1)/2 - ans << '\n';
}
