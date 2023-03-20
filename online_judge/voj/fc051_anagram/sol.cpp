#include <bits/stdc++.h>  
#include <unordered_map>
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

int main() {
    io
    random_device device;
    mt19937 rnd(device());
    string s1, s2;
    cin >> s1 >> s2;

    map<int, HashNode> hsh;

    auto index = [&](int u) {
        if(!hsh.count(u)) {
            ll x = rnd(), y = rnd(), z = rnd();
            hsh[u] = {x, y, z};
        }
        return hsh[u];
    };

    int n = s1.length(), m = s2.length();
    vector<HashNode> pre_sum_s1(n+1), pre_sum_s2(m+1);

    for(int i = 1; i <= n; ++i)
        pre_sum_s1[i] = pre_sum_s1[i-1] + index(s1[i-1]);

    for(int i = 1; i <= m; ++i)
        pre_sum_s2[i] = pre_sum_s2[i-1] + index(s2[i-1]);

    auto SumHash = [&](const HashNode &x) {
        auto& [a, b, c] = x;
        return a - b - c;
    };

    for(int len = min(n, m); len >= 1; len--) {
        unordered_map<ll, bool> is_exist;
        for(int i = len; i <= n; ++i) {
            auto cur = pre_sum_s1[i] - pre_sum_s1[i - len]; 
            is_exist[SumHash(cur)] = true;
        }

        for(int i = len; i <= m; ++i) {
            auto cur = pre_sum_s2[i] - pre_sum_s2[i - len]; 
            if(is_exist.count(SumHash(cur)))
                return cout << len << '\n', 0;
        }
    }
    cout << 0 << '\n';
}








