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
const int MAXN = 2e5;
 
int powMod(int a, int b){
	if(b == 0)
		return 1;
	if(b == 1)
		return a;
	int t = powMod(a, b/2);
	t = 1LL*t*t%MOD;
	if(b%2 == 1)
		t = 1LL*t*a%MOD;
	return t;
}
 
int F[2*MAXN+5];
int nCk(int n, int k){
	if(k > n)
		return 0;
	return 1LL * F[n] * powMod(1LL * F[n-k] * F[k] % MOD, MOD-2) %MOD; 
}
 
int main(){
	io
	F[0] = 1;
	for(int i = 1; i <= 2*MAXN; i++)
		F[i] = 1LL*F[i-1]*i%MOD;
	int n; cin >> n;
	vector <int> a(n+1);
	for(int &x: a)
		cin >> x;
	
	vector <int> b(MAXN+1);
	int maxValue = n;
	int j = n;
	for(int i = 1; i <= MAXN; i++){
		while(j >= 0 && a[j] < i)
			j--;
		b[i] = max(j, 0);
	}
 
	// dp[i, j] * (a[i] - j + 1)
	// i is row index, j is column index
	// => dp[i, j] * a[i] - dp[i, j] * (j - 1)
 
	// row
	ll res = a[0];
	for(int i = 1; i <= n; i++){
		res += 1LL * nCk(a[i] + i - 1, i) * a[i] % MOD;
		res %= MOD;
	}
	// col
	for(int i = 1; i <= MAXN; i++){
		res = (res - 1LL * nCk(b[i] + i - 1, i) * (i - 1) % MOD + MOD) % MOD;
	}
	cout << res << '\n';
}