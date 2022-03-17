#include <bits/stdc++.h>  
typedef long long ll;
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
#define mp make_pair
#define fi first
#define se second
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int MAXN = 5e5 + 5;

vector <int> G[MAXN];

int num[MAXN], low[MAXN];
int numChild[MAXN];
int cntTime = 0;

map <ii, bool> bridge;

void DFS(int u, int p){
    num[u] = low[u] = ++cntTime;
    numChild[u] = 1;

    for(int v: G[u]){
        if(v == p)
            continue;
        if(num[v])
            low[u] = min(low[u], num[v]);
        else{
            DFS(v, u);
            low[u] = min(low[u], low[v]);
            numChild[u] += numChild[v];
            if(low[v] > num[u])
                bridge[mp(u, v)] = true;
        }
    }
}


int main(){
    io
    int n, m;
    cin >> n >> m;
    vii edges;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int cntCmp = 0;
    // tarjan
    for(int i = 1; i <= n; i++)
        if(!num[i]){
            cntCmp++;
            DFS(i, 0);
        }

    if(cntCmp >= 3)
        return cout << 0, 0;

    if(cntCmp == 2)
        return cout << 1LL*(m-bridge.size())*numChild[1]*(n - numChild[1]), 0;

    ll ans = 0;
    for(auto it: bridge){
        auto [u, v] = it.fi;
        int child = min(numChild[u], numChild[v]);
        ans += 1LL*(n - child)*child - 1;
    }
    ans += 1LL*(m-bridge.size())*(1LL*n*(n-1)/2 - m);
    cout << ans << '\n';
}
