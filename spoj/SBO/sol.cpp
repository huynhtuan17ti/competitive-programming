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
const int MAXN = 5e5 + 5;
const int MAXVAL = 1e5;
int a[MAXN];

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

struct range{
    int pos, l, r;
};

vector <range> initialize(int n){
    vector <range> ranges(n+1);
    unordered_map <int, int> M;
    for(int i = 1; i <= n; i++){
        if(M.find(a[i]) == M.end())
            ranges[i].l = 0;
        else ranges[i].l = M[a[i]];
        M[a[i]] = i;
    }
    M.clear();
    for(int i = n; i >= 1; i--){
        if(M.find(a[i]) == M.end())
            ranges[i].r = n+1;
        else ranges[i].r = M[a[i]];
        M[a[i]] = i;
    }
    for(int i = 1; i <= n; i++)
        ranges[i].pos = i;
    
    return ranges;
}

void solve(int n){
    vector <range> ranges = initialize(n);
    LazySegmentTree <int> IT(n, 0, [&](int i, int j){return max(i, j);});
    int res = 0;
    priority_queue <ii, vii, greater <ii>> Q;
    for(int i = 1; i <= n; i++){
        Q.push({ranges[i].r, i});
        IT.update(1, 1, n, ranges[i].l+1, ranges[i].pos, 1);
        while(!Q.empty() && Q.top().fi < i){
            int pos = Q.top().se;
            IT.update(1, 1, n, ranges[pos].l+1, ranges[pos].pos, -1);
            Q.pop();
        }
        res = max(res, IT.get(1, 1, n, 1, i));
    }
    cout << res << '\n';
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    solve(n);
}