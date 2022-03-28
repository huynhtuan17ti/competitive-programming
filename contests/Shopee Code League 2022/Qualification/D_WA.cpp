/**
 *    author:    hungt1
 *    created:   19-03-2022   15:43:22
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
    int n; cin >> n;
    vector<int> num(n + 1, -1);
    vector<pii> b(n);
    int idx = 0;
    for (int i = 0; i < 2 * n; i++){
        int x; cin >> x;
        if (num[x] == -1) {
            num[x] = idx;
            b[idx++].first = i;
        }
        else b[num[x]].second = i;
    }
    sort(all(b));
    set<pii> s;
    vector<vector<int>> adj(n + 1, vector<int> ());
    s.insert({b[0].second, 0});
    for (int i = 1; i < n; i++){
        while (s.size()){
            pii x = *s.begin();
            if (x.first < b[i].first) s.erase(x);
            else break;
        }
        for (pii x : s){
            if (b[i].first < x.first && x.first < b[i].second){
                adj[i].push_back(x.second); adj[x.second].push_back(i);                
            }
            else break;
        }
        s.insert({b[i].second, i});
    }

    bool check = true;
    vector<int> color(n + 1, -1);
    function<void(int)> dfs = [&](int u){
        if (color[u] == -1) color[u] = 0;
        for (int v : adj[u]){
            if (color[v] != -1){
                if (!(color[v] ^ color[u])) check = false;
            }
            else {
                color[v] = 1 - color[u];
                dfs(v);
            }
        }
    };

    for (int i = 0; i < n; i++){
        if (color[i] == -1) dfs(i);
    }

    cout << (check ? "yes" : "no") << '\n';
}

int main()
{
    fastio;
    int T = 1; cin >> T;
    while (T--){
        solve();
    }
    return 0;
}