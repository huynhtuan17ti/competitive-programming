#include <bits/stdc++.h>  
using namespace std;
 
constexpr int MOD = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define mp make_pair
#define fi first
#define se second
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};
constexpr int MAXN = 3e5 + 5;

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

int main() {
    io
    int n, q;
    cin >> n >> q;
    DSU dsu(n);
    while(q--) {
        char t;
        int a, b;
        cin >> t >> a >> b;
        ++a; ++b;
        int U = dsu.findSet(a), V = dsu.findSet(b);
        if(t == '=') {
            if(U != V) dsu.Union(U, V);
        }else {    
            cout << (U == V ? "yes" : "no") << '\n';
        }
    }
}
