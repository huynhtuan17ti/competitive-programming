#include <bits/stdc++.h>
using namespace std;

#define long long long
#define db double
#define pii pair <int, int>
#define pll pair <long, long>
#define all(c) c.begin(), c.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

template <class T> inline void chmin(T &a, const T& val) { if (a > val) a = val; }
template <class T> inline void chmax(T &a, const T& val) { if (a < val) a = val; }
template <class T> long sqr(T a) { return 1ll * a * a; }
template <class T> void compress(T &a){
    sort(all(a)); a.resize(unique(all(a)) - a.begin());
}

const db pi = acos(-1.00);
const db eps = 1e-6;
const long INF = 1e18;
const int MOD = 1e9 + 7;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

const int N = 36;
int n, m;
long X, Y, a[N], b[N];
long sumA, sumB, ans;
vector<pll> val;
vector<long> c, d;

struct SegmentTree {
#define m ((l + r) >> 1)
#define lc (i << 1)
#define rc (i << 1 | 1)
    vector<long> mx;
    int n;

    SegmentTree(int n = 0) : n(n){    
        mx.resize(4 * n + 1, 0);
    }

    SegmentTree(const vector<long> &a) : n(a.size()) {
        mx.resize(4 * n + 1, 0);
        function<void(int, int, int)> build = [&](int i, int l, int r){
            if (l == r){
                mx[i] = a[l - 1];
                return;
            }
            build(lc, l, m); build(rc, m + 1, r);
            mx[i] = max(mx[lc], mx[rc]);
        };
        build(1, 1, n);
    }

    long get(int i, int l, int r, int u, int v){
        if (v < l || r < u) return -INF;
        if (u <= l && r <= v) return mx[i];
        return max(get(lc, l, m, u, v), get(rc, m + 1, r, u, v));
    }

    long get(int l, int r){
        return get(1, 1, n, l, r);
    }
#undef m
#undef lc
#undef rc  
} it;

void solve(int l, int r, int type){
    for (int i = 0; i < 2; i++){
        sumA += a[l] * i;
        sumB += b[l] * i;
        if (l < r) solve(l + 1, r, type);
        else {
            if (type == 1) val.push_back({sumA, sumB});
            else {
                int l = lower_bound(all(c), X - sumA) - c.begin() + 1;
                int r = upper_bound(all(c), Y - sumA) - c.begin();
                if (l <= r){
                    chmax(ans, sumB + it.get(l, r));
                }
            }
        }
        sumA -= a[l] * i;
        sumB -= b[l] * i;
    }
}

int main()
{
    fastio;
    cin >> n >> X >> Y;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
    solve(1, n / 2, 1); 
    sort(all(val));
    m = val.size();
    c.resize(m); d.resize(m);
    for (int i = 0; i < m; i++){
        d[i] = val[i].second;
        c[i] = val[i].first;
    }
    it = SegmentTree(d);
    solve(n / 2 + 1, n, 2);
    cout << ans;
    return 0;
}