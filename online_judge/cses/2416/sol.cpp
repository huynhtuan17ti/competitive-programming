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

struct Query{
    int l, r, id;
};

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
        void down(int l, int r, int id){
            T k = IT[id].lazy;
            if(k == 0)
                return;
            int mid = (l+r) >> 1;
            IT[2*id].val = k*(mid - l + 1);
            IT[2*id].lazy = k;
            IT[2*id+1].val = k*(r - mid);
            IT[2*id+1].lazy = k;

            IT[id].lazy = 0;
        }
        void update(int id, int l, int r, int u, int v, T val){
            if(v < l || r < u)
                return;
            if(u <= l && r <= v){
                IT[id].val = (r-l+1)*val;
                IT[id].lazy = val;
                return;
            }
            down(l, r, id);
            int mid = (l+r) >> 1;
            update(2*id, l, mid, u, v, val);
            update(2*id+1, mid+1, r, u, v, val);
            IT[id].val = IT[2*id].val + IT[2*id+1].val;
        }
        T get(int id, int l, int r, int u, int v){
            if(v < l || r < u)
                return 0;
            if(u <= l && r <= v)
                return IT[id].val;
            down(l, r, id);
            int mid = (l+r) >> 1;
            T L = get(2*id, l, mid, u, v);
            T R = get(2*id+1, mid+1, r, u, v);
            return L + R;
        }
};

int main(){
    io
    int n, q;
    cin >> n >> q;
    vector <int> a(n+1);
    vector <ll> sum(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }

    vector <int> R(n+1);
    stack <int> st;
    for(int i = n; i >= 1; i--){
        while(!st.empty() && a[i] >= a[st.top()]){
            st.pop();
        }
        if(!st.empty())
            R[i] = st.top() - 1;
        else R[i] = n;
        st.push(i);
    }

    vector <Query> queries;
    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        queries.push_back({l, r, i});
    }
    sort(queries.begin(), queries.end(), [](const Query &A, const Query &B){
        return A.l > B.l;
    });
    LazySegmentTree <ll> ST(n);
    vector <ll> res(q);
    int j = n;
    for(Query q: queries){
        while(j >= q.l){
            ST.update(1, 1, n, j, R[j], a[j]);
            j--;
        }
        res[q.id] = ST.get(1, 1, n, q.l, q.r) - (sum[q.r] - sum[q.l-1]);
    }
    for(int i = 0; i < q; i++)
        cout << res[i] << '\n';
}