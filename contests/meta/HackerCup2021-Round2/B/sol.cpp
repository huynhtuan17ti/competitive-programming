#include <bits/stdc++.h>  
#include <sys/resource.h>

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
const int MAXN = 800005;

vector <int> G[MAXN];
int F[MAXN];
vector <int> P[MAXN];
int num[MAXN];
int sum[MAXN];

int cnt = 0;
void DFS(int u, int pre){
    for(int i = 0; i < G[u].size(); i++){
        int v = G[u][i];
        if(v != pre && u != v){
            DFS(v, u);
        }
    }   
}


template <typename T>
class LCA{
    public:
    vector <int> h;
    vector <vector <int>> R;

    void initialize(int n){
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

int DFS_sum(int u, int pre){
    for(int v: G[u])
        if(v != pre)
            sum[u] += DFS_sum(v, u);
    return sum[u];
}

void solve(int iTest){
    int n; cin >> n;
    cnt = 0;
    for(int i = 1; i <= n; i++){
        G[i].clear();
        P[i].clear();
        sum[i] = 0;
        num[i] = 0;
    }
    
    vii edges;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
        G[u].push_back(v);
        G[v].push_back(u);
    }

    DFS(1, 0);
    
    for(int i = 1; i <= n; i++){
        cin >> F[i];
        assert(F[i] <= n);
        P[F[i]].push_back(i);
    }
    
    LCA <int> lca;
    lca.initialize(n);

    for(int val = 1; val <= n; val++){
        sort(P[val].begin(), P[val].end(), [](const int &A, const int &B){
            return num[A] < num[B];
        });
        for(int j = 1; j < P[val].size(); j++){
            int v = P[val][j-1];
            int u = P[val][j];
            int cha = lca.lca(u, v);
            sum[cha] -= 2;
            sum[u] ++;
            sum[v] ++;

        }
    }

    DFS_sum(1, 0);

    int res = 0;
    for(int i = 0; i < n-1; i++){
        int x = sum[lca.R[edges[i].fi][0] == edges[i].se ? edges[i].fi : edges[i].se];
        if(x == 0)
            res++;
    }
    cout << "Case #" << iTest << ": " << res << '\n';
}

int main(){
    rlimit rlim;
    if (getrlimit(RLIMIT_STACK, &rlim)) return 1;
    rlim.rlim_cur = rlim.rlim_max;
    // You can set the fixed value instead of max value, e.g. rlim.rlim_cur = 1024 * 1024 * 1024
    // will set your stack size to 1 GiB
    if (setrlimit(RLIMIT_STACK, &rlim)) return 2;
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int t; cin >> t;
    for(int iTest = 1; iTest <= t; iTest++){
        solve(iTest);
    }
}