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
const int MAXN = 1e7;
/*
    satisfy at least one of two conditions below:
    1. The numbers of blue bars is equal to red bars.
    2. No 2 consecutive blue bars

    Call F(N) is the number of ways satisfy condition 1, mean N must be a even number. And the answer is (N/2)C(N).
    Also, G(N) is  the numbers of ways satisfy condition 2, call M is the number of blue bars, the answer is (M)C(N-M+1)
    And P(N) is the numbers of ways satisfy both condition 1 and 2, P(N) = (N/2)C(N-N/2+1)
    P(N) can be calculated by dynamic, dp[1] = 2, dp[2] = 3 and dp[i] = dp[i-1] + dp[i-2]

    The answer if F(N) + G(N) - P(N)
*/

int F[MAXN+5];

void initialize(int n, int mod){
    F[0] = 1;
    for(int i = 1; i <= n; i++)
        F[i] = (1LL*F[i-1]*i)%mod;
}

int powMod(int a, int b, int mod){
    if(b == 0)
        return 1;
    if(b == 1)
        return a;
    int t = powMod(a, b/2, mod);
    t = 1LL*t*t%mod;
    if(b%2 == 1)
        t = 1LL*t*a%mod;
    return t;
}

int nCk(int n, int k, int mod){
    if(k > n)
        return 0;
    return 1LL*F[n]*powMod(1LL*F[n-k]*F[k]%mod, mod-2, mod)%mod;
}

int Lucas(int n, int k, int mod){
    int res = 1;
    int kr, nr;
    while(k != 0){
        nr = n%mod;
        kr = k%mod;
        res = 1LL*res*nCk(nr, kr, mod)%mod;
        n /= mod;
        k /= mod;
    }
    return res;
}

void solve(){
    int n, mod;
    cin >> n >> mod;
    initialize(n+1, mod);
    int F = 0, G = 0, P = 0;
    if(n%2 == 0){
        F = Lucas(n, n/2, mod);
        P = Lucas(n-n/2+1, n/2, mod);
    }
    vector <int> dp(n+1);
    dp[1] = 2;
    dp[2] = 3;
    for(int i = 3; i <= n; i++){
        dp[i] = (dp[i-1] + dp[i-2])%mod;
    }
    G = dp[n];
    cout << ((F+G)%mod - P + mod)%mod << '\n';
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int t; cin >> t;
    while(t--){
        solve();
    }
}