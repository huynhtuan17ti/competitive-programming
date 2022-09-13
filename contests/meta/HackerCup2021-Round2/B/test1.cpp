#include <bits/stdc++.h>

using namespace std;
const int MAXN = 100005;
typedef pair <int, int> ii;
typedef vector <ii> vii;
#define fi first
#define se second

class LCA{
    public:
        int R[MAXN][30];
        int n;
        int h[MAXN];
        vector <int> G[MAXN];
        void add_edge(int u, int v){
            G[u].push_back(v);
            G[v].push_back(u);
        }
        void DFS(int u, int pre){
            for(int v: G[u])
                if(v != pre){
                    R[v][0] = u;
                    h[v] = h[u] + 1;
                    DFS(v, u);
                }
        }
        void init_table(){
            for(int j = 1; j <= log2(n); j++)
                for(int i = 1; i <= n; i++)
                    R[i][j] = R[R[i][j-1]][j-1];
        }
        int lca(int u, int v){
            if(h[u] < h[v])
                swap(u, v);
            for(int i = log2(h[u]); i >= 0; i--)
                if(h[u] - (1<<i) >= h[v])
                    u = R[u][i];
            if(u == v)
                return u;
            for(int i = log2(h[u]); i >= 0; i--)
                if(R[u][i] != 0 && R[u][i] != R[v][i])
                {
                    u = R[u][i];
                    v = R[v][i];
                }
            return R[u][0];
        }
        void init(int n){
            this->n = n;
            for(int i = 0; i <= n; i++)
                G[i].clear();
            fill(h, h+n+1, 0);
        }
}lca;

int sum[MAXN];

int DFS(int u){
    for(int v: lca.G[u])
        if(v != lca.R[u][0])
            sum[u] += DFS(v);
    return sum[u];
}

int main(){
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int t; cin >> t;
    int n; cin >> n;
    lca.init(n);
    vii edges;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
        lca.add_edge(u, v);
        
    }
    lca.DFS(1, 0);
    lca.init_table();
    int m; cin >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        int cha = lca.lca(u, v);
        sum[u]++;
        sum[v]++;
        sum[cha] -= 2;
    }
    DFS(1);
    for(int i = 0; i < n-1; i++)
        cout << sum[lca.R[edges[i].fi][0] == edges[i].se ? edges[i].fi : edges[i].se] << " \n"[i == n-1];
}