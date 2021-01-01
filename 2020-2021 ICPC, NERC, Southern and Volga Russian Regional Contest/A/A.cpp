/* Tuan Kkura */
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define base 31
#define MOD 1e9+7
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORs(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, a, b) for(int i = a; i < b; i++)
#define __FOR(i, a, b, k) for(int i = a; i <= b; i+= k)
#define __REP(i, a, b, k) for(int i = a; i < b; i+= k)
#define pb push_back
#define _io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

typedef pair <int, int> ii;
typedef vector <ii> vii;
#define fi first
#define se second
#define mp make_pair
#define PROB "A"
#define MAXN 500005
#define MAX_VAL 500000
int bit[MAXN];
int trace[MAXN];
int a[MAXN];

void update(int id, int i, int val){
    while(id <=  MAX_VAL){
        if(bit[id] < val){
            bit[id] = val;
            trace[id] = i;
        }
        id += id&(-id);
    }
}

ii get(int id){
    int ans = 0;
    int pos = MAX_VAL;
    while(id >= 1){
        if(ans < bit[id]){
            ans = bit[id];
            pos = trace[id];
        }
        if(ans == bit[id])
            pos = min(pos, trace[id]);
        id -= id&(-id);
    }
    return {ans, pos};
}

int IT[4*MAXN];

void updateIT(int id, int l, int r){
    if(l == r){
        IT[id] = a[l];
        return;
    }
    int mid = (l+r) >> 1;
    updateIT(2*id, l, mid);
    updateIT(2*id+1, mid+1, r);
    IT[id] = max(IT[2*id], IT[2*id+1]);
}

int getIT(int id, int l, int r, int u, int v){
    if(v < l || r < u)
        return 0;
    if(u <= l && r <= v)
        return IT[id];
    int mid = (l+r) >> 1;
    int L = getIT(2*id, l, mid, u, v);
    int R = getIT(2*id+1, mid+1, r, u, v);
    return max(L, R);
}

int main(){
    _io
    freopen(PROB".inp", "r", stdin);
    freopen(PROB".out", "w", stdout);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector <int> S;
        FOR(i, 1, n){
            cin >> a[i];
            S.pb(a[i]);
        }
        S.pb(0);
        sort(S.begin(), S.end());
        S.resize(unique(S.begin(), S.end()) - S.begin());
        FOR(i, 1, n)
            a[i] = lower_bound(S.begin(), S.end(), a[i]) - S.begin();
        fill(bit, bit+1+n, 0);
        fill(trace, trace+1+n, 0);
        updateIT(1, 1, n);
        update(1, 0, 0);
        int res = 0;
        FOR(i, 1, n){
            ii val = get(a[i]);
            int max_len = val.fi + 1;
            if(val.se+1 <= i-1 && getIT(1, 1, n, val.se+1, i-1) >= max(a[val.se], a[i]))
                max_len ++;
            //cout << i << ' ' << val.fi << ' ' << val.se << '\n';
            res = max(res, max_len);
            update(a[i], i, max_len);
        }
        cout << res << '\n';
    }
}
