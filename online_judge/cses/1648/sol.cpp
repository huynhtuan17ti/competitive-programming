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

template <typename T>
class FenwickTree{
    vector <T> fenw;
    int n;
    public:
        void initialize(int _n){
            this->n = _n;
            fenw.resize(n+1);
        }

        void update(int id, T val) {
            while (id <= n) {
                fenw[id] += val;
                id += id&(-id);
            }
        }

        T get(int id){
            T ans{};
            while(id >= 1){
                ans += fenw[id];
                id -= id&(-id); 
            }
            return ans;
        }
};

int main(){
    io
    int n, q;
    cin >> n >> q;
    vector <int> a(n+1);
    FenwickTree <ll> fenw;
    fenw.initialize(n);
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        a[i] = x;
        fenw.update(i, x);
    }
    while(q--){
        int t, l, r;
        cin >> t >> l >> r;
        if(t == 1){
            fenw.update(l, r - a[l]);
            a[l] = r;
        }
        else
            cout << fenw.get(r) - fenw.get(l-1) << '\n';
    }
}