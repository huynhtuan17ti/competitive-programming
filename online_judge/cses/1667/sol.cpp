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
const int inf = 1e9;

int main(){
    io
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector <vector <int>> G(n+1);
    while(m--){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector <int> trace(n+1);

    auto bfs = [&](int u){
        queue <int> q;
        vector <int> len(n+1, inf);

        q.push(u);
        len[u] = 0;

        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v: G[u])
                if(len[v] > len[u] + 1){
                    len[v] = len[u] + 1;
                    trace[v] = u;
                    q.push(v);
                }
        }
    };

    bfs(1);

    if(trace[n] == 0){
        return cout << "IMPOSSIBLE" << '\n', 0;
    }
    
    vector <int> path;
    for(int v = n; v > 0; v = trace[v])
        path.push_back(v);
    
    reverse(path.begin(), path.end());
    cout << path.size() << '\n';
    for(int u: path)
        cout << u << ' ';
}