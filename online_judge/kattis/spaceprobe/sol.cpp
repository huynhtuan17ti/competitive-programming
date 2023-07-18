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
    int n, k;
    ll t1, t2;
    cin >> n >> k >> t1 >> t2;
    vector<ll> m(n);
    for(int i = 0; i < n; ++i)
        cin >> m[i];
    
    using lii = pair<ll, ll>;
    vector<lii> p;
    ll e, b;
    for(int i = 0; i < k; ++i) {
        cin >> b >> e;
        for(ll u: m) {
            ll L = b - u, R = e - u;
            if(L > t2 || R < t1) continue;
            L = max(L, t1);
            R = min(t2, R);
            p.push_back({L, R});
        }
    }
    
    sort(p.begin(), p.end());

    ll non_overlap_len = 0;
    ll max_len = t1;
    for(auto [b, e]: p) {
        if(max_len < b)
            non_overlap_len += b - max_len;
        max_len = max(max_len, e); 
    }
    if(max_len < t2)
        non_overlap_len += t2 - max_len;
    cout << fixed << setprecision(10) << static_cast<ld>(non_overlap_len) / (t2 - t1) << '\n';
}
