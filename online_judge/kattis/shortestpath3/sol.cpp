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
constexpr int inf = 1e9;

bool stop = false;
using Edge = tuple<int, int, int>;

inline void solve() {
    int n, m, q, s;
    cin >> n >> m >> q >> s;
    if(n == 0) {
        stop = true;
        return;
    }
    vector<Edge> edges;
    for(int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.emplace_back(u, v, w);
    }

    // bellman-ford
    vector<int> dist(n, inf);
    dist[s] = 0;
    for(int i = 1; i <= 2 * n - 1; ++i) {
        for(auto [u, v, w]: edges)
            if(dist[u] != inf && dist[v] > dist[u] + w) {
                if(i >= n)
                    dist[v] = -inf;
                else dist[v] = dist[u] + w;
            }
    }

    while(q--) {
        int u; cin >> u;
        int d = dist[u];
        cout << (d == inf ? "Impossible" : (d == -inf ? "-Infinity" : to_string(d))) << '\n';
    }
    cout << '\n';
}

int main() {
    io
    do {
        solve();
    }while(!stop);
}
