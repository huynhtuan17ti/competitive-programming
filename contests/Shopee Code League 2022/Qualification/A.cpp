/**
 *    author:    hungt1
 *    created:   19-03-2022   14:05:11
**/
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using pll = pair<int64_t, int64_t>;
using ld = long double;

#define long int64_t
#define all(c) c.begin(), c.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)

template <class T> inline void chmin(T &a, const T& val) { if (a > val) a = val; }
template <class T> inline void chmax(T &a, const T& val) { if (a < val) a = val; }
template <class T> long sqr(T a) { return 1ll * a * a; }
template <class T> void compress(T &a) { sort(all(a)); a.resize(unique(all(a)) - a.begin()); }
template <class T> T power(T x, long n){
    T res = 1;
    for (; n; x *= x, n >>= 1){
        if (n & 1) res *= x;
    }
    return res;
}

const double pi = acos(-1.00);
const double eps = 1e-6;
const int INF = 2e9;
const int MOD = 1e9 + 7;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

const int M = 256;
vector<pii> block[M];

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> mat(n, vector<int> (m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> mat[i][j];
            if (mat[i][j] != 0){
                block[mat[i][j]].push_back({i, j});
            }
        }
    }


    deque<pii> deq;
    vector<vector<int>> dist(n, vector<int> (m, INF));
    dist[0][0] = 0;
    deq.push_front({0, 0});
    while (!deq.empty()){
        auto [u, v] = deq.front();
        deq.pop_front();
        for (auto [x, y] : block[mat[u][v]]){
            if (dist[x][y] > dist[u][v]){
                dist[x][y] = dist[u][v];
                deq.push_front({x, y});
            }
        }
        block[mat[u][v]].clear();
        for (int i = 0; i < 4; i++){
            int x = u + dx[i], y = v + dy[i];
            if (x < 0 || x >= n || y < 0 || y >= m) continue;
            if (dist[x][y] > dist[u][v] + 1){
                dist[x][y] = dist[u][v] + 1;
                deq.push_back({x, y});
            }
        }
    }
    cout << dist[n - 1][m - 1] << '\n';
}

int main()
{
    fastio;
    int T = 1; //cin >> T;
    while (T--){
        solve();
    }
    return 0;
}