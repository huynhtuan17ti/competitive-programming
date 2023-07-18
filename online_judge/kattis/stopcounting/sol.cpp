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
    for(int i = 1; i <= n; ++i)
        cin >> a[i];

    ld ans = 0;
    ld cur_sum = 0;
    for(int i = 1; i <= n; ++i) {
        cur_sum += a[i];
        ans = max(ans, cur_sum / i);
    }
    cur_sum = 0;
    for(int i = n; i >= 1; --i) {
        cur_sum += a[i];
        ans = max(ans, cur_sum / (n - i + 1));
    }
    cout << fixed << setprecision(10) << ans << '\n';
}
