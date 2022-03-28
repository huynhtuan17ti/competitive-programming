/**
 *    author:    hungt1
 *    created:   26-03-2022   13:14:25
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
 
const int N = 2e5 + 1;
long H[N], p[N];
int hashList[21];
int lenList[21];
 
void solve(){
    int n; cin >> n;
    string s; cin >> s;
    p[0] = 1;
    for (int i = 0; i < n; i++){
        H[i + 1] = (H[i] * 301 + s[i]) % MOD;
        p[i + 1] = p[i] * 301 % MOD;
    }    
 
    int k; cin >> k;
    for (int i = 0; i < k; i++){
        string t; cin >> t;
        lenList[i] = t.length();
        long tmp = 0;
        for (char c : t){
            tmp = (tmp * 301 + c) % MOD;
        }
        hashList[i] = tmp;
    }
 
    
    vector<int> lenMask(1 << k, 0);
    for (int mask = 0; mask < (1 << k); mask++){
        int len = 0;
        for (int i = 0; i < k; i++){
            if (mask >> i & 1) len += lenList[i];
        }
        lenMask[mask] = len;
    }
 
    auto getHash = [&](int l, int r){
        return (H[r] - H[l - 1] * p[r - l + 1] + 1ll * MOD * MOD) % MOD;
    };
 
    vector<bool> dp(1 << k, false);
    vector<int> trace(1 << k, 0);
    dp[0] = true;
    for (int mask = 0; mask < (1 << k); mask++){
        if (dp[mask]){
            for (int i = 0; i < k; i++){
                if (mask >> i & 1) continue;
                if (dp[mask ^ (1 << i)]) continue;
                int cur = lenMask[mask];
                if (cur + lenList[i] > n) continue;
                if (getHash(cur + 1, cur + lenList[i]) == hashList[i]){
                    dp[mask ^ (1 << i)] = true;
                    trace[mask ^ (1 << i)] = mask;
                }
            }
        }
    }
    int mn = k + 1, lst = -1;
    for (int mask = 0; mask < (1 << k); mask++){
        if (lenMask[mask] == n && dp[mask]){
            int cnt = 0;
            for (int i = 0; i < k; i++){
                if (mask >> i & 1) cnt++;
            }
            if (cnt < mn){
                mn = cnt;
                lst = mask;
            }
        }
    }
 
    cout << mn << '\n';
    vector<int> ans;
    while (lst != 0){
        int x = lst ^ trace[lst];
        int p = 0;
        while (x % 2 == 0){
            x /= 2; p++;
        }
        ans.push_back(p);
        lst = trace[lst];
    }
    reverse(all(ans));
    for (int x : ans) cout << x + 1 << ' '; cout << '\n';
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