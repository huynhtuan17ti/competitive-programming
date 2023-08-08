#include <bits/stdc++.h>  
using namespace std;
 
constexpr int MOD = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define mp make_pair
#define fi first
#define se second
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};
constexpr int MAXN = 1e6;

int F[2*MAXN+5];

int powMod(int a, int b, int mod = MOD) {
    if(b == 0)	return 1;
    if(b == 1)	return a;

    int t = powMod(a, b/2, mod);
    t = 1LL * t * t % mod;
    if(b%2)
        t = 1LL * t * a % mod;
    return t;
}

int nCk(int n, int k) {
    if(k > n) return 0;
    return 1LL * F[n] * powMod(1LL * F[k] * F[n-k] % MOD, MOD - 2) % MOD;
}

int main() {
    io
    F[0] = 1;
    for(int i = 1; i <= 2*MAXN; ++i)
        F[i] = (1LL * F[i-1] * i) % MOD;
    int N, X, Y;
    cin >> N >> X >> Y;

    ll ans = 0;
    for(int l = 1; l <= N; ++l) {
        int tX = N - X * l, tY = N - Y * l;
        if(tX < 0 || tY < 0) break;
        int cur_res = 1LL * nCk(tX + l - 1, l - 1) * nCk(tY + l - 1, l - 1) % MOD; 
        ans = (ans + cur_res) % MOD;
    }
    cout << ans << '\n';
}
