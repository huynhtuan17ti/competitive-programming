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
const ll inf = 1e14;

int main(){
    io
    int n, m, q;
    cin >> n >> m >> q;
    vector <vector <ll>> G(n+1, vector <ll>(n+1, inf));
    for(int i = 1; i <= n; i++) G[i][i] = 0;
    while(m--){
        int u, v, c;
        cin >> u >> v >> c;
        G[u][v] = G[v][u] = min(G[u][v], 1LL*c);
    }
    // floyd
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
    while(q--){
        int u, v;
        cin >> u >> v;
        cout << ((G[u][v] == inf)? -1: G[u][v]) << '\n';
    }
}