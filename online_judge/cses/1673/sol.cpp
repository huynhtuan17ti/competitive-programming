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
vector <int> G[MAXN][2];
const ll inf = 1e15;

int vi[MAXN][2];

void DFS(int u, int t){
    vi[u][t] = 1;
    for(int v: G[u][t])
        if(!vi[v][t])
            DFS(v, t);
}

int main(){
    io
    int n, m;
    cin >> n >> m;
    typedef pair <ii, int> edge;
    vector <edge> edges;
    while(m--){
        int u, v, c;
        cin >> u >> v >> c;
        G[u][0].push_back(v);
        G[v][1].push_back(u);
        edges.push_back({mp(u, v), c});
    }
    DFS(1, 0);
    DFS(n, 1);
    auto bellmanFord = [&](int src) -> ll{
        vector <ll> dist(n+1, -inf);
        dist[src] = 0;
        for(int i = 1; i < n; i++)
            for(edge e: edges){
                int u = e.fi.fi;
                int v = e.fi.se;
                int c = e.se;
                if(dist[v] < dist[u] + c)
                    dist[v] = dist[u] + c;
            }

        for(edge e: edges){
            int u = e.fi.fi;
            int v = e.fi.se;
            int c = e.se;
            if(dist[v] < dist[u] + c){
                dist[v] = dist[u] + c;
                if(vi[v][0] && vi[v][1]) // contain cycle on single path from 1 to n
                    return -1;
            }
        }
        return dist[n];
    };

    cout << bellmanFord(1);
}