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
 
class LaztSegmentTree{
private:
    struct Node{
        ll sum;
        ll lazy;
        int lazyType; 
    };
    vector <Node> IT;
public:
    LaztSegmentTree(int n){
        IT.resize(4*n + 5);
    }
    void down(int id, int l, int r){
        ll k = IT[id].lazy;
        int type = IT[id].lazyType;
        if(k == 0)
            return;
        int mid = (l+r) >> 1;
        if(type == 1){
            IT[2*id].sum = k * (mid - l + 1);
            IT[2*id].lazy = k;
            IT[2*id].lazyType = 1;
 
            IT[2*id+1].sum = k * (r - mid);
            IT[2*id+1].lazy = k;
            IT[2*id+1].lazyType = 1;
        }else{
            IT[2*id].sum += k * (mid - l + 1);
            IT[2*id].lazy += k;
 
            IT[2*id+1].sum += k * (r - mid);
            IT[2*id+1].lazy += k;
        }
        IT[id].lazy = 0;
        IT[id].lazyType = 0;
    }
    void update(int id, int l, int r, int u, int v, int val, int type){
        if(v < l || r < u)
            return;
        if(u <= l && r <= v){
            if(type == 1){
                IT[id].sum = 1LL * val * (r - l + 1);
                IT[id].lazy = val;
                IT[id].lazyType = 1;
            }else{
                IT[id].sum += 1LL * val * (r - l + 1);
                IT[id].lazy += val;
            }
            return;
        }
        down(id, l, r);
        int mid = (l+r) >> 1;
        update(2*id, l, mid, u, v, val, type);
        update(2*id+1, mid+1, r, u, v, val, type);
        IT[id].sum = IT[2*id].sum + IT[2*id+1].sum;
    }
    ll get(int id, int l, int r, int u, int v){
        if(v < l || r < u)
            return 0;
        if(u <= l && r <= v){
            return IT[id].sum;
        }
        down(id, l, r);
        int mid = (l+r) >> 1;
        return get(2*id, l, mid, u, v) +
               get(2*id+1, mid+1, r, u, v);
    }
};
 
int main(){
    io
    //freopen("test.inp", "r", stdin);
    int n, q;
    cin >> n >> q;
    LaztSegmentTree seg(n);
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        seg.update(1, 1, n, i, i, x, 0);
    }
    while(q--){
        int t, u, v; cin >> t >> u >> v;
        if(t == 1){
            int x; cin >> x;
            seg.update(1, 1, n, u, v, x, 0);
        }
        if(t == 2){
            int x; cin >> x;
            seg.update(1, 1, n, u, v, x, 1);
        }
        if(t == 3){
            cout << seg.get(1, 1, n, u, v) << '\n';
        }
    }
}