#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>  
using namespace std;
 
constexpr int MOD = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define mp make_pair
#define fi first
#define se second
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};
constexpr int MAXN = 3e5 + 5;

vector<int> G[MAXN];

int main() {
    io
    int N, M;
    cin >> N >> M;
    for(int i = 1; i <= M; ++i) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    using Query = tuple<int, int, int>;
    vector<Query> queries;
    int Q; cin >> Q;
    for(int u, d, c; Q--; ) {
        cin >> u >> d >> c;
        queries.push_back({u, d, c});
    }

    vector<int> color(N+1);
    vector<vector<bool>> state(N+1, vector<bool> (11));
    function<void(int, int, int)> dfs = [&](int u, int d, int c) -> void {
        if(d < 0) return;
        if(state[u][d] == 1)
            return;
        if(color[u] == 0) color[u] = c;
        for(int v: G[u])
            dfs(v, d - 1, c);
        state[u][d] = 1;
    };

    reverse(queries.begin(), queries.end());
    for(auto &[u, d, c]: queries) {
        dfs(u, d, c); 
    }
    for(int i = 1; i <= N; ++i)
        cout << color[i] << '\n';
}
