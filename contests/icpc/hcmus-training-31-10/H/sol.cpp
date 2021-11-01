#include <bits/stdc++.h>
using namespace std;

#define long long long
#define db double
#define pii pair <int, int>
#define pll pair <long, long>
#define all(c) c.begin(), c.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

template <class T> inline void chmin(T &a, const T& val) { if (a > val) a = val; }
template <class T> inline void chmax(T &a, const T& val) { if (a < val) a = val; }
template <class T> long sqr(T a) { return 1ll * a * a; }
template <class T> void compress(T &a){
    sort(all(a)); a.resize(unique(all(a)) - a.begin());
}

const db pi = acos(-1.00);
const db eps = 1e-6;
const int INF = 2e9;
const int MOD = 1e9 + 7;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

struct BIT {
    vector<int> bit;
    int n; 

    BIT(int n) : n(n) {
        bit.assign(n + 1, 0);
    }

    void update(int p){
        for (; p <= n; p += p&-p){
            bit[p] ^= 1;
        }
    }

    int get(int p){
        int ans = 0;
        for (; p > 0; p -= p&-p){
            ans ^= bit[p];
        }
        return ans;
    }

    int get(int l, int r){
        return get(min(n, r)) ^ (get(min(n, l - 1)));
    }
};

int main()
{
    fastio;
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    long tot = 0;
    for (int k = 0; k < 25; k++){
        vector<int> b(n);
        for (int i = 0; i < n; i++){
            b[i] = a[i] & ((1 << (k + 1)) - 1);
        }  
        int mx = *max_element(all(b));
        
        // 2^k --> 2^(k + 1) - 1
        // 2^k + 2^(k + 1) --> 2^(k + 2) - 2
        
        int ans = 0;
        BIT tree(mx + 1);
        for (int i = 0; i < n; i++){
            ans ^= tree.get((1 << k) - b[i] + 1, (1 << (k + 1)) - b[i]);
            ans ^= tree.get((1 << k) + (1 << (k + 1)) - b[i] + 1, (1 << (k + 2)) - 1 - b[i]);
            tree.update(b[i] + 1);
        }
        if (ans) tot += (1 << k);
    }  
    cout << tot;
    return 0;
}