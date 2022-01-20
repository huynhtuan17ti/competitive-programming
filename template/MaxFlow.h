#include <bits/stdc++.h>  
using namespace std;

typedef long long ll;
const int MAXN = 505;
const ll inf = 1e13;

vector <int> G[MAXN];
ll c[MAXN][MAXN];
ll f[MAXN][MAXN];
ll len[MAXN]; int trace[MAXN], Set[MAXN];

bool short_paths(int s, int e, int n){
    fill(len+1, len+1+n, inf);
    fill(Set+1, Set+1+n, 2);
    deque <int> Q;
    Q.push_back(s); len[s] = 0;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop_front();
        Set[u] = 0;
        for(int v: G[u]){
            ll cost = (f[u][v] >= 0)? 1 : -1;
            if(c[u][v] > f[u][v] && len[v] > len[u] + cost){
                len[v] = len[u] + cost;
                trace[v] = u;
                if(Set[v] == 0){
                    Set[v] = 1;
                    Q.push_front(v);
                }
                if(Set[v] == 2){
                    Set[v] = 1;
                    Q.push_back(v);
                }
            }
        }
    }
    return (len[e] != inf);
}

int main(){
    int n, m;
    cin >> n >> m;
    while(m--){
        int u, v, w;
        cin >> u >> v >> w;
        if(c[u][v] != 0){
            c[u][v] += w;
            continue;
        }
        G[u].push_back(v);
        G[v].push_back(u);
        c[u][v] = w;
    }

    ll max_flow = 0;
    int s = 1, e = n;
    while(short_paths(1, n, n)){
        ll flow = inf;
        for(int v = e; v != s; v  = trace[v]){
            int u = trace[v];
            flow = min(flow, c[u][v] - f[u][v]);
        }
        for(int v = e; v != s; v  = trace[v]){
            int u = trace[v];
            f[u][v] += flow;
            f[v][u] -= flow;
        }
        max_flow += flow;
    }
    cout << max_flow << '\n';
}