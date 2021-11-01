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
const int INF = 2e9;
const int MOD = 1e9 + 7;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

struct LazySegmentTree {
#define m ((l + r) >> 1)
#define lc (i << 1)
#define rc (i << 1 | 1)
    vector<int> mx, lazy;
    int n;

    LazySegmentTree(int n = 0) : n(n){
        mx.resize(4 * n + 1, 0);
        lazy.resize(4 * n + 1, 0);    
    }

    void push(int i, int l, int r){
        if (lazy[i] == 0) return;
        mx[i] += lazy[i];
        if (l != r){
            lazy[lc] += lazy[i];
            lazy[rc] += lazy[i];
        }  
        lazy[i] = 0;
    }

    void update(int i, int l, int r, int u, int v, int val){
        push(i, l, r);
        if (v < l || r < u) return;
        if (u <= l && r <= v){
            lazy[i] += val;
            push(i, l, r);
            return;
        }  
        update(lc, l, m, u, v, val); update(rc, m + 1, r, u, v, val);
        mx[i] = max(mx[lc], mx[rc]);
    }

    int get(int i, int l, int r, int u, int v){
        push(i, l, r);
        if (v < l || r < u) return -INF;
        if (u <= l && r <= v) return mx[i];
        return max(get(lc, l, m, u, v), get(rc, m + 1, r, u, v));
    }

    void update(int l, int r, int val){
        update(1, 1, n, l, r, val);
    }

    int get(int l, int r){
        return get(1, 1, n, l, r);
    }
#undef m
#undef lc
#undef rc  
};

const int N = 1e5 + 1;
int n, m, color[N];
vector<pii> l[N], r[N];
int ans[N];

int main()
{
    fastio; 
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int x, y, c; cin >> x >> y >> c;
        int type = (c > 0 ? 1 : -1);
        l[x].push_back({type, i});
        r[y].push_back({type, i});
        color[i] = c;
    }
    LazySegmentTree tree(m);
    for (int i = 1; i <= n; i++){
        for (pii add : l[i]){
            tree.update(1, add.second, add.first);
        }
        for (pii rm : r[i - 1]){
            tree.update(1, rm.second, -rm.first);
        }
        int lo = 1, hi = m;
        ans[i] = 0;
        while (lo <= hi){
            int mi = (lo + hi) / 2;
            if (tree.get(mi, m) > 0){
                ans[i] = color[mi];
                lo = mi + 1;
            }
            else {
                hi = mi - 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << ' '; cout << '\n';
    return 0;
}