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
vii G[MAXN];
vii P[MAXN];
int xorSum[MAXN];
bool vi[MAXN];
bool isAnswer = true;

void DFS(int u){
    vi[u] = 1;
    for(auto [v, c]: G[u]){
        if(c == -1)
            continue;
        if(!vi[v]){
            xorSum[v] = (xorSum[u]^c);
            DFS(v);
        }else{
            int val = xorSum[u]^c;
            if(val != xorSum[v])
                isAnswer = false;
        }
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    typedef pair <ii, int> edge;
    vector <edge> edges;
    for(int i = 1; i <= n; i++)
        G[i].clear();
    isAnswer = true;
    fill(xorSum+1, xorSum+1+n, 0);
    fill(vi+1, vi+1+n, 0);
    for(int i = 1; i < n; i++){
        int u, v, c;
        cin >> u >> v >> c;
        edges.push_back({mp(u, v), c});
        if(c != -1)
            c = __builtin_popcount(c)%2;
        
        G[u].push_back({v, c});
        G[v].push_back({u, c});
    }

    while(m--){
        int a, b, c;
        cin >> a >> b >> c;

        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }

    for(int i = 1; i <= n; i++){
        if(!vi[i])
            DFS(i);
    }

    if(!isAnswer)
        cout << "NO" << '\n';
    else{
        cout << "YES" << '\n';
        for(edge e: edges){
            int u = e.fi.fi;
            int v = e.fi.se;

            if(e.se == -1){
                cout << e.fi.fi << ' ' << e.fi.se << ' ' << (xorSum[v]^xorSum[u]) << '\n';
            }else{
                cout << e.fi.fi << ' ' << e.fi.se << ' ' << e.se << '\n';
            }
        }
    }
}

int main(){
    io
    int t; cin >> t;
    while(t--){
        solve();
    }
}