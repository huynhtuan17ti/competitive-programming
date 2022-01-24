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

vector <int> G[MAXN];
int matchL[MAXN], matchR[MAXN];
int dist[MAXN];

bool BFS(int n){
    queue <int> Q;
    for(int i = 1; i <= n; i++){
        if(matchL[i] == 0){
            dist[i] = 0;
            Q.push(i);
        }else dist[i] = INT_MAX;
    }
    dist[0] = INT_MAX;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        if(u == 0)    continue;
        for(int v: G[u])
            if(dist[matchR[v]] == INT_MAX){
                dist[matchR[v]] = dist[u] + 1;
                Q.push(matchR[v]);
            }
    }
    return (dist[0] != INT_MAX);
}
 

bool DFS(int u){
    if(u == 0)  return true;
    for(int v: G[u])
        if(dist[matchR[v]] == dist[u] + 1){
            if(DFS(matchR[v])){
                matchL[u] = v;
                matchR[v] = u;
                return true;
            }
        }
    dist[u] = INT_MAX;
    return false;
}

int main(){
    io
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    while(k--){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
    }

    int matching = 0;
    while(BFS(n)){
        for(int i = 1; i <= n; i++)
            if(matchL[i] == 0 && DFS(i))    matching++;
    }
    cout << matching << '\n';
    for(int i = 1; i <= n; i++)
        if(matchL[i] > 0)
            cout << i << ' ' << matchL[i] << '\n';
}