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
    io
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
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
            //cerr << '(' << u << ", " << v << ") ";
            f[u][v] += flow;
            f[v][u] -= flow;
        }
        //cerr << flow << '\n';
        max_flow += flow;
    }
    cout << max_flow << '\n';
}