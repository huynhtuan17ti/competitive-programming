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
const int MAXN = 2e5 + 5;
const ll inf = 1e15;
ll sum[MAXN];

template <typename T>
class LazySegmentTree{
    struct node{
        T val, lazy;
        node(){
            val = lazy = 0;
        }
    };
    public:
        vector <node> IT;
        LazySegmentTree(int n){
            IT.resize(4*n+5);
        }
        void build(int id, int l, int r){
            if(l == r){
                IT[id].val = sum[l];
                return;
            }
            int mid = (l+r) >> 1;
            build(2*id, l, mid);
            build(2*id+1, mid+1, r);
            IT[id].val = max(IT[2*id].val, IT[2*id+1].val);
        }
        void push(int id, T val){
            IT[id].val += val;
            IT[id].lazy += val;
        }
        void down(int id){
            T k = IT[id].lazy;
            if(k == 0)
                return;

            push(2*id, k);
            push(2*id+1, k);

            IT[id].lazy = 0;
        }
        void update(int id, int l, int r, int u, int v, T val){
            if(v < l || r < u)
                return;
            if(u <= l && r <= v){
                push(id, val);
                return;
            }
            down(id);
            int mid = (l+r) >> 1;
            update(2*id, l, mid, u, v, val);
            update(2*id+1, mid+1, r, u, v, val);
            IT[id].val = max(IT[2*id].val, IT[2*id+1].val);
        }
        T get(int id, int l, int r, int u, int v){
            if(u == v && v == 0)
                return 0;
            if(v < l || r < u)
                return -inf;
            if(u <= l && r <= v)
                return IT[id].val;
            down(id);
            int mid = (l+r) >> 1;
            T L = get(2*id, l, mid, u, v);
            T R = get(2*id+1, mid+1, r, u, v);
            return max(L, R);
        }
};

int main(){
    io
    int n, q;
    cin >> n >> q;
    vector <int> arr(n+1);
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        arr[i] = x;
        sum[i] = sum[i-1] + x;
    }
    LazySegmentTree <ll> ST(n);
    ST.build(1, 1, n);
    while(q--){
        int t, a, b;
        cin >> t >> a >> b;
        if(t == 1){
            ST.update(1, 1, n, a, n, b - arr[a]);
            arr[a] = b;
        }else{
            cout << max(0LL, ST.get(1, 1, n, a, b) - ST.get(1, 1, n, a-1, a-1)) << '\n';
        }
    }
}