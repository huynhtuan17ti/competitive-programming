#include <bits/stdc++.h>  
using namespace std;
 
constexpr int MOD = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<pll> vpll;
#define mp make_pair
#define fi first
#define se second
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};
constexpr int MAXN = 5e5 + 5;

int W[MAXN];
bool IsBlack[MAXN];

int main() {
    int n, m;
    cin >> n >> m;

    using AdjEdge = pair<int, int>;
    using AdjSet = set<AdjEdge>;
    vector<vector<AdjSet>> G(n+1, vector<AdjSet>(2));

    vii edges;
    edges.push_back({0, 0});
    for(int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v});
        W[i] = w;
    }

    int k; cin >> k;
    for(int i = 1; i <= k; ++i) {
        int u; cin >> u;
        IsBlack[u] = 1;
    }
    for(int i = 1; i <= m; ++i) {
        auto [u, v] = edges[i];
        G[u][0].insert({W[i], i});
        if(IsBlack[v] == 0)
            G[u][1].insert({W[i], i});
    }

    int s, t; cin >> s >> t;
    edges[0].se = s;
    
    vector<vector<ll>> dp(m+1, vector<ll>(2, LLONG_MAX));
    using Item = tuple<ll, int, int>;
    priority_queue<Item, vector<Item>, greater<Item>> pq;
    pq.push({0, 0, IsBlack[s]});
    dp[0][IsBlack[s]] = 0;
    while(!pq.empty()) {
        auto [len, cur_id, c] = pq.top();
        auto [_, u] = edges[cur_id];
        pq.pop();
        
        auto it = G[u][c].lower_bound(mp((W[cur_id] + 1)/2, -1));
        while(it != G[u][c].end() && (cur_id == 0 || W[cur_id] * 2 >= (*it).fi)) {
           int nxt_id = (*it).se; 
            int nxt_w = W[nxt_id];
            int nxt_c = c;
            if(IsBlack[edges[nxt_id].se] == 1) nxt_c = 1;
            if(dp[nxt_id][nxt_c] > dp[cur_id][c] + nxt_w) {
                dp[nxt_id][nxt_c] = dp[cur_id][c] + nxt_w;
                pq.push({dp[nxt_id][nxt_c], nxt_id, nxt_c});
            }
            it = G[u][c].erase(it); 
        }
    }

    ll res = LLONG_MAX;
    for(int i = 1; i <= m; ++i) {
        auto [u, v] = edges[i];
        if(v == t) res = min(res, dp[i][1]);
    }
    if(res == LONG_MAX)
        res = -1;
    cout << res << '\n';
}
