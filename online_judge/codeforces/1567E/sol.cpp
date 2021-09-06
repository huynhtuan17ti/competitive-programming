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
int a[MAXN];

ll calc(int x){
    return 1LL*x*(x+1)/2;
}

class SegmentTree{
    struct node{
        ll ans;
        int left, right;
        int posL, posR;
        node(){
            ans = left = right = 0;
            posL = posR = 0;
        }
    };
    node empty;
    bool check_empty(node v){
        return (v.posL == 0 && v.posR == 0);
    }

    node merge(node L, node R){
        if(check_empty(L))
            return R;
        if(check_empty(R))
            return L;
        node res;
        res.posL = L.posL; res.posR = R.posR;
        res.left = L.left; res.right = R.right;
        res.ans = L.ans + R.ans;
        if(a[L.posR] <= a[R.posL]){
            res.ans += 1LL*L.right*R.left;
            if(L.left == L.posR - L.posL + 1)
                res.left = L.left + R.left;
            if(R.right == R.posR - R.posL + 1)
                res.right = R.right + L.right;
        }
        return res;
    }
    vector <node> IT;
    public:
        void initialize(int n){
            IT.resize(4*n+5);
            build(1, 1, n);
            empty.posL = empty.posR = 0;
        }

        void build(int id, int l, int r){
            if(l == r){
                IT[id].ans = IT[id].left = IT[id].right = 1;
                IT[id].posL = l;
                IT[id].posR = r;
                return;
            }
            int mid = (l+r) >> 1;
            build(2*id, l, mid);
            build(2*id+1, mid+1, r);
            IT[id] = merge(IT[2*id], IT[2*id+1]);
        }

        void update(int id, int l, int r, int i, int val){
            if(i < l || r < i)
                return;
            if(l == r && l == i){
                a[i] = val;
                return;
            }
            int mid = (l+r) >> 1;
            update(2*id, l, mid, i, val);
            update(2*id+1, mid+1, r, i, val);
            IT[id] = merge(IT[2*id], IT[2*id+1]);
        }

        node get(int id, int l, int r, int u, int v){
            if(v < l || r < u)
                return empty;
            if(u <= l && r <= v){
                return IT[id];
            }
            int mid = (l+r) >> 1;
            node L = get(2*id, l, mid, u, v);
            node R = get(2*id+1, mid+1, r, u, v);

            return merge(L, R);
        }
};

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    int n; cin >> n;
    int q; cin >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    SegmentTree st;
    st.initialize(n);

   
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int x, y;
            cin >> x >> y;
            st.update(1, 1, n, x, y);
        }else{
            int l, r;
            cin >> l >> r;
            ll ans = st.get(1, 1, n, l, r).ans;
            cout << ans << '\n';
        }
    }
}