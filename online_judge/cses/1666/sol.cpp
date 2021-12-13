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
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    while(m--){
        int u, v;
        cin >> u >> v;
        int U = dsu.findSet(u);
        int V = dsu.findSet(v);
        if(U != V){
            dsu.Union(U, V);
        }
    }
    vector <int> p;
    for(int i = 1; i <= n; i++)
        if(dsu.parent[i] < 0)
            p.push_back(i);
    cout << p.size()-1 << '\n';
    for(int i = 1; i < p.size(); i++)
        cout << p[i] << ' ' << p[i-1] << '\n';
}