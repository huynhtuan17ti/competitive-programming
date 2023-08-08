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
constexpr int dx[] = {-1, 1, 0, 0, 0};
constexpr int dy[] = {0, 0, -1, 1, 0};
constexpr int INF = 1e9;
constexpr int MAXN = 100;

char state[51][25][51];
int dp[51][25][51];

inline void solve() {
    int max_round; cin >> max_round;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n+2; ++i) {
        for(int j = 0; j < m; ++j)
            cin >> state[0][i][j];
    }

    bool is_right = true;
    for(int i = n; i >= 1; --i) {
        for(int s = 1; s < m; ++s) {
            if(is_right)
                for(int j = 0; j < m; ++j)
                    state[s][i][j] = state[s-1][i][(j-1+m)%m];
            else
                for(int j = 0; j < m; ++j)
                    state[s][i][j] = state[s-1][i][(j+1)%m];
        }
        is_right = 1 - is_right;
    }

    for(int s = 1; s < m; ++s)
        for(int j = 0; j < m; ++j) {
            state[s][0][j] = state[0][0][j];
            state[s][n+1][j] = state[0][n+1][j];
        }

    //for(int i = 0; i <= n+1; ++i)
        //for(int j = 0; j < m; ++j)
            //cout << state[2][i][j] << " \n"[j == m-1];

    
    auto check = [&](int id, int u, int v) {
        return (0 <= u && u <= n+1 && 0 <= v && v < m && state[id][u][v] != 'X');
    };

    for(int s = 0; s < m; ++s) 
        for(int i = 0; i < n+2; ++i)
            for(int j = 0; j < m; ++j) {
                dp[s][i][j] = INF;
            }
    
    using Cell = tuple<int, int, int>;
    queue<Cell> Q;
    for(int j = 0; j < m; ++j) 
        if(state[0][n+1][j] == 'F') {
            Q.emplace(0, n+1, j);
            dp[0][n+1][j] = 0;
        }

    while(!Q.empty()) {
        auto [id, u, v] = Q.front();
        Q.pop();

        int nxt_id = (id + 1) % m;
        for(size_t k = 0; k < 5; ++k) {
            int nu = u + dx[k], nv = v + dy[k];
            if(check(nxt_id, nu, nv) && dp[nxt_id][nu][nv] > dp[id][u][v] + 1) {
                dp[nxt_id][nu][nv] = dp[id][u][v] + 1;
                Q.emplace(nxt_id, nu, nv);
            }
        }
    }

    int ans = INF;
    for(int j = 0; j < m; ++j)
        if(state[0][0][j] == 'G') {
            for(int s = 0; s < m; ++s)
                ans = min(ans, dp[s][0][j]);
        }
    if (ans > max_round)
        cout << "The problem has no solution." << '\n';
    else
        cout << "The minimum number of turns is " << ans << ".\n";
}

int main() {
    io
    int t; cin >> t;
    while(t--) {
        solve();
    }
}
