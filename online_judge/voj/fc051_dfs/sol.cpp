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
const int MAXN = 105;

int n;
int a[MAXN];
int dp[MAXN][MAXN][MAXN];

int calcDp(int upper, int l, int r){
    if(l > r)
        return 1;
    if(l == r)
        return (a[l] <= upper);
    if(dp[upper][l][r] >= 0)
        return dp[upper][l][r];
    int ans = 0;
    for(int k = l; k <= r; k++){
        // choose k as a parent
        if(a[k] <= upper){
            int x = 1LL * calcDp(n, k+1, r) * calcDp(a[k], l, k-1) % MOD;
            ans += x;
            if(ans >= MOD)
                ans -= MOD;
        }
    }
    dp[upper][l][r] = ans;
    return ans;
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int u = 1; u <= n; u++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dp[u][i][j] = -1;
    cout << calcDp(n, 2, n) << '\n';
}