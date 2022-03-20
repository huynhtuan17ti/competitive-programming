/**
 *    author:    hungt1
 *    created:   19-03-2022   14:17:58
**/
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using pll = pair<int64_t, int64_t>;
using ld = long double;

#define long int64_t
#define all(c) c.begin(), c.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)

template <class T> inline void chmin(T &a, const T& val) { if (a > val) a = val; }
template <class T> inline void chmax(T &a, const T& val) { if (a < val) a = val; }
template <class T> long sqr(T a) { return 1ll * a * a; }
template <class T> void compress(T &a) { sort(all(a)); a.resize(unique(all(a)) - a.begin()); }
template <class T> T power(T x, long n){
    T res = 1;
    for (; n; x *= x, n >>= 1){
        if (n & 1) res *= x;
    }
    return res;
}

const double pi = acos(-1.00);
const double eps = 1e-6;
const int INF = 2e9;
const int MOD = 1e9 + 7;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

void solve(){
    int n, sum = 0; cin >> n;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
        sum += x;
    }

    vector<vector<int>> dp(2, vector<int> (sum + 1, -1));
    int cur = 0; dp[0][0] = 0;
    for (int x : a){
        cur ^= 1;
        for (int diff = 0; diff <= sum; diff++) dp[cur][diff] = dp[cur ^ 1][diff];
        for (int diff = 0; diff <= sum; diff++){
            if (dp[cur ^ 1][diff] == -1) continue;
            if (diff + x <= sum){
                dp[cur][diff + x] = max(dp[cur][diff + x], dp[cur ^ 1][diff]);
            }
            dp[cur][abs(diff - x)] = max(dp[cur][abs(diff - x)], dp[cur ^ 1][diff] + min(x, diff));
        }
    }
    cout << dp[cur][0] << '\n';
}

int main()
{
    fastio;
    int T = 1; //cin >> T;
    while (T--){
        solve();
    }
    return 0;
}