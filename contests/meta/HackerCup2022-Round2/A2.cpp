#include <bits/stdc++.h>  
using namespace std;

const int MOD = 1e9 + 7;
const long double esp = 1e-7;
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

using HashNode = tuple<ll, ll, ll>;

HashNode operator+(const HashNode &A, const HashNode &B){
    const auto& [a1, b1, c1] = A;
    const auto& [a2, b2, c2] = B;
    return {a1 + a2, b1 + b2, c1 + c2};
};

HashNode& operator+=(HashNode &A, const HashNode &B){
    auto& [a1, b1, c1] = A;
    const auto& [a2, b2, c2] = B;
    a1 += a2; b1 += b2; c1 += c2;
    return A;
};

HashNode operator-(const HashNode &A, const HashNode &B){
    const auto& [a1, b1, c1] = A;
    const auto& [a2, b2, c2] = B;
    return {a1 - a2, b1 - b2, c1 - c2};
};

HashNode& operator-=(HashNode &A, const HashNode &B){
    auto& [a1, b1, c1] = A;
    const auto& [a2, b2, c2] = B;
    a1 -= a2; b1 -= b2; c1 -= c2;
    return A;
};

template <typename T>
class FenwickTree{
private:
    vector<T> bit;
    int n;
public:
    FenwickTree(int _n){
        this->n = _n;
        bit.resize(n+1);
    }

    void update(int id, T val) {
        while (id <= n) {
            bit[id] += val;
            id += id&(-id);
        }
    }

    T get(int id){
        T ans{};
        while(id >= 1){
            ans += bit[id];
            id -= id&(-id); 
        }
        return ans;
    }
};

void solve(int iTest){
    random_device device;
    mt19937 rnd(device());
    int n; cin >> n;
    FenwickTree<HashNode> fenw(n);
    map<int, HashNode> hsh;
    map<HashNode, int> inv;
    vector<int> a(n+1);

    auto index = [&](int u){
        if(!hsh.count(u)){
            ll x = rnd(), y = rnd(), z = rnd();
            hsh[u] = {x, y, z};
            inv[{x, y, z}] = u;
        }
        return hsh[u];
    };
    
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        fenw.update(i, index(a[i]));
    }

    int cnt = 0;
    int q; cin >> q;
    while(q--){
        int t, l, r;
        cin >> t >> l >> r;
        if(t == 1){
            fenw.update(l, index(r) - index(a[l]));
            a[l] = r;
        }else{
            if((r-l+1)%2 == 0) continue;
            int mid = (l+r) >> 1;
            auto total = fenw.get(r) - fenw.get(l-1);
            auto left = fenw.get(mid-1) - fenw.get(l-1);
            auto right = fenw.get(r) - fenw.get(mid);

            if(inv.count(total - left - left))
                cnt++;
            else if(inv.count(total - right - right))
                cnt++;
        }
    }
    
    cerr << "Processing case #" << iTest << '\n';
    cout << "Case #" << iTest << ": " << cnt << '\n';
}

int main(){
    io
    freopen("A2_val.txt", "r", stdin);
    freopen("test.out", "w", stdout);
    int t; cin >> t;
    for(int iTest = 1; iTest <= t; iTest++){
        solve(iTest);
    }
}