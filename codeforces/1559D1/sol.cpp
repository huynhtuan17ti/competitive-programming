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

class DSU{
    public:
        vector <int> parent;
        void initialize(int n){
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
    int n; cin >> n;
    int m1, m2;
    cin >> m1 >> m2;
    vii edges[2];
    while(m1--){
        int u, v;
        cin >> u >> v;
        edges[0].push_back({u, v});
    }
    while(m2--){
        int u, v;
        cin >> u >> v;
        edges[1].push_back({u, v});
    }
    DSU dsu[2];
    dsu[0].initialize(n);
    dsu[1].initialize(n);

    for(int t = 0; t <= 1; t++){
        for(ii e: edges[t]){
            int U = dsu[t].findSet(e.fi);
            int V = dsu[t].findSet(e.se);
            if(U != V)
                dsu[t].Union(U, V);
        }
    }

    vii res;
    for(int i = 1; i <= n; i++)
        for(int j = i+1; j <= n; j++){
            int U1 = dsu[0].findSet(i);
            int V1 = dsu[0].findSet(j);
    
            int U2 = dsu[1].findSet(i);
            int V2 = dsu[1].findSet(j);
    
            if(U1 != V1 && U2 != V2){
                dsu[0].Union(U1, V1);
                dsu[1].Union(U2, V2);
                res.push_back({i, j});
            }
        }
 
    cout << res.size() << '\n';
    for(ii e: res)
        cout << e.fi << ' ' << e.se << '\n';
}