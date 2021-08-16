#include <bits/stdc++.h>

using namespace std;
#define MAXN 1005

typedef pair <int, int> ii;
#define fi first
#define se second

struct edge{
    int u, v;
    double c;
};

double dist(ii A, ii B){
    return (double)sqrt(1LL*(A.fi-B.fi)*(A.fi-B.fi) + 1LL*(A.se-B.se)*(A.se-B.se));
}

int parent[MAXN];

void init(int n){
    for(int i = 1; i <= n; i++)
        parent[i] = -1;
}

int findSet(int u){
    while(parent[u] > 0)
        u = parent[u];
    return u;
}

void Union(int u, int v){
    int x = parent[u] + parent[v];
    if(parent[u] > parent[v]){
        parent[u] = v;
        parent[v] = x;
    }else{
        parent[v] = u;
        parent[u] = x;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector <ii> pos(n+1);
    for(int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        pos[i] = {x, y};
    }
    vector <edge> edges;
    map <ii, bool> is_edge;
    init(n);
    while(m--){
        int u, v;
        cin >> u >> v;
        if(v > u)
            swap(u, v);
        is_edge[{u, v}] = true;
        edges.push_back({u, v, dist(pos[u], pos[v])});

        int U = findSet(u), V = findSet(v);
        if(U != V)
            Union(U, V);
    }
    for(int i = 1; i <= n; i++)
        for(int j = i+1; j <= n; j++)
            if(is_edge.find({i, j}) == is_edge.end()){
                edges.push_back({i, j, dist(pos[i], pos[j])});
            }
    double res = 0.0;
    sort(edges.begin(), edges.end(), [](const edge &A, const edge &B){
        return A.c < B.c;
    });
    for(edge e: edges){
        int U = findSet(e.u);
        int V = findSet(e.v);
        if(U != V){
            Union(U, V);
            res += e.c;
        }
    }
    cout << fixed << setprecision(2) << res << '\n';
}