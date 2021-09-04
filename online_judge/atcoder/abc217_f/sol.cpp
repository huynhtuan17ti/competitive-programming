#include <bits/stdc++.h>  
 
using namespace std;
 
const int MOD = 998244353;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define mp make_pair
#define fi first
#define se second
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int MAXN = 405;
 
ll dp[MAXN][MAXN];
 
int F[MAXN +  5];
 
void initialize(){
    F[0] = 1;
    for(int i = 1; i < MAXN; i++)
        F[i] = (1LL*F[i-1]*i)%MOD;
}
 
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
 
int nCk(int n, int k){
    if(n < k)
        return 0;
    // Fermat's Little Theorem
    return 1LL*F[n]*powMod(1LL*F[k]*F[n-k]%MOD, MOD-2)%MOD;
}
 
ll C[MAXN][MAXN];
 
int main(){
    io
    initialize();
    int n, m; cin >> n >> m;
    map <ii, bool> vi;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        vi[mp(u, v)] = 1;
    }
 
    for(int i = 1; i <= 2*n; i++)
        for(int j = 1; j <= i; j++){
            C[i][j] = nCk(i, j);
        }
 
    for(int i = 1; i < 2*n; i++)
        if(vi[mp(i, i+1)])
            dp[i][i+1] = 1;
    
    for(int i = 1; i <= 2*n+1; i++)
        for(int j = 1; j <= i; j++)
            dp[i][j] = 1;
 
    for(int len = 4, level = 2; len <= 2*n; len += 2, level++){
        for(int i = 1; i + len -1 <= 2*n; i++){
            int j = i + len - 1;
            for(int k = i+1; k <= j; k += 2){
                int L = (k-i-1)/2, R = (j-k)/2;
                int P = C[L+R+1][L+1];
                if(vi[mp(i, k)]){
                    dp[i][j] += dp[i+1][k-1]*dp[k+1][j]%MOD*P%MOD;
                    dp[i][j] %= MOD;
                }
            }
        }
    }
 
    cout << dp[1][2*n] << '\n';
}