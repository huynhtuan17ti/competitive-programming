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
    // freopen("test.out", "w", stdout);
    int n; cin >> n;
    vector <vector <char>> a(n+1, vector <char>(n+1));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    
    vector <vector <ll>> dp(n+1, vector <ll> (n+1));
    dp[1][1] = (a[1][1] == '.');
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            if(i == 1 && j == 1)
                continue;
            dp[i][j] = (a[i][j] == '.')? dp[i-1][j] + dp[i][j-1] : 0;
            dp[i][j] %= MOD;
        }
    cout << dp[n][n] << '\n';
}