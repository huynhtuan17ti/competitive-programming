#include <bits/stdc++.h>  
using namespace std;
 
constexpr int MOD = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define mp make_pair
#define fi first
#define se second
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};
constexpr int MAXN = 3e5 + 5;

template <typename T>
class FenwickTree{
public:
    FenwickTree(int n): n_(n){
        bit_l_.resize(n_+1);
        bit_r_.resize(n_+1);
    }

    void UpdateLeft(int id, T val) {
        while (id <= n_) {
            bit_l_[id] += val;
            id += id&(-id);
        }
    }

    T GetLeft(int id){
        T ans{};
        while(id >= 1){
            ans += bit_l_[id];
            id -= id&(-id); 
        }
        return ans;
    }

    void UpdateRight(int id, T val) {
        while (id >= 1) {
            bit_r_[id] += val;
            id -= id&(-id);
        }
    }

    T GetRight(int id){
        T ans{};
        while(id <= n_){
            ans += bit_r_[id];
            id += id&(-id); 
        }
        return ans;
    }
private:
    vector<T> bit_l_;
    vector<T> bit_r_;
    int n_;
};

int Pow2[MAXN];

int main() {
    io
    int n, m;
    ll k;
    cin >> n >> m >> k;
    Pow2[0] = 1;
    for(int i = 1; i <= n; ++i)
        Pow2[i] = (1LL * Pow2[i-1] * 2) % MOD;

    vector<int> p(n+1);
    for(int i = 1; i <= n; ++i)
        cin >> p[i];
    vii ranges;
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        ranges.emplace_back(u, v);
    }

    vii avail_ranges;
    int j = 1;
    ll cur_sum = 0;
    for(int i = 1; i <= n; ++i) {
        cur_sum += p[i];
        while(j < i && cur_sum - p[j] >= k) {
            cur_sum -= p[j];
            ++j;
        }
        if (cur_sum < k) continue;
        avail_ranges.emplace_back(j, i); 
    }

    sort(avail_ranges.begin(), avail_ranges.end(), [](const ii&A, const ii&B) {
            return A.se - A.fi > B.se - B.fi;
        });

    sort(ranges.begin(), ranges.end(), [](const ii&A, const ii&B) {
            return A.se - A.fi > B.se - B.fi;
        });
    
    vector<int> cnt(n+1);
    FenwickTree<int> fenw(n);
    ll ans = 0;
    j = 0;
    for(auto [u, v] : avail_ranges) {
        while(j < m && ranges[j].se - ranges[j].fi >= v - u) {
            fenw.UpdateLeft(ranges[j].se, 1);
            fenw.UpdateRight(ranges[j].fi, 1);
            ++cnt[ranges[j].se];
            ++j;
        } 
        int s = fenw.GetLeft(v-1) + fenw.GetRight(u+1);
        int t = cnt[v];
        //cerr << u << ' ' << v << ": " << s << ' ' << t << ' ' << j - s - t << '\n';
        ans = (ans + 1LL * Pow2[j - s - t] * (Pow2[t] - 1 + MOD) % MOD) % MOD;
        //cerr << ans << '\n';
    }
    cout << ans << '\n';
}
