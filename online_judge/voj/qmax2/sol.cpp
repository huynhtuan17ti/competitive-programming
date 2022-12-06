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
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
const int MAXN = 5e5 + 5;

int n;
int h; // height of tree;
int st[MAXN], lazy[MAXN];

void apply(int id, int value) {
    st[id] += value;
    if(id < n)
        lazy[id] += value;
}

void push(int id) {
    for(int s = h; s >= 1; s--) {
        int i = id >> s;
        if(lazy[i] != 0) {
            apply(i<<1, lazy[i]);
            apply(i<<1|1, lazy[i]);
            lazy[i] = 0;   
        }
    }
}

void build(int id) {
    for(id >>= 1; id >= 1; id >>= 1) {
        st[id] = max(st[id<<1], st[id<<1|1]) + lazy[id];
    }
}

void update(int l, int r, int value) {
    l += n;
    r += n;
    int l0 = l, r0 = r;
    for(; l < r; l >>= 1, r >>= 1) {
        if(l&1) apply(l++, value);
        if(r&1) apply(--r, value);
    }
    build(l0);
    build(r0-1);
}

int query(int l, int r) {
    l += n;
    r += n;
    push(l);
    push(r-1);

    int res = 0;
    for(; l < r; l >>= 1, r >>= 1) {
        if(l&1) res = max(res, st[l++]);
        if(r&1) res = max(res, st[--r]);
    }
    return res;
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int m;
    cin >> n >> m;
    // calc the maximum bit of n
    h = sizeof(int) * 8 - __builtin_clz(n);
    return 0;

    int t, x, y, k;
    while(m--) {
        cin >> t;
        if(t == 0) {
            cin >> x >> y >> k;
            x--; y--;
            update(x, y+1, k);
        }else{
            cin >> x >> y;
            x--; y--;
            cout << query(x, y+1) << '\n';
        }
    }
}