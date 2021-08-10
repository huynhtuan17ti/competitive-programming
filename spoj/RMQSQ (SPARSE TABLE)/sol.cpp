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
class SparseTable{
    F func;
    int n;
    vector <vector <T>> ans;
    public:
        SparseTable(const vector <T>& a, const F& f) : func(f){
            this->n = (int)a.size();
            int sz = trunc(log2(n)) + 1;
            ans.resize(n);
            for(int i = 0; i < n; i++){
                ans[i].resize(sz);
            }
            for(int i = 0; i < n; i++)
                ans[i][0] = a[i];
            for(int j = 1; j < sz; j++)
                for(int i = 0; i <= n - (1<<j); i++)
                    ans[i][j] = func(ans[i][j-1], ans[i + (1<<(j-1))][j-1]);
        }

        T query(int l, int r){
            assert(0 <= l && l <= r && r < n);
            int k = trunc(log2(r-l+1));
            return func(ans[l][k], ans[r - (1<<k) + 1][k]);
        }
};


int main(){
    io
    int n; cin >> n;
    vector <int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    SparseTable <int> st(a, [&](int i, int j){return min(i, j);});
    int q; cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << st.query(l, r) << '\n';
    }
}