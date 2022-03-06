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

struct edge{
    int u, v, c;
    bool operator < (const edge &other){
        return c < other.c;
    }
};

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

    void Union(int u, int v){
        int x = parent[u] + parent[v];
        if(parent[u] > parent[v]){
            parent[v] = x;
            parent[u] = v;
        }else{
            parent[u] = x;
            parent[v] = u;
        }
    }
};

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n; cin >> n;
    vector <int> q(n+1);
    for(int i = 1; i <= n; i++)
        cin >> q[i];
    int m; cin >> m;
    vector <vector <edge>> edges(n+1);
    while(m--){
        int u, v, c;
        cin >> u >> v >> c;
        edges[v].push_back({u, v, c});
    }
    for(int i = 1; i <= n; i++)
        sort(edges[i].begin(), edges[i].end());

    DSU dsu(n);
    int ans = 0, cnt = 0;
    for(int i = 1; i <= n; i++){
        for(auto [u, v, c]: edges[i]){
            int U = dsu.findSet(u);
            int V = dsu.findSet(v);
            if(U != V){
                //cout << u << ' ' << v << ' ' << c << '\n';
                cnt++;
                ans += c;
                dsu.Union(U, V);
                break;
            }
        }
    }
    if(cnt < n-1){
        return cout << -1, 0;
    }
    cout << ans << '\n';
}
