#include <bits/stdc++.h>  
using namespace std;

const int MOD = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
#define mp make_pair
#define fi first
#define se second
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
const int MAXN = 5e5 + 5;
const ll inf = 1e15;
vii G[MAXN];
int vi[MAXN];

stack <int> st;
void DFS(int u){
    vi[u] = 1;
    for(auto [v, c]: G[u])
        if(!vi[v])
            DFS(v);
    st.push(u);
}

int main(){
    io
    //freopen("test.inp", "r", stdin);
    int n, m;
    cin >> n >> m;
    while(m--){
        int u, v, c;
        cin >> u >> v >> c;
        G[u].push_back({v, c});
    }
    // Toposort
    DFS(1);
    vector <vector <ll>> dp(n+1, vector <ll>(5));
    /*
        0: minimum price
        1: number of ways
        2: minimum flights
        3: maximum flights 
    */
    for(int i = 1; i <= n; i++)
        dp[i][0] = dp[i][2] = inf;

    dp[1][0] = 0;
    dp[1][1] = 1;
    dp[1][2] = 0;

    priority_queue <pll, vector <pll>, greater <pll>> pq;
    pq.push({0, 1});
    while(!pq.empty()){
        auto [len, u] = pq.top();
        //cerr << u << ' ' << len << '\n';
        pq.pop();

        if(len != dp[u][0])
            continue;

        for(auto [v, c]: G[u])
            if(dp[u][0] + c < dp[v][0]){
                dp[v][0] = dp[u][0] + c;
                dp[v][1] = dp[u][1];
                    
                dp[v][2] = dp[u][2] + 1;
                dp[v][3] = dp[u][3] + 1;
                pq.push({dp[v][0], v});
            }else if(dp[u][0] + c == dp[v][0]){
                dp[v][1] = (dp[v][1] + dp[u][1])%MOD;
                dp[v][2] = min(dp[v][2], dp[u][2] + 1);
                dp[v][3] = max(dp[v][3], dp[u][3] + 1);
            }
    }
    for(int t = 0; t < 4; t++)
        cout << dp[n][t] << ' ';
}