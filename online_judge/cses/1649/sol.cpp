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
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
const int MAXN = 5e5 + 5;

class SegmentTree{
private:
    vector <int> data;
public:
    SegmentTree(int n){
        data.resize(4*n + 5);
    }
    void update(int id, int l, int r, int i, int val){
        if(i < l || r < i)
            return;
        if(l == r && l == i){
            data[id] = val;
            return;
        }
        int mid = (l+r) >> 1;
        update(2*id, l, mid, i, val);
        update(2*id+1, mid+1,r, i, val);
        data[id] = min(data[2*id], data[2*id+1]);
    }
    int get(int id, int l, int r, int u, int v){
        if(v < l || r < u)
            return INT_MAX;
        if(u <= l && r <= v)
            return data[id];
        int mid = (l+r) >> 1;
        return min(get(2*id, l, mid, u, v), get(2*id+1, mid+1, r, u, v));
    }
};

int main(){
    io
    int n, q;
    cin >> n >> q;
    SegmentTree seg(n);
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        seg.update(1, 1, n, i, x);
    }
    while(q--){
        int t, u, v;
        cin >> t >> u >> v;
        if(t == 1)
            seg.update(1, 1, n, u, v);
        else
            cout << seg.get(1, 1,n, u, v) << '\n';
    }
}