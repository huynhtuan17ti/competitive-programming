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
const int MAXN = 1e6;

ll dp[MAXN + 5][2];

int main(){
    io
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    ll sumDp = 1;
    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[0][1] = 0;
    for(int i = 1; i <= MAXN; i++){
        if(i > 1)
            dp[i][0] = dp[i-1][1] + dp[i-1][0] * 4;
        dp[i][1] = sumDp;
        sumDp += dp[i][0] + dp[i][1];
        sumDp %= MOD;

        dp[i][0] %= MOD;
        dp[i][1] %= MOD;
    }
    // the answer is dp[i][1] + dp[i][0]
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << (dp[n][1] + dp[n][0])%MOD << '\n';
    }
}