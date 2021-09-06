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
const int MAXN = 1e5+5;
const ll inf = 1e15;
ll a[MAXN];

struct node{
    ll min, max;
    node(){
        min = inf;
        max = -inf;
    }
    node(ll x, ll y){
        min = x;
        max = y;
    }
};

template <typename T>
class SegmentTree{
    T blank;
    
    vector <node> IT;
    
    public:
        SegmentTree(int n, T blank){
            IT.resize(4*n+5);
            this->blank = blank;
            build(1, 1, n);
        }

        void build(int id, int l, int r){
            if(l == r){
                IT[id].min = IT[id].max = a[l];
                return;
            }
            int mid = (l+r) >> 1;
            build(2*id, l, mid);
            build(2*id+1, mid+1, r);
            IT[id].max = max(IT[2*id].max, IT[2*id+1].max);
            IT[id].min = min(IT[2*id].min, IT[2*id+1].min);
        }

        void update(int id, int l, int r, int i, int val){
            if(i < l || r < i)
                return;
            if(l == r && l == i){
                a[l] = val;
                IT[id].min = IT[id].max = a[l];
                return;
            }
            int mid = (l+r) >> 1;
            update(2*id, l, mid, i, val);
            update(2*id+1, mid+1, r, i, val);
            IT[id].max = max(IT[2*id].max, IT[2*id+1].max);
            IT[id].min = min(IT[2*id].min, IT[2*id+1].min);
        }

        node get(int id, int l, int r, int u, int v){
            if(v < l || r < u)
                return node(inf, -inf);
            if(u <= l && r <= v)
                return IT[id];
            int mid = (l+r) >> 1;
            node L = get(2*id, l, mid, u, v);
            node R = get(2*id+1, mid+1, r, u, v);
            node res;
            res.max = max(L.max, R.max);
            res.min = min(L.min, R.min);
            return res;
        }
};

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    vector <int> p(n+1);
    for(int i = 1; i <= n; i++){
        cin >> p[i];
    }

    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        p[i] = p[i] - x;
        a[i] = a[i-1] + p[i];
    }

    SegmentTree <ll> st(n, 0);

    while(q--){
        int l, r;
        cin >> l >> r;
        node val = st.get(1, 1, n, l, r);
        ll Max = val.max, Min = val.min;
        if(Max - a[l-1] > 0 || a[r] - a[l-1] != 0){
            cout << -1 << '\n';
        }else{
            cout << abs(Min - a[l-1]) << '\n';
        }
    }
}