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
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
const int MAXN = 5e5 + 5;

vector <int> G[MAXN];

template <typename T>
class LCA{
    public:
    vector <int> h;
    vector <vector <int>> R;

    LCA(int n){
        h.resize(n+1);
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
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);
    int n, q; cin >> n >> q;
    for(int i = 2; i <= n; i++){
        int u; cin >> u;
        G[u].push_back(i);
    }
    LCA <int> lca(n);
    while(q--){
        int u, v;
        cin >> u >> v;
        cout << lca.lca(u, v) << '\n';
    }
}