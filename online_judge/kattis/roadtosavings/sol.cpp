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

int G[MAXN][MAXN];

int main() {
    io
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j) {
            G[i][j] = INF;
            if(i == j) G[i][j] = 0;
        }
    
    using Edge = tuple<int, int, int>;
    vector<Edge> edges;
    while(m--) {
        int u, v, l;
        cin >> u >> v >> l;
        edges.emplace_back(u, v, l);
        G[u][v] = G[v][u] = l;
    }
    
    for(int k = 1; k <= n; ++k)
        for(int u = 1; u <= n; ++u)
            for(int v = 1; v <= n; ++v)
                if(G[u][k] + G[k][v] < G[u][v]) {
                    G[u][v] = G[u][k] + G[k][v];
                }

    int shortest_path = G[a][b], ans = 0;
    for(auto& [u, v, l]: edges) {
        int len = min(G[a][u] + l + G[v][b], G[a][v] + l + G[u][b]);
        if(len > shortest_path) ans += l;
    } 
    cout << ans << '\n';
}
