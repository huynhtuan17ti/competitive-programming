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
const int MAXN = 500005;

template <typename T>
class FenwickTree{
private:
    vector <T> fenw;
    int n;
public:
    FenwickTree(int _n){
        this->n = _n;
        fenw.resize(n+1);
    }

    void update(int id, T val) {
        while (id <= n) {
            fenw[id] = max(fenw[id], val);
            id += id&(-id);
        }
    }

    T get(int id){
        T ans = 0;
        while(id >= 1){
            ans = max(ans, fenw[id]);
            id -= id&(-id); 
        }
        return ans;
    }
};

int main(){
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    io
    int n; cin >> n;
    vii ranges(n);
    vector <int> S;
    for(auto &[l, r]: ranges){
        cin >> l >> r;
        S.push_back(l);
        S.push_back(r);
    }
    S.push_back(INT_MIN);
    sort(S.begin(), S.end());
    S.resize(unique(S.begin(), S.end()) - S.begin());
    sort(ranges.begin(), ranges.end());
    auto find = [&](int val) -> int{
        return lower_bound(S.begin(), S.end(), val) - S.begin();
    };
    FenwickTree <ll> fenw(S.size()+1);
    int ans = 0;
    for(auto [l, r]: ranges){
        l = find(l); r = find(r);
        int curMax = fenw.get(l) + 1;
        ans = max(curMax, ans);
        fenw.update(r, curMax);
    }
    cout << ans << '\n';
}