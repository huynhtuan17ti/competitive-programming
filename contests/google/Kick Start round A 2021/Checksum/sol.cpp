/* Tuan Kkura */
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define base 31
#define MOD 1e9+7
#define pb push_back
#define _io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

typedef pair <int, int> ii;
typedef vector <ii> vii;
#define fi first
#define se second
#define mp make_pair
#define PROB "text"
#define MAXN 1005

int a[MAXN][MAXN];
int b[MAXN][MAXN];
int c[MAXN], r[MAXN];

int parent[MAXN];

struct edge{
    int u, v, c;
};

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

int main(){
    _io
    int T; cin >> T;
    for(int iTest = 1; iTest <= T; iTest++){
        int n; cin >> n;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                cin >> a[i][j];
        for(int  i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                cin >> b[i][j];
        for(int i = 1; i <= n; i++)
            cin >> r[i];
        for(int i = 1; i <= n; i++)
            cin >> c[i];

        vector <edge> edges;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(a[i][j] == -1){
                    edges.pb({i, j+n, b[i][j]});
                }
        sort(edges.begin(), edges.end(), [](const edge &A, const edge &B){
                return A.c > B.c;
             });
        ll sum = 0, max_mst = 0;
        for(int i = 1; i <= 2*n; i++)
            parent[i] = -1;
        for(edge e: edges){
            int U = findSet(e.u);
            int V = findSet(e.v);
            if(U != V){
                Union(U, V);
                max_mst += e.c;
            }
            sum += e.c;
        }

        cout << "Case #" << iTest << ": " << sum - max_mst << '\n';
    }
}
