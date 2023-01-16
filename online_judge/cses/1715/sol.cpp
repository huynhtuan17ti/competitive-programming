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
const int MAX_VAL = 1e6;
int f[MAX_VAL+1];

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
	f[0] = 1;
	for(int i = 1; i <= MAX_VAL; i++)
		f[i] = 1LL * f[i-1] * i % MOD;
	string s; cin >> s;
	int n = s.length();
	vector<int> cnt(30);
	for(char ch: s)
		cnt[ch - 'a']++;
	
	int nu = f[n];
	int de = 1;
	for(int ch = 0; ch < 26; ch++)
		de = 1LL * de * f[cnt[ch]] % MOD;
	
	cout << 1LL * nu * powMod(de, MOD - 2) % MOD << '\n';
}
