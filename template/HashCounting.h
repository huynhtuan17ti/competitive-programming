/*
    Given 2 sets of integers
    Check if 2 the frequency of same number in 2 sets is equal.
    Ex:
        [1, 2, 3] = [3, 1, 2]
        [1, 2, 3] != [3, 2, 2]
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

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

void solve(){
    // random generator
    random_device device;
    mt19937 rnd(device());

    int n; cin >> n;
    map<int, HashNode> hsh;
    vector<int> a(n+1);

    auto index = [&](int u){
        if(!hsh.count(u)){
            ll x = rnd(), y = rnd(), z = rnd();
            hsh[u] = {x, y, z};
        }
        return hsh[u];
    };
    
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        // HashNode(a[i]) = index(a[i])
    }
}

/*
    Given set1 = [a_i], set2 = [b_i]
    S1 = sum(HashNode(a_i) in set1)
    S2 = sum(HashNode(b_i) in set2)
    if S1 == S2 ==> set1 = set2
*/