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
const int MAXN = 305;

int dp[MAXN][MAXN];

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            dp[i][j] = 1e9;

    for(int i = 0; i < n; i++){
        if(t[0] == s[i])
            dp[0][i] = 0;
    }

    for(int i = 1; i < m; i++){
        for(int j = 0; j < n; j++){
            if(t[i] == s[j]){
                if(j > 0 && s[j-1] == t[i-1]){
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1] + 1);
                    for(int k = 0; k < n; k++)
                        if(k != j-1 && s[k] == s[j-1])
                            dp[i][j] = min(dp[i][j], dp[i-1][k] + abs(k - j + 1) + 1);
                }
                if(j < n-1 && s[j+1] == t[i-1]){
                    dp[i][j] = min(dp[i][j], dp[i-1][j+1] + 1);
                    for(int k = 0; k < n; k++)
                        if(k != j+1 && s[k] == s[j+1]){
                            dp[i][j] = min(dp[i][j], dp[i-1][k] + abs(k - j - 1) + 1);
                        }
                }
            }
        }
    }

    int res = 1e9;
    for(int i = 0; i < n; i++){
        if(dp[m-1][i] != 1e9)
            res = min(res, dp[m-1][i]);
    }

    if(res == 1e9)
        cout << -1 << '\n';
    else cout << res << '\n';
}