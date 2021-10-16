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
int p[MAXN];

/*
    ans = pj + |i - j|
    if j < i:
        ans = pj + i - j = i + (pj - j)
    else:
        ans = pj + j - i = (pj + j) - i
*/

template <typename T>
class SegmentTree{
    struct node{
        T val;
        node(){
            val = 0;
        }
    };
    public:
        vector <node> IT;
        SegmentTree(int n){
            IT.resize(4*n+5);
        }
        void update(int id, int l, int r, int u, T val){
            if(u < l || r < u)
                return;
            if(l == r && l == u){
                IT[id].val = val;
                return;
            }
            int mid = (l+r) >> 1;
            update(2*id, l, mid, u, val);
            update(2*id+1, mid+1, r, u, val);
            IT[id].val = min(IT[2*id].val, IT[2*id+1].val);
        }
        T get(int id, int l, int r, int u, int v){
            if(v < l || r < u)
                return inf;
            if(u <= l && r <= v)
                return IT[id].val;
            int mid = (l+r) >> 1;
            T L = get(2*id, l, mid, u, v);
            T R = get(2*id+1, mid+1, r, u, v);
            return min(L, R);
        }
};

int main(){
    io
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> p[i];
    
    SegmentTree <ll> STLeft(n);
    SegmentTree <ll> STRight(n);

    for(int i = 1; i <= n; i++){
        STLeft.update(1, 1, n, i, p[i] - i);
        STRight.update(1, 1, n, i, p[i] + i);
    }

    while(q--){
        int t; cin >> t;
        if(t == 1){
            int k, x;
            cin >> k >> x;
            STLeft.update(1, 1, n, k, x - k);
            STRight.update(1, 1, n, k, x + k);
        }else{
            int k;
            cin >> k;
            ll res = min(
                k + STLeft.get(1, 1, n, 1, k),
                STRight.get(1, 1, n, k, n) - k
            );
            cout << res << '\n';
        }
    }
}