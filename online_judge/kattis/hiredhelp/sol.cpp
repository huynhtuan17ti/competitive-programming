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
    int N, K;
    cin >> N >> K;
    vector<int> cnt(K+2);
    for(int i = 1; i <= N; ++i) {
        int d; cin >> d;
        ++cnt[min(d, K+1)];
    }

    auto check = [&](int val) {
        ll r = cnt[K+1];
        for(int i = K; i >= 1; --i) {
            if (cnt[i] >= val) {
                r += (cnt[i] - val);
            } else {
                if (cnt[i] + r < val) return false;
                r -= (val - cnt[i]);
            }
        }
        return true;
    };

    int l = 0, r = N;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid))
            l = mid + 1;
        else r = mid - 1;
    }
    cout << l - 1 << '\n';
}
