#include <bits/stdc++.h>  
using namespace std;

const int MOD = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
#define mp make_pair
#define fi first
#define se second
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
const int MAXN = 5e3 + 5;

ii dp[MAXN][MAXN];

int main(){
    io
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int n; cin >> n;
    vector <int> a(n+1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++){
        dp[i][i].fi = a[i];
        dp[i][i].se = i;
        if(i+1 <= n){
            dp[i][i+1].fi = max(a[i], a[i+1]);
            dp[i][i+1].se = (a[i] > a[i+1])? i : i+1;
        }
    }
    
    for(int len = 3; len <= n; len++)
        for(int i = 1; i <= n; i++){
            int j = i + len - 1;
            if(j > n)
                continue;
            dp[i][j].fi = -1e15;
            if(dp[i+1][j].se == i+1 && dp[i][j].fi < dp[i+2][j].fi + a[i]){
                dp[i][j].fi = dp[i+2][j].fi + a[i];
                dp[i][j].se = i;
            }
            if(dp[i+1][j].se == j && dp[i][j].fi < dp[i+1][j-1].fi + a[i]){
                dp[i][j].fi = dp[i+1][j-1].fi + a[i];
                dp[i][j].se = i;
            }
            if(dp[i][j-1].se == j-1 && dp[i][j].fi < dp[i][j-2].fi + a[j]){
                dp[i][j].fi = dp[i][j-2].fi + a[j];
                dp[i][j].se = j;
            }
            if(dp[i][j-1].se == i && dp[i][j].fi < dp[i+1][j-1].fi + a[j]){
                dp[i][j].fi = dp[i+1][j-1].fi + a[j];
                dp[i][j].se = j;
            }
        }
    cout << dp[1][n].fi << '\n';
}