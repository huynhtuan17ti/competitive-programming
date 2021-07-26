/* Tuan Kkura */
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define base 31
#define MOD 1e9+7
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORs(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, a, b) for(int i = a; i < b; i++)
#define __FOR(i, a, b, k) for(int i = a; i <= b; i+= k)
#define __REP(i, a, b, k) for(int i = a; i < b; i+= k)
#define pb push_back
#define _io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

typedef pair <int, int> ii;
typedef vector <ii> vii;
#define fi first
#define se second
#define mp make_pair
#define PROB "J"
#define MAXN 400005

struct edge{
    int u, v, c;
};

int parent[MAXN];

int Find_Set(int u)
{
    while(parent[u] > 0)    u = parent[u];
    return u;
}

void Union(int u, int v)
{
    int x = parent[u] + parent[v];
    if(parent[u] > parent[v])
    {
        parent[u] = v;
        parent[v] = x;
    }else{
        parent[u] = x;
        parent[v] = u;
    }
}


int main(){
    _io
    freopen(PROB".inp", "r", stdin);
    freopen(PROB".out", "w", stdout);
    int t; cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        vector <edge> edges;
        fill(parent+1, parent+1+n, -1);
        FOR(i, 1, m){
            int u, v, c;
            cin >> u >> v >> c;
            edges.pb({u, v, c - k});
        }
        sort(edges.begin(), edges.end(), [](const edge &A, const edge &B){
                return A.c < B.c;
             });
        int Max = INT_MIN;
        ll res = 0;
        int fi_pos = INT_MAX;
        REP(i, 0, m){
            int u = edges[i].u;
            int v = edges[i].v;
            int U = Find_Set(u);
            int V = Find_Set(v);
            if(U == V){
                fi_pos = min(fi_pos, abs(edges[i].c));
                continue;
            }
            Union(U, V);
            if(edges[i].c > 0)
                res += edges[i].c;
            Max = max(Max, edges[i].c);
        }
        //cout << Max << ' ' << fi_pos <<  '\n';
        if(Max < 0)
            cout << min(-Max, fi_pos) << '\n';
        else cout << res << '\n';
    }
}
