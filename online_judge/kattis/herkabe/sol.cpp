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
constexpr int MAXN = 1e3;

int nPk[MAXN + 1][MAXN + 1];

int main() {
    io
    
    for(int i = 1; i <= MAXN; ++i) {
        int cur = 1;
        for(int j = i; j >= 1; --j) {
            nPk[i][i - j] = cur;
            cur = (1LL * cur * j) % MOD;
        }
        nPk[i][i] = cur;
    }

    auto f_nPk = [&](int n, int k) {
        if (k > n) return 0;
        return nPk[n][k];
    };

    int n;
    cin >> n;
    vector<string> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end());
    //for(auto v: a)
        //cout << v << '\n';
    
    function<int(size_t, int, int)> calc = [&](size_t pos, int l, int r) {
        int cnt = 0, sum = 0;
        int ans = 1;
        int pre = l;

        while(pre <= r && a[pre].size() <= pos) ++pre;
        if(pre > r) return 1;
        for(int i = pre+1; i <= r + 1; ++i) {
            if(i == r + 1 || a[i][pos] != a[i-1][pos]) {
                ans = (1LL * ans * calc(pos + 1, pre, i - 1)) % MOD;
                sum += (i - pre);
                ++cnt;
                pre = i;
            }
        }

        return static_cast<int>(1LL * ans * f_nPk(r - l + 1 - sum + cnt, cnt) % MOD);
    };

    cout << calc(0, 0, n-1) << '\n';
}
