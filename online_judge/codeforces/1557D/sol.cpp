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
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int MAXN = 6e5 + 5;

vii seg[MAXN];
int trace[MAXN];

ii _max(ii a, ii b){
    if(a.fi > b.fi)
        return a;
    return b;
}

ii IT[4*MAXN];
ii lazy[4*MAXN];

void down(int id){
    ii k = lazy[id];
    if(k.fi == 0)
        return;
    IT[2*id] = max(IT[2*id], k);
    lazy[2*id] = max(lazy[2*id], k);
    IT[2*id+1] = max(IT[2*id+1], k);
    lazy[2*id+1] = max(lazy[2*id+1], k);

    lazy[id] = {0, 0};
}

void update(int id, int l, int r, int u, int v, ii val){
    if(v < l || r < u)
        return;
    if(u <= l && r <= v){
        IT[id] = _max(IT[id], val);
        lazy[id] = _max(lazy[id], val);
        return;
    }
    down(id);
    int mid = (l+r) >> 1;
    update(2*id, l, mid, u, v, val);
    update(2*id+1, mid+1, r, u, v, val);
    IT[id] = max(IT[2*id], IT[2*id+1]);
}

ii get(int id, int l, int r, int u, int v){
    if(v < l || r < u)
        return {0, 0};
    if(u <= l && r <= v){
        return IT[id];
    }
    down(id);
    int mid = (l+r) >> 1;
    ii L = get(2*id, l, mid, u, v);
    ii R = get(2*id+1, mid+1, r, u, v);
    return _max(L, R);
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector <int> S;
    while(m--){
        int i, l, r;
        cin >> i >> l >> r;
        seg[i].push_back({l, r});
        S.push_back(l);
        S.push_back(r);
    }
    S.push_back(INT_MIN);
    sort(S.begin(), S.end());
    S.resize(unique(S.begin(), S.end()) - S.begin());
    int sz = S.size();

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < seg[i].size(); j++){
            seg[i][j].fi = lower_bound(S.begin(), S.end(), seg[i][j].fi) - S.begin();
            seg[i][j].se = lower_bound(S.begin(), S.end(), seg[i][j].se) - S.begin();
        }
    }
    int len = 0, res = 0;
    for(int i = 1; i <= n; i++){
        ii Max = {0, 0};
        for(ii u: seg[i]){
            Max = _max(Max, get(1, 1, sz, u.fi, u.se));
        }
        for(ii u: seg[i]){
            update(1, 1, sz, u.fi, u.se, {Max.fi+1, i});
        }
        trace[i] = Max.se;
        if(len < Max.fi+1){
            len = Max.fi+1;
            res = i;
        }
    }
    vector <int> p;
    int u = res;
    vector <int> vi(n+1, 0);
    while(u > 0){
        p.push_back(u);
        vi[u] = 1;
        u = trace[u];
    }
    cout << n - len << '\n';
    for(int i = 1; i <= n; i++)
        if(!vi[i])
            cout << i << ' ';
}

int main(){
    io
    int t; t = 1;
    while(t--){
        solve();
    }
}