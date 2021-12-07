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

void solve(){
    int n, d;
    cin >> n >> d;
    vector <ii> edges;
    for(int i = 1; i <= d; i++){
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
    DSU dsu;
    dsu.initialize(n);
    int cnt = 0;
    for(ii e: edges){
        int U = dsu.findSet(e.fi);
        int V = dsu.findSet(e.se);
        if(U == V)
            cnt++;
        else
            dsu.Union(U, V);
        
        vector <int> v;
        for(int i = 1; i <= n; i++)
            if(dsu.parent[i] < 0)
                v.push_back(-dsu.parent[i]);
        sort(v.begin(), v.end(), greater <int> ());
        ll sum = 0;
        for(int i = 0; i <= cnt; i++)
            sum += v[i];
        cout << sum-1 << '\n';
    }
}

int main(){
    io
    int t = 1;
    while(t--){
        solve();
    }
}