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
const int MAXN = 1e5 + 5;
int a[MAXN];

class BIT{
    int data[MAXN];
    int n;
    public:
        void update(int id, int val){
            while(id <= n){
                data[id] += val;
                id += id&(-id);
            }
        }
        int get(int id){
            int ans = 0;
            while(id >= 1){
                ans += data[id];
                id -= id&(-id);
            }
            return ans;
        }
        void initialize(int n){
            this->n = n;
            fill(data, data+1+n, 0);
        }
        int findIndexR(int val){
            int l = 1, r = n;
            while(l <= r){
                int mid = (l+r) >> 1;
                if(get(mid) <= val)
                    l = mid + 1;
                else r = mid - 1;
            }
            return l-1;
        }
        int findIndexL(int val){
            int l = 1, r = n;
            while(l <= r){
                int mid = (l+r) >> 1;
                if(get(mid) >= val)
                    r = mid - 1;
                else l = mid + 1;
            }
            return r+1;
        }
        int findIndex(int val){
            int l = 1, r = n;
            while(l <= r){
                int mid = (l+r) >> 1;
                if(mid - get(mid) <= val)
                    l = mid + 1;
                else r = mid - 1;
            }
            return l-1;
        }
};

class IT{
    int data[4*MAXN];
    public:
        void build(int id, int l, int r){
            if(l == r){
                data[id] = a[l];
                return;
            }
            int mid = (l+r) >> 1;
            build(2*id, l, mid);
            build(2*id+1, mid+1, r);
            data[id] = max(data[2*id], data[2*id+1]);
        }
        void initialize(int n){
            fill(data, data+4*n+1, 0);
            build(1, 1, n);
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
            update(2*id+1, mid+1, r, i, val);
            data[id] = max(data[2*id], data[2*id+1]);
        }
        int get(int id, int l, int r, int u, int v){
            if(u > v)
                return -1;
            if(v < l || r < u)
                return -1;
            if(u <= l && r <= v)
                return data[id];
            int mid = (l+r) >> 1;
            int L = get(2*id, l, mid, u, v);
            int R = get(2*id+1, mid+1, r, u, v);
            return max(L, R);
        }
};

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n; cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    BIT bit;
    IT it;
    bit.initialize(n);
    it.initialize(n);

    int m; cin >> m;
    while(m--){
        char type;
        cin >> type;
        if(type == 'S'){
            int x; cin >> x;
            int idx = bit.findIndex(x);
            bit.update(idx+1, 1);
            it.update(1, 1, n, idx, -1);
        }
        if(type == 'Q'){
            int x, y;
            cin >> x >> y;
            int idL = bit.findIndexL(x);
            int idR = bit.findIndexR(y);
            int ans = it.get(1, 1, n, idL, idR);
            if(ans == -1)
                cout << "NONE" << '\n';
            else cout << ans << '\n';
        }
    }
}