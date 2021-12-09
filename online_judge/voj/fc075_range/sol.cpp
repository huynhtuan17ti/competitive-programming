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
    int n, m;
    cin >> n >> m;
    #define Edge pair <int, ii>
    vector <Edge> edges;
    while(m--){
        int u, v, w;
        cin >> u >> v >> w;
        u++;
        v++;
        edges.push_back({w, mp(u, v)});
    }

    DSU dsu(n);

    sort(edges.begin(), edges.end());
    int cnt = 0;
    for(Edge e: edges){
        int U = dsu.findSet(e.se.fi);
        int V = dsu.findSet(e.se.se);
        if(U != V){
            dsu.Union(U, V);
            cnt++;
        }
        if(cnt == n-1)
            return cout << e.fi, 0;
    }
    cout << "IMPOSSIBLE";
}