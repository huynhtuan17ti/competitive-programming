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
 
template <typename T, typename F = function <T(const T&, const T&)>>
class LazySegmentTree{
    F func;
    T blank;
    struct node{
        T val, lazy;
        node(){
            val = lazy = 0;
        }
    };
    public:
        vector <node> IT;
        LazySegmentTree(int n, T blank, const F& f){
            IT.resize(4*n+5);
            this->func = f;
            this->blank = blank;
        }
        void push(int id, T val){
            IT[id].val += val;
            IT[id].lazy += val;
        }
        void down(int id){
            T k = IT[id].lazy;
            if(k == blank)
                return;

            push(2*id, k);
            push(2*id+1, k);

            IT[id].lazy = blank;
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
            IT[id].val = func(IT[2*id].val, IT[2*id+1].val);
        }
        T get(int id, int l, int r, int u, int v){
            if(v < l || r < u)
                return blank;
            if(u <= l && r <= v)
                return IT[id].val;
            down(id);
            int mid = (l+r) >> 1;
            T L = get(2*id, l, mid, u, v);
            T R = get(2*id+1, mid+1, r, u, v);
            return func(L, R);
        }
};

struct seg{
    int l, r, w;
};

int main(){
    io
    int t; t = 1;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector <seg> segs;
        for(int i = 0; i < n; i++){
            int l, r, w;
            cin >> l >> r >> w;
            r = min(r-1, m);
            segs.push_back({l, r, w});
        }
        sort(segs.begin(), segs.end(), [](const seg &A, const seg &B){
            return (A.w < B.w);
        });

        LazySegmentTree <int> ST(m, 0, [&](int i, int j){
            return min(i, j);
        });
        int j = 0;
        int res = INT_MAX;
        for(int i = 0; i < segs.size(); i++){
            ST.update(1, 1, m-1, segs[i].l, segs[i].r, 1);
            while(j < i && ST.IT[1].val > 0){
                ST.update(1, 1, m-1, segs[j].l, segs[j].r, -1);
                j += 1;
            }
            if(j > 0 && ST.IT[0].val == 0){
                j -= 1;
                ST.update(1, 1, m-1, segs[j].l, segs[j].r, 1);
            }
            if(ST.IT[1].val > 0){
                res = min(res, segs[i].w - segs[j].w);
            }
        }
        cout << res << '\n';
    }
}