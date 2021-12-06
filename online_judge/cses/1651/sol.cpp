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

class FenwickTree{
private:
    int n;
    vector <ll> data;
public:
    FenwickTree(int n){
        data.resize(n+1);
        this->n = n;
    }
    void update(int id, int val){
        while(id <= n){
            data[id] += val;
            id += id&(-id);
        }
    }
    ll get(int id){
        ll ans = 0;
        while(id >= 1){
            ans += data[id];
            id -= id&(-id);
        }
        return ans;
    }
};

int main(){
    io
    int n, m;
    cin >> n >> m;
    FenwickTree fenw(n);
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        fenw.update(i, x);
        fenw.update(i+1, -x);
    }
    while(m--){
        int t; cin >> t;
        if(t == 1){
            int u, v, x;
            cin >> u >> v >> x;
            fenw.update(u, x);
            fenw.update(v+1, -x);
        }else{
            int k; cin >> k;
            cout << fenw.get(k) << '\n';
        }
    }
}