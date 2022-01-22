/**
 *    author:    hungt1
 *    created:   27-11-2021   10:03:09
**/
#include <bits/stdc++.h>
using namespace std;

#define long long long
#define db double
#define pii pair <int, int>
#define pll pair <long, long>
#define all(c) c.begin(), c.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

template <class T> inline void chmin(T &a, const T& val) { if (a > val) a = val; }
template <class T> inline void chmax(T &a, const T& val) { if (a < val) a = val; }
template <class T> long sqr(T a) { return 1ll * a * a; }
template <class T> void compress(T &a){
    sort(all(a)); a.resize(unique(all(a)) - a.begin());
}

const db pi = acos(-1.00);
const db eps = 1e-6;
const int INF = 2e9;
const int MOD = 1e9 + 7;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

const int N = 101;
int dp[2 * N][N][N];

int power(int x, int n){
   if (n == 0) return 1;
   int y = power(x, n / 2);
   y = 1ll * y * y % MOD;
   if (n & 1) return 1ll * x * y % MOD;
   else return y; 
}

int main()
{
    fastio;
    int r, c; cin >> r >> c;
    int l; cin >> l;
    for (int i = 1; i <= r; i++){
        for (int j = 1; j <= c; j++){
            dp[1][i][j] = 1;
        }
    }
    for (int k = 2; k <= l; k++){
        int sum = 0;
        for (int i = 1; i <= r; i++){
            for (int j = 1; j <= c; j++){
                sum += dp[k - 1][i][j];
                sum %= MOD;
            } 
        }
        for (int i = 1; i <= r; i++){
            for (int j = 1; j <= c; j++){
                dp[k][i][j] = sum;
                for (int u = -1; u <= 1; u++){
                    if (i + u < 1) continue;
                    for (int v = -1; v <= 1; v++){
                        if (j + v < 1) continue;
                        dp[k][i][j] -= dp[k - 1][i + u][j + v];
                        dp[k][i][j] %= MOD;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= r; i++){
        for (int j = 1; j <= c; j++){
            ans += dp[l][i][j];
            ans %= MOD;
        }
    }
    cout << (ans + MOD) % MOD << '\n';
    return 0;
}