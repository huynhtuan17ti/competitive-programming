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
ii dp[MAXN][2];
vector <int> trace;

void DFS(int u, int pre){
    dp[u][0] = {0, 0};
    dp[u][1] = {1, (int)G[u].size()};

    for(int v: G[u]){
        if(v != pre)
            DFS(v, u);
    }

    for(int v: G[u]){
        if(v != pre){
            dp[u][1].fi += dp[v][0].fi;
            dp[u][1].se += dp[v][0].se;

            if(dp[v][0].fi > dp[v][1].fi){
                dp[u][0].fi += dp[v][0].fi;
                dp[u][0].se += dp[v][0].se;
            }
            if(dp[v][0].fi < dp[v][1].fi){
                dp[u][0].fi += dp[v][1].fi;
                dp[u][0].se += dp[v][1].se;
            }
            if(dp[v][0].fi == dp[v][1].fi){
                dp[u][0].fi += dp[v][0].fi;
                dp[u][0].se += min(dp[v][0].se, dp[v][1].se);
            }
        }
    }
}

void DFS_trace(int u, int pre, int t){
    if(t == 1)
        trace.push_back(u);
    for(int v: G[u])
        if(v != pre){
            if(t == 1)
                DFS_trace(v, u, 0);
            else{
                if(dp[v][0].fi > dp[v][1].fi){
                    DFS_trace(v, u, 0);
                }
                if(dp[v][0].fi < dp[v][1].fi){
                    DFS_trace(v, u, 1);
                }
                if(dp[v][0].fi == dp[v][1].fi){
                    if(dp[v][0].se < dp[v][1].se)
                        DFS_trace(v, u, 0);
                    else DFS_trace(v, u, 1);
                }
            }
        }
}

void solve(){
    int n; cin >> n;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    if(n == 2){
        cout << "2 2" << '\n';
        cout << "1 1" << '\n';
        return;
    }
    DFS(1, 0);
    int maxCnt = max(dp[1][1].fi, dp[1][0].fi);

    // traceback
    if(dp[1][1].fi != dp[1][0].fi)
        DFS_trace(1, 0, (dp[1][1].fi > dp[1][0].fi));
    else{
        DFS_trace(1, 0, (dp[1][1].se < dp[1][0].se));
    }

    //cerr << trace.size() << ' ' << maxCnt << '\n';
    assert(trace.size() == maxCnt);

    vector <int> vi(n+1);
    for(int u: trace)
        vi[u] = 1;
    vector <int> w(n+1);
    
    for(int i = 1; i <= n; i++)
        if(!vi[i])
            w[i] = 1;

    for(int u: trace)
        for(int v: G[u])
            w[u] += w[v];
    
    ll sumW = 0;
    for(int i = 1; i <= n; i++){
        sumW += w[i];
    }
    cout << maxCnt << ' ' << sumW << '\n';
    for(int i = 1; i <= n; i++)
        cout << w[i] << ' ';
    cout << '\n';
}

int main(){
    io
    int t = 1;
    while(t--){
        solve();
    }
}