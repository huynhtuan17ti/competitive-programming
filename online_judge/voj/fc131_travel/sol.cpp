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

vector<int> G[MAXN];
int cnt = 0;
int st[MAXN], ed[MAXN];

template <typename T>
class FenwickTree
{
private:
    vector<T> fenw;
    int n;

public:
    FenwickTree(int _n)
    {
        this->n = _n;
        fenw.resize(n + 1);
    }

    void update(int id, T val)
    {
        while (id <= n)
        {
            fenw[id] += val;
            id += id & (-id);
        }
    }

    T get(int id)
    {
        T ans{};
        while (id >= 1)
        {
            ans += fenw[id];
            id -= id & (-id);
        }
        return ans;
    }
};

template <typename T>
class LCA
{
public:
    vector<int> h;
    vector<vector<int>> R;

    void initialize(int n)
    {
        h.resize(n + 1);
        R.resize(n + 1);
        int sz = trunc(log2(n) + 1);
        for (int i = 0; i <= n; i++)
            R[i].resize(sz);
        DFS_level(1, 0);
        for (int j = 1; j <= log2(n); j++)
            for (int i = 1; i <= n; i++)
                R[i][j] = R[R[i][j - 1]][j - 1];
    }

    void DFS_level(int u, int pre)
    {
        for (int v : G[u])
            if (v != pre)
            {
                h[v] = h[u] + 1;
                R[v][0] = u;
                DFS_level(v, u);
            }
    }

    int lca(int u, int v)
    {
        if (h[u] < h[v])
            swap(u, v);

        for (int i = log2(h[u]); i >= 0; i--)
            if (h[u] - (1 << i) >= h[v])
                u = R[u][i];

        if (u == v)
            return u;

        for (int i = log2(h[u]); i >= 0; i--)
            if (R[u][i] != 0 && R[u][i] != R[v][i])
            {
                u = R[u][i];
                v = R[v][i];
            }
        return R[u][0];
    }
};

void DFS(int u, int pre){
    st[u] = ++cnt;
    for(int v: G[u])
        if(v != pre)
            DFS(v, u);
    ed[u] = cnt;
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    vector <int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] = abs(a[i]);
    }
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    DFS(1, 0);
    FenwickTree <ll> fenw(n+1);
    for(int i = 1; i <= n; i++){
        //cerr << st[i] << ' ' << ed[i] << '\n';
        fenw.update(st[i], a[i]);
        fenw.update(ed[i]+1, -a[i]);
    }

    LCA <int> lca;
    lca.initialize(n);

    while(q--){
        int t, u, v; cin >> t >> u >> v;
        if(t == 1){
            int pre = a[u];
            a[u] = abs(v);
            fenw.update(st[u], -pre + a[u]);
            fenw.update(ed[u]+1, pre - a[u]);
        }else{
            int pa = lca.lca(u, v);
            cout << 2LL*(fenw.get(st[u]) + fenw.get(st[v]) - 2LL*fenw.get(st[pa])) + 2*a[pa] - a[u] - a[v] << '\n';
        }
    }
}