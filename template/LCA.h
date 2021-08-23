#include <bits/stdc++.h>
using namespace std;

template <typename T>
class LCA{
    public:
    vector <int> h;
    vector <T> dist;
    vector <vector <int>> R;

    void initialize(int n){
        h.resize(n+1);
        dist.resize(n+1);
        R.resize(n+1);
        int sz = trunc(log2(n)+1);
        for(int i = 0; i <= n; i++)
            R[i].resize(sz);
        DFS_level(1, 0);
        for(int j = 1; j <= log2(n); j++)
            for(int i = 1; i <= n; i++)
                R[i][j] = R[R[i][j-1]][j-1];
    }

    void DFS_level(int u, int pre){
        for(ii v: G[u])
            if(v.fi != pre){
                h[v.fi] = h[u] + 1;
                dist[v.fi] = dist[u] + v.se;
                R[v.fi][0] = u;
                DFS_level(v.fi, u);
            }
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
            if(R[u][i] != 0 && R[u][i] != R[v][i]){
                u = R[u][i];
                v = R[v][i];
            }
        return R[u][0];
    }

    // get distance between (u, v)
    ll get(int u, int v){
        int p = lca(u, v);
        return dist[u] + dist[v] - dist[p]*2;
    }
};