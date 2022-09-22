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
const int MAXN = 25000;
const int MAXV = 1e7;

int c[MAXN + 5];
vector<int> G[MAXN + 5];
int R[MAXN][50];
int h[MAXN];

class LCA{
public:
    LCA(int n){
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
    // get parent of (u, v)
    int get(int u, int v){
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
    freopen("test.ans", "w", stdout);
    
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> c[i];
    }

    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    LCA lca(n);

    auto getAns = [&](int u, int v){
        int pa = lca.get(u, v);
        vector<int> paths;
        paths.push_back(pa);
        while(u != pa){
            paths.push_back(u);
            u = R[u][0];
        }
        while(v != pa){
            paths.push_back(v);
            v = R[v][0];
        }
        int nPair = 0;
        for(int i = 0; i < paths.size(); i++)
            for(int j = i+1; j < paths.size(); j++)
                if(__gcd(c[paths[i]], c[paths[j]]) == 1)
                    nPair++;
        return nPair;
    };

    while(q--){
        int u, v;
        cin >> u >> v;
        cout << getAns(u, v) << '\n';
    }
}