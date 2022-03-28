/**
 *    author:    hungt1
 *    created:   26-03-2022   12:22:49
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
const int dx[8] = {-2, -2, -2, 0, 0, 2, 2, 2};
const int dy[8] = {-2, 0, 2, -2, 2, -2, 0, 2};
 
struct Matrix {
    vector<vector<int>> mat;
    int n;
 
    Matrix(int n = 0, int val = 0) : n(n) {
        mat.resize(n, vector<int> (n, 0));
        for (int i = 0; i < n; i++) mat[i][i] = val;
    }
 
    Matrix(const vector<vector<int>> other) : n(other.size()) {
        mat = other;
    }
 
    Matrix operator * (const Matrix& other){
        Matrix ans(n);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                for (int k = 0; k < n; k++){
                    ans.mat[i][j] += 1ll * mat[i][k] * other.mat[k][j] % MOD;
                    ans.mat[i][j] %= MOD;
                }           
            }
        }
        return ans;
    };
};
 
Matrix power(Matrix x, long n){
    if (n == 0) return Matrix(x.n, 1);
    Matrix y = power(x, n / 2);
    y = y * y;
    if (n % 2) return y * x;
    return y;
}
 
void solve(){
    int n; cin >> n;
    int x, y, a, b; cin >> x >> y >> a >> b; 
    //x--; y--; a--; b--;
    long k; cin >> k;
 
    vector<vector<int>> mat(n * n, vector<int> (n * n, 0));
    for (int u = 0; u < n; u++){
        for (int v = 0; v < n; v++){
            for (int i = 0; i < 8; i++){
                int x = u + dx[i];
                int y = v + dy[i];
                if (n <= 2) {
                    x = u; y = v;
                    mat[u * n + v][x * n + y] = 1;
                    continue;
                }
                if (x < 0) x = -x;
                if (x >= n) x = 2 * (n - 1) - x;
                if (y < 0) y = -y;
                if (y >= n) y = 2 * (n - 1) - y;
                mat[u * n + v][x * n + y] = 1;
            }
        }
    }
 
    Matrix ans(mat);
    ans = power(ans, k);
    cout << ans.mat[x * n + y][a * n + b] << '\n';
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