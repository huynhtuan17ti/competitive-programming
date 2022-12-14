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

const int MAX_VALUE = 1e6;
int factor[MAX_VALUE + 5];

void build_sieve(){
	for(int i = 2; i <= MAX_VALUE; i++)
		factor[i] = i;
	for(int i = 4; i <= MAX_VALUE; i+=2) factor[i] = 2;
	for(int i = 3; i*i <= MAX_VALUE; i++)
		if(factor[i] == i)
			for(int j = i*i; j <= MAX_VALUE; j+=i)
				if(factor[j] == j)
					factor[j] = i;
}

ll getNumDivisors(int val) {
	unordered_map<int, int> p;
	while(val > 1) {
		p[factor[val]]++;
		val /= factor[val];
	}
	ll ans = 1;
	for(auto it: p)
		ans *= (it.se + 1);
	return ans;
}

void solve() {
	int x; cin >> x;
	cout << getNumDivisors(x) << '\n';
}

int main() {
	io
	build_sieve();
	int n; cin >> n;
	while(n--) {
		solve();
	}
}
