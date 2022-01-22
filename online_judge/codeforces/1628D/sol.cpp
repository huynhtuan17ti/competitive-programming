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
const int MAXN = 2005;

int powMod(int a, int b){
    if(b == 0)
        return 1;
    if(b == 1)
        return a;
    int t = powMod(a, b/2);
    t = (1LL*t*t)%MOD;
    if(b%2 == 1)
        t = (1LL*t*a)%MOD;
    return t;
}

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    int div2 = powMod(2, MOD-2);
    vector <vector <ll>> dp(n+1, vector <ll> (m+1));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= min(i, m); j++){
            if(i == j)
                dp[i][j] = 1LL*i*k % MOD;
            else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) * div2 % MOD;
        }
    cout << dp[n][m] << '\n';
}   

int main(){
    io
    int t; cin >> t;
    while(t--){
        solve();
    }
}