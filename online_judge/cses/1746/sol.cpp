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
const int MAXN = 5e5 + 5;

int main(){
    io
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector <int> a(n+2);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    
    vector <vector <ll>> dp(n+1, vector <ll> (m+2));
    if(a[1] == 0)
        for(int j = 1; j <= m; j++)
            dp[1][j] = 1;
    else dp[1][a[1]] = 1;

    for(int i = 2; i <= n; i++){
        if(a[i] > 0){
            dp[i][a[i]] = (dp[i-1][a[i] - 1] + dp[i-1][a[i]] + dp[i-1][a[i] + 1])%MOD;
            continue;
        }
        for(int j = 1; j <= m; j++)
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1] + dp[i-1][j]) % MOD;
    }

    ll res = 0;
    for(int j = 1; j <= m; j++)
        res = (res + dp[n][j]) % MOD;
    cout << res << '\n';
}