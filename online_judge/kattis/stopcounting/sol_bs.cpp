#include <bits/stdc++.h>  
using namespace std;
 
constexpr int MOD = 1e9 + 7;
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
constexpr int MAXN = 3e5 + 5;

int main() {
    io
    int n; cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    auto check = [&](ld val) -> bool {
        vector<ld> d(n+2);
        ll cur_sum = 0;
        for(int i = n; i >= 1; --i) {
            cur_sum += a[i];
            d[i] = val * (n - i + 1) - cur_sum;
            if(i < n)
                d[i] = min(d[i], d[i+1]);
        }
        cur_sum = 0;
        if(0 >= d[1]) return true;
        for(int i = 1; i <= n; ++i) {
            cur_sum += a[i];
            if(cur_sum - val * i >= min(d[n+1], d[i+1]))
                return true;
        }
        return false;
    };

    ld L = 0, R = 1e15;
    for(int iter = 0; iter <= 100; ++iter) {
        ld mid = (L + R) / 2.0;
        if(check(mid))
            L = mid;
        else R = mid;
    }
    cout << fixed << setprecision(10) << L << '\n';
}
