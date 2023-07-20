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
constexpr ll INF = 1e15;

bool stop = false;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<ll>> G(n, vector<ll>(n, INF));
    for(int i = 0; i < n; ++i) G[i][i] = 0;
    if(n == 0) {
        stop = true;
        return;
    }
    while(m--) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u][v] = min(G[u][v], 1LL*w);
    }

    // floyd
    for(int k = 0; k < n; ++k)
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j) {
                if(G[i][k] != INF && G[k][j] != INF && G[i][j] > G[i][k] + G[k][j]) {
                    G[i][j] = G[i][k] + G[k][j];
                }
            }

    // check negative cycles
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            for(int k = 0; k < n; ++k)
                if(G[i][k] != INF && G[k][j] != INF && G[k][k] < 0)
                    G[i][j] = -INF;
    
    while(q--) {
        int u, v;
        cin >> u >> v;
        if(u == v) {
            cout << (G[u][v] < 0 ? "-Infinity" : "0") << '\n';
        }else {
            if(G[u][v] == INF) {
                cout << "Impossible" << '\n';
            }else if(G[u][v] == -INF)
                cout << "-Infinity" << '\n';
            else cout << G[u][v] << '\n';
        }
    }
    cout << '\n';
}

int main() {
    io
    while(!stop) {
        solve();
    }
}
