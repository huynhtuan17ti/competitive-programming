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
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector <vector <ll>> a(n+1, vector <ll> (m+1));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];
    
    vector<vector<vector <ll>>> dp(n+2, vector <vector<ll>> (m+2, vector<ll> (2)));
    for(int j = 1; j <= m; j++)
        dp[1][j][0] = max(a[1][j], dp[1][j-1][0] + a[1][j]);
    for(int j = m; j >= 1; j--)
        dp[1][j][1] = max(a[1][j], dp[1][j+1][1] + a[1][j]);
    
    for(int i = 2; i <= n; i++){
        dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][1][1]) + a[i][1];
        dp[i][m][1] = max(dp[i-1][m][0], dp[i-1][m][1]) + a[i][m];
        for(int j = 2; j <= m; j++){
            dp[i][j][0] = max(max(dp[i-1][j][0], dp[i-1][j][1]) + a[i][j], dp[i][j-1][0] + a[i][j]);
        }
        for(int j = m-1; j >= 1; j--){
            dp[i][j][1] = max(max(dp[i-1][j][0], dp[i-1][j][1]) + a[i][j], dp[i][j+1][1] + a[i][j]);
        }
    }

    ll res = LLONG_MIN;
    for(int j = 1; j <= m; j++)
        res = max({res, dp[n][j][0], dp[n][j][1]});

    cout << res << '\n';
}