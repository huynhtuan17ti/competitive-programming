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
const int MAXV = 5e5;
int label[MAXN];
vii G[MAXN];
vector <int> Div[MAXV + 5];

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

    // get distance of (u, v)
    ll get(int u, int v){
        int p = lca(u, v);
        return dist[u] + dist[v] - dist[p]*2;
    }
};

vector <int> F[MAXV+5];

void init_div(){
    for(int i = 1; i <= MAXV; i++){
        for(int j = i; j <= MAXV; j+=i)
            F[j].push_back(i);
    }
}

void solve(int n){
    set <int> used;
    for(int i = 1; i <= n; i++){
        cin >> label[i];
        for(int v: F[label[i]]){
            Div[v].push_back(i);
            used.insert(v);
        }
    }

    for(int i = 1; i <= n; i++)
        G[i].clear();

    for(int i = 1; i < n; i++){
        int u, v, c;
        cin >> u >> v >> c;
        G[u].push_back({v, c});
        G[v].push_back({u, c});
    }

    LCA <ll> lca;
    lca.initialize(n);

    ll res = 0;
    for(auto val: used){
        if(Div[val].size() == 1)
            continue;
        int root = Div[val][0];
        ll maxDist = 0;
        int node = -1;
        for(int v: Div[val]){
            ll cur_dist = lca.get(root, v);
            if(maxDist < cur_dist){
                maxDist = cur_dist;
                node = v;
            }
        }
        maxDist = 0;
        for(int v: Div[val]){
            ll cur_dist = lca.get(node, v);
            maxDist = max(maxDist, cur_dist);
        }

        res = max(res, maxDist*val);
        Div[val].clear();
    }
    cout << res << '\n';   
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    init_div();
    int n;
    while(cin >> n){
        if(n == 0)
            return 0;
        solve(n);
    }
}