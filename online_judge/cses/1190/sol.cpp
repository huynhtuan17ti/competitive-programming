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
int a[MAXN];

class SegmentTree{
private:
    struct Node{
        ll prefix, suffix;
        ll total;
        ll ans;
        Node(int p = 0, int s = 0, int t = 0, int a = 0){
            prefix = p;
            suffix = s;
            total = t;
            ans = a;
        }
    };
    Node up(Node L, Node R){
        Node res;
        res.prefix = max(L.prefix, L.total + R.prefix);
        res.suffix = max(L.suffix + R.total, R.suffix);
        res.total = L.total + R.total;
        res.ans = max({L.suffix + R.prefix, L.ans, R.ans});
        return res;
    }   
    vector <Node> data;
public:
    SegmentTree(int n){
        data.resize(4*n + 5);
        build(1, 1, n);
    }
    void build(int id, int l, int r){
        if(l == r){
            data[id] = Node(a[l], a[l], a[l], a[l]);
            return;
        }
        int mid = (l+r) >> 1;
        build(2*id, l, mid);
        build(2*id+1, mid+1, r);
        data[id] = up(data[2*id], data[2*id+1]);
    }
    void update(int id, int l, int r, int i){
        if(i < l || r < i)
            return;
        if(l == r && l == i){
            data[id] = Node(a[i], a[i], a[i], a[i]);
            return;
        }
        int mid = (l+r) >> 1;
        update(2*id, l, mid, i);
        update(2*id+1, mid+1, r, i);
        data[id] = up(data[2*id], data[2*id+1]);
    }
    ll get(){
        return data[1].ans;
    }
};

int main(){
    io
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    SegmentTree seg(n);
    while(m--){
        int pos, val;
        cin >> pos >> val;
        a[pos] = val;
        seg.update(1, 1, n, pos);
        cout << max(0LL, seg.get()) << '\n';
    }
}