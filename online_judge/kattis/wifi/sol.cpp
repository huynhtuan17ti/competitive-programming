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

inline void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> p(m+1);
    for(int i = 1; i <= m; ++i) {
        cin >> p[i];
        p[i] *= 10;
    }
    sort(p.begin(), p.end());
    
    auto check = [&](int max_dis) {
        int min_access_points = 0;
        int pre_point = INT_MIN;
        for(int i = 1; i <= m; ++i) {
            if(abs(p[i] - pre_point) > max_dis) {
                pre_point = p[i] + max_dis;
                ++min_access_points;
            }
        }
        return min_access_points <= n;
    };

    int L = 0, R = 10000000;
    while(L <= R) {
        int mid = (L + R) >> 1;
        if(check(mid))
            R = mid - 1;
        else L = mid + 1;
    }
    cout << fixed << setprecision(1) << static_cast<double>(R + 1) / 10 << '\n';
}

int main() {
    io
    int t; cin >> t;
    while(t--) {
        solve();
    }
}
