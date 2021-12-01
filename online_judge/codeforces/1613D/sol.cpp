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
const int MAXN = 5e5 + 5;
int a[MAXN];
#define add 3

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector <vector <ll>> dp(n+10);
    for(int i = 0; i < n+10; i++)
        dp[i].resize(3);

    dp[-1 + add][0] = 1;
    ll res = 0;
    for(int i = 1; i <= n; i++){
        int x = a[i] + add;
        dp[x][0] += dp[x][0] + dp[x-1][0];
        dp[x][0] %= MOD;

        dp[x][1] += dp[x-2][0] + dp[x-2][2] + dp[x][1];
        dp[x][1] %= MOD;

        dp[x][2] += dp[x+2][1] + dp[x][2];
        dp[x][2] %= MOD;
    }
    for(int x = 0 + add; x <= n + add; x++)
        res = (res + dp[x][0] + dp[x][1] + dp[x][2])%MOD;
    cout << res << '\n';
}

int main(){
    io
    int t; cin >> t;
    while(t--){
        solve();
    }
}