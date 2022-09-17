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

int vi[MAXN], inSt[MAXN], dist[MAXN], p[MAXN];
int maxCycle = 0;

void DFS(int u){
    vi[u] = inSt[u] = 1;
    for(int v: G[u]){
        if(inSt[v] && v != p[u]){
            maxCycle = max(maxCycle, dist[u] - dist[v] + 1);
        }
        if(!vi[v]){
            dist[v] = dist[u] + 1;
            p[v] = u;
            DFS(v);
        }
    }
    inSt[u] = 0;
}

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++){
        G[i].clear();
        vi[i] = inSt[i] = dist[i] = p[i] = 0;
    }
    while(m--){
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    maxCycle = 0;
    DFS(1);
    cout << maxCycle << '\n';
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int t; cin >> t;
    while(t--){
        solve();
    }
}