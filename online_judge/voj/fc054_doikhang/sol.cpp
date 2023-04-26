#include <bits/stdc++.h>  
using namespace std;
 
constexpr int MOD = 1e9 + 9;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define mp make_pair
#define fi first
#define se second
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};
constexpr int MAXN = 1001;

ll dp[MAXN][MAXN][11];

int main() {
    io
    int N, M, K;
    cin >> N >> M >> K;
    vector<ll> X(N+1), Y(M+1);
    for(int i = 1; i <= N; ++i)
        cin >> X[i];
    for(int i = 1; i <= M; ++i)
        cin >> Y[i];
    
    sort(X.begin()+1, X.end(), greater<ll>());
    sort(Y.begin()+1, Y.end(), greater<ll>());
    
    for(int i = 0; i <= N; ++i)
        dp[i][0][0] = 1;

    for(int i = 0; i <= M; ++i)
        dp[0][i][0] = 1;

    for(int i = 1; i <= N; ++i)
    for(int j = 1; j <= M; ++j)
    for(int k = 0; k <= K; ++k) {
        if(X[i] > Y[j]) {
            if(k > 0) dp[i][j][k] += dp[i-1][j-1][k-1];
            dp[i][j][k] += dp[i-1][j][k] + dp[i][j-1][k] - dp[i-1][j-1][k];
        }else  
            dp[i][j][k] += dp[i-1][j][k] + dp[i][j-1][k] - dp[i-1][j-1][k];
        dp[i][j][k] += MOD;
        dp[i][j][k] %= MOD;
    }
    cout << dp[N][M][K] << '\n';
}
