/**
 *    author:    hungt1
 *    created:   27-11-2021   10:50:00
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

int main()
{
    fastio;
    int n, m, k; cin >> n >> m >> k;
    int ans = (n + 2 * m + 3 * k) / 6;
    int mn = 0;
    while (n < ans){
        if (m > ans){
            m -= 1; n += 2;
            mn++;
        }
        else {
            k -= 1; m += 1; n += 1;
            mn++;
        }
    }
    while (m < ans){
        if (n - 2 >= ans){
            n -= 2; m += 1;
        }
        else {
            k -= 1; n += 1; m += 1;
            mn++;
        }
    }
    while (k < ans){
        if (n > ans && m > ans){
            k += 1; n -= 1; m -= 1;
        }
        else if (n - 3 >= ans){
            k += n -= 3;
        }
        else {
            m -= 1; n += 2;
            mn++;
        }
    }
    cout << ans << ' ' << mn << '\n';
    return 0;
}