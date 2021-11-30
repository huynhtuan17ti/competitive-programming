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

ll sumRange(int l, int r){
    return 1LL*r*(r+1)/2 - 1LL*l*(l-1)/2;
}

template <typename T>
class LazySegmentTree{
    struct node{
        T sum, lazy_val, lazy_cnt;
        node(){
            sum = lazy_val = lazy_cnt = 0;
        }
    };
    vector <int> a;
    public:
        vector <node> IT;
        LazySegmentTree(int n, vector <int> srcA){
            IT.resize(4*n+5);
            a = srcA;
        }
        void build(int id, int l, int r){
            if(l == r){
                IT[id].sum = a[l];
                return;
            }
            int mid = (l+r) >> 1;
            build(2*id, l, mid);
            build(2*id+1, mid+1, r);
            IT[id].sum = IT[2*id].sum + IT[2*id+1].sum;
        }
        void down(int id, int l, int r){
            T k = IT[id].lazy_val;
            T cnt = IT[id].lazy_cnt;

            int mid = (l+r) >> 1;
            ll leftAdd = k * (mid - l + 1) + sumRange(l, mid) * cnt;
            ll rightAdd = k * (r - mid) + sumRange(mid+1, r) * cnt;

            IT[2*id].sum += leftAdd;
            IT[2*id].lazy_val += k;
            IT[2*id].lazy_cnt += cnt;

            IT[2*id+1].sum += rightAdd;
            IT[2*id+1].lazy_val += k;
            IT[2*id+1].lazy_cnt += cnt;

            IT[id].lazy_val = IT[id].lazy_cnt = 0;
        }
        void update(int id, int l, int r, int u, int v, T val){
            if(v < l || r < u)
                return;
            if(u <= l && r <= v){
                IT[id].sum += 1LL * (r - l + 1) * val + sumRange(l, r);
                IT[id].lazy_val += val;
                IT[id].lazy_cnt ++;
                return;
            }
            down(id, l, r);
            int mid = (l+r) >> 1;
            update(2*id, l, mid, u, v, val);
            update(2*id+1, mid+1, r, u, v, val);
            IT[id].sum = IT[2*id].sum + IT[2*id+1].sum;
        }
        T get(int id, int l, int r, int u, int v){
            if(v < l || r < u)
                return 0;
            if(u <= l && r <= v)
                return IT[id].sum;
            down(id, l, r);
            int mid = (l+r) >> 1;
            T L = get(2*id, l, mid, u, v);
            T R = get(2*id+1, mid+1, r, u, v);
            return L + R;
        }
};

int main(){
    io
    //freopen("test.inp", "r", stdin);
    int n, q;
    cin >> n >> q;
    vector <int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    LazySegmentTree <ll> seg(n, a);
    seg.build(1, 1, n);
    while(q--){
        int t, u, v;
        cin >> t >> u >> v;
        if(t == 1)
            seg.update(1, 1, n, u, v, -(u-1));
        else
            cout << seg.get(1, 1, n, u, v) << '\n';
    }
}