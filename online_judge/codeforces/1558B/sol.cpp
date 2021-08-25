#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define mp make_pair
#define fi first
#define se second
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int MAXN = 5e6 + 5;
ll MOD;

ll dp[MAXN];
ll bonus[MAXN];

void solve(){
    int n, m;
    cin >> n >> m;
    MOD = m;
    ll sum = 1;
    dp[1] = 1;

    for(int k = 2; k <= n; k++){
        if(k > n)
            break;
        bonus[k] += 1;
        bonus[min(n+1, k*2)] = (bonus[min(n+1, k*2)] - 1 + MOD)%MOD;
    }

    for(int i = 2; i <= n; i++){
        bonus[i] = (bonus[i] + bonus[i-1])%MOD;
        dp[i] = (dp[i] + sum)%MOD;
        dp[i] = (dp[i] + bonus[i])%MOD;
        sum = (sum + dp[i])%MOD;
        
        for(int k = 2; k <= n; k++){
            if(k*i > n)
                break;
            bonus[k*i] = (bonus[k*i] + dp[i])%MOD;
            bonus[min(n+1, k*i + k)] = (bonus[min(n+1, k*i + k)] - dp[i] + MOD)%MOD;
        }
    }
    cout <<  dp[n] << '\n';
}

int main(){
    io
    int t; t = 1;
    while(t--){
        solve();
    }
}