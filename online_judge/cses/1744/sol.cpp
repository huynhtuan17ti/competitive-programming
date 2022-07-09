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
const int MAXN = 500 + 5;

int dp[MAXN][MAXN];

int main(){
    io
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int a, b;
    cin >> a >> b;
    for(int i = 1; i <= a; i++)
        for(int j = 1; j <= b; j++){
            if(i == j){
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = MAXN*MAXN;
            for(int cut = 1; cut < j; cut++)
                dp[i][j] = min(dp[i][j], dp[i][j-cut] + dp[i][cut] + 1);
            for(int cut = 1; cut < i; cut++)
                dp[i][j] = min(dp[i][j], dp[i-cut][j] + dp[cut][j] + 1);
        }
    cout << dp[a][b] << '\n';
}