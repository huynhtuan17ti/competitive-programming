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

vector<int> G[MAXN];

int main() {
    io
    int n, m;
    cin >> n >> m;
    vii edges;
    while(m--) {
        int u, v;
        cin >> u >> v;
        edges.emplace_back(u, v);
    }
    vii rest_edges;
    DSU dsu(n);
    for(auto [u, v]: edges) {
        if(dsu.Union(u, v)) {
            G[u].push_back(v);
            G[v].push_back(u);
        }else {
           rest_edges.emplace_back(u, v); 
        } 
    }

    vector<int> l(n+1);
    vector<vector<int>> dp(n+1, vector<int>(2));

    function<void(int, int)> DFS = [&](int u, int pre) {
        if(l[u]) dp[u][1] = 1;
        for(int v: G[u])
            if(v != pre) {
                DFS(v, u);
                dp[u][0] += max(dp[v][0], dp[v][1]);
                if(l[u]) dp[u][1] += dp[v][0];
            }
    };

    auto getBit = [&](int val, int bit)-> bool {
        return (val>>bit)&1;
    };

    int k = (int)rest_edges.size();
    int ans = 0;
    for(int state = 0; state < (1<<k); ++state) {
        fill(l.begin(), l.end(), 1);
        for(int i = 0; i < k; ++i) {
            auto [u, v] = rest_edges[i];
            if(getBit(state, i)) swap(u, v);
            l[u] = 0;
        }
        for(int i = 1; i <= n; ++i) dp[i][0] = dp[i][1] = 0;
        DFS(1, 0);
        ans = max({ans, dp[1][0], dp[1][1]});
    }
    cout << ans << '\n';
}
