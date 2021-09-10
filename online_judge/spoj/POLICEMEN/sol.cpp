#include <bits/stdc++.h>  
 
using namespace std;
 
const int MOD = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define mp make_pair
#define fi first
#define se second
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int MAXN = 1e5 + 5;
vector <int> G[MAXN];

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
        for(int v: G[u])
            if(v != pre){
                h[v] = h[u] + 1;
                dist[v] = dist[u] + 1;
                R[v][0] = u;
                DFS_level(v, u);
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
};

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n; cin >> n;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    LCA <int> lca;
    lca.initialize(n);
    int m; cin >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        if(lca.dist[a] >= lca.dist[b]){
            cout << "YES" << ' ' << lca.lca(a, b) << '\n';
        }else{
            cout << "NO" << '\n';
        }
    }
}