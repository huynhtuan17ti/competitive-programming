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
const ll MODSHIT = 1e15;
const int MAXN = 5005;
const ll INF = 1e14;

ll dp[MAXN][MAXN];

int main(){
    io
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int n, k; cin >> n >> k;
    vector <int> a(n+1);
    vector <ll> sum(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }
    vector <ll> preDp(n+1, -INF);
    dp[0][0] = 0;
    for(int p = 1; p <= k; p++)
        dp[0][p] = -INF;
    preDp[0] = 0;
    for(int i = 1; i <= n; i++){
        for(int p = k; p >= 1; p--){
            dp[i][p] = dp[i-1][p];
            //cout << i << ' ' << p << ' ' << sum[i] << ' ' << preDp[p-1] << '\n';
            dp[i][p] = max(dp[i][p], sum[i] + preDp[p-1]);
   
            if(dp[i][p] != -INF)
                preDp[p] = max(preDp[p], dp[i][p] - sum[i]);
        }
        preDp[0] = max(preDp[0], -sum[i]);
    }

    cout << dp[n][k] << '\n';
}