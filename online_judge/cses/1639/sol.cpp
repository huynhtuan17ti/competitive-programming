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
const int MAXN = 5e3 + 5;

int dp[MAXN][MAXN]; // the minimum number of operations to transform s[1..i] same as t[1..j]

int main(){
    io
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    s = ' ' + s;
    t = ' ' + t;

    for(int i = 0; i <= n; i++)
        dp[i][0] = i;
    for(int j = 0; j <= m; j++)
        dp[0][j] = j;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            dp[i][j] = n + m;
            if(s[i] == t[j])
                dp[i][j] = dp[i-1][j-1];
            dp[i][j] = min({dp[i][j], dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + 1});
        }
    cout << dp[n][m] << '\n';
}