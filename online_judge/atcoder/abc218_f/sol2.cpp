#include <bits/stdc++.h>  
using namespace std;
#include <bits/extc++.h>
 
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

vii G[MAXN]; 

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector <int> ans(m+1, 0);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back({v, i});
    }
    auto bfs = [&](int x){
        vector <int> dist(n+1, -1);
        vii par(n+1, mp(0, 0));
        queue <int> Q;
        Q.push(1);
        dist[1] = 0;
        while(!Q.empty()){
            int u = Q.front();
            Q.pop();
            for(auto [v, c] : G[u]){
                if(c == x)
                    continue;
                if(dist[v] == -1){
                    dist[v] = dist[u] + 1;
                    par[v] = {u, c};
                    Q.push(v);
                }
            }
        }

        if(x == -1 && dist[n] != -1){
            int v = n;
            while(v > 1){
                auto [pre, c] = par[v];
                ans[c] = -1;
                v = pre;
            }
        }
        return dist[n];
    };

    int min_dist = bfs(-1);
    for(int i = 0; i < m; i++){
        if(ans[i] == 0){
            cout << min_dist << '\n';
        }else cout << bfs(i) << '\n';
    }
}