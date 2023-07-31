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
constexpr int MAXN = 105;
constexpr int INF = 1e9;

class DSU{
public:
    vector <int> parent;

    DSU(int n){
        parent.resize(n+1, -1);
    }

    int findSet(int u){
        while(parent[u] > 0)
            u = parent[u];
        return u;
    }

    bool Union(int u, int v){
        u = findSet(u);
        v = findSet(v);
        if(u == v) return false;

        int x = parent[u] + parent[v];
        if(parent[u] > parent[v]){
            parent[v] = x;
            parent[u] = v;
        }else{
            parent[u] = x;
            parent[v] = u;
        }
        return true;
    }
};

int G[MAXN][MAXN];

int main() {
    io
    constexpr int POLICE_V = 160;
    int n, m, e;
    cin >> n >> m >> e;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            if(i != j) G[i][j] = INF;

    using Edge = tuple<double, int, int>;
    vector<Edge> edges;
    while(m--) {
        int a, b, l;
        cin >> a >> b >> l;
        G[a][b] = min(G[a][b], l);
        G[b][a] = min(G[b][a], l);
        edges.emplace_back(0, a, b);
    }

    vector<int> hw;
    for(int i = 0; i < e; ++i) {
        int u; cin >> u;
        hw.push_back(u);
    }

    int b, p;
    cin >> b >> p;

    // floyd
    for(int k = 1; k <= n; ++k)
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);

    // min_v[i] = minimum speed to go from b to i
    vector<double> min_v(n+1, INF);
    for(int i = 1; i <= n; ++i) {
        if(G[b][i] != INF)
            min_v[i] = G[b][i] * POLICE_V / static_cast<double>(G[p][i]); 
    }

    for(auto& [d, u, v]: edges)
        d = max(min_v[u], min_v[v]);

    sort(edges.begin(), edges.end());
    DSU dsu(n);
    vector<vector<int>> adj(n+1);
    for(auto [d, u, v]: edges) {
        if(dsu.Union(u, v)) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    function<void(int, int)> DFS = [&](int u, int pre) {
        for(int v: adj[u])
            if(v != pre) {
                min_v[v] = max(min_v[v], min_v[u]);
                DFS(v, u);
            }
    };

    DFS(b, 0);

    double ans = INF;
    for(auto u: hw)
        ans = min(ans, min_v[u]);

    if(ans == INF)
        cout << "IMPOSSIBLE\n";
    else
        cout << fixed << setprecision(10) << ans << '\n';
}
