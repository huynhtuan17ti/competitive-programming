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
    int m, p, n;
    cin >> m >> p >> n;

    int ans = 0;
    int cur_target = m;
    for(int i = 1; i <= n; ++i) {
        int w; cin >> w;
        if(w >= cur_target) {
            ++ans;
            cur_target = ceil(m - static_cast<double>(w - cur_target) * p / 100.0);
        }else {
            cur_target = ceil(m + static_cast<double>(cur_target - w) * p / 100.0);
        }
    }

    cout << ans << '\n';
}
