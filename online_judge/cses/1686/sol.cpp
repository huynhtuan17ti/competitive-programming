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
vector <int> Gv2[MAXN];
int w[MAXN];
int low[MAXN], num[MAXN], SCC[MAXN];
ll wSCC[MAXN];
int cntTime = 0, cntSCC = 0;
stack <int> st;

void DFS(int u){
    num[u] = low[u] = ++cntTime;
    st.push(u);
    for(int v: G[u])
        if(num[v])
            low[u] = min(low[u], num[v]);
        else{
            DFS(v);
            low[u] = min(low[u], low[v]);
        }
    if(low[u] == num[u]){
        int v;
        cntSCC++;
        do{
            v = st.top();
            st.pop();
            SCC[v] = cntSCC;
            wSCC[cntSCC] += w[v];
            low[v] = num[v] = INT_MAX;
        }while(u != v);
    }
}

void DFS_topo(int u){
    num[u] = 1;
    for(int v: Gv2[u])
        if(!num[v])
            DFS_topo(v);
    st.push(u);
}

int main(){
    io
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> w[i];
    while(m--){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
    }
    // using tarjan's algorithm to find SCC
    for(int i = 1; i <= n; i++)
        if(!num[i]) DFS(i);
    
    // build new graph
    for(int u = 1; u <= n; u++)
        for(int v: G[u])
            if(SCC[u] != SCC[v])
                Gv2[SCC[u]].push_back(SCC[v]);

    fill(num+1, num+1+n, false);
    while(!st.empty())  st.pop();
    for(int i = 1; i <= cntSCC; i++)
        if(!num[i])
            DFS_topo(i);
    
    vector <ll> dp(cntSCC+1);
    while(!st.empty()){
        int u = st.top();
        st.pop();
        dp[u] += wSCC[u];
        for(int v: Gv2[u])
            dp[v] = max(dp[v], dp[u]);
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
}