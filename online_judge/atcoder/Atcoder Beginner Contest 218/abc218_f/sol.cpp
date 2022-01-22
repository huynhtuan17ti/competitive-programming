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
const int MAXN = 405;
 
vector <int> G[2][MAXN];
 
void BFS(int t, int n, int start, ll dist[], ll ways[]){
    for(int i = 1; i <= n; i++){
        dist[i] = INT_MAX;
        ways[i] = 0;
    }
    queue <int> Q;
    Q.push(start);
    dist[start] = 0;
    ways[start] = 1;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        for(int v: G[t][u]){
            if(dist[v] == dist[u] + 1){
                ways[v] += ways[u];
            }
            if(dist[v] > dist[u] + 1){
                dist[v] = dist[u] + 1;
                ways[v] = ways[u];
                Q.push(v);
            }
        }
    }
}
 
ll BFS2(int n, ii edge){
    vector <ll> dist(n+1, INT_MAX);
    queue <int> Q;
    Q.push(1);
    dist[1] = 0;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        for(int v: G[0][u]){
            if(u == edge.fi && v == edge.se)
                continue;
            if(dist[v] > dist[u] + 1){
                dist[v] = dist[u] + 1;
                Q.push(v);
            }
        }
    }
    if(dist[n] == INT_MAX)
        return -1;
    return dist[n];
}
 
ll dist1[MAXN];
ll dist2[MAXN];
 
ll ways1[MAXN], ways2[MAXN];
 
int main(){
    io
    int n, m;
    cin >> n >> m;
    vii edges;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
        G[0][u].push_back(v);
        G[1][v].push_back(u);
    }
    BFS(0, n, 1, dist1, ways1);
    BFS(1, n, n, dist2, ways2);
 
    for(ii e: edges){
        int u = e.fi, v = e.se;
        ll min_dist = min(dist1[u] + dist2[v], dist2[u] + dist1[v]) + 1;
        if(min_dist == dist1[n] && ways1[u]*ways2[v] == ways1[n]){
            cout << BFS2(n, e) << '\n';
        }else if(min_dist == dist1[n]){
            cout << ((min_dist == INT_MAX)? -1: min_dist) << '\n';
        }else{
            cout << ((dist1[n] == INT_MAX)? -1: dist1[n]) << '\n';
        }
    }
}