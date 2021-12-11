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
const int MAXN = 100 + 5;

ll dp[MAXN][MAXN][MAXN];

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int r, s, p;
    cin >> r >> s >> p;
    dp[r][s][p] = 1;
    for(int i = r; i >= 0; i--)
        for(int j = s; j >= 0; j--)
            for(int k = p; k >= 0; k--){
                if(j >= 1 && i >= 1){
                    dp[i][j-1][k] += dp[i][j][k] * i * j % MOD;
                    dp[i][j-1][k] %= MOD;
                }
                if(k >= 1 && j >= 1){
                    dp[i][j][k-1] += dp[i][j][k] * j * k % MOD;
                    dp[i][j][k-1] %= MOD;
                }
                if(i >= 1 && k >= 1){
                    dp[i-1][j][k] += dp[i][j][k] * k * i % MOD;
                    dp[i-1][j][k] %= MOD;
                }
            }
    ll sum = 0;
    for(int i = 1; i <= r; i++)
        sum = (sum + dp[i][0][0])%MOD;
    cout << sum << ' ';
    sum = 0;
    for(int i = 1; i <= s; i++)
        sum = (sum + dp[0][i][0])%MOD;
    cout << sum << ' ';
    sum = 0;
    for(int i = 1; i <= p; i++)
        sum = (sum + dp[0][0][i])%MOD;
    cout << sum;
}