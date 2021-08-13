#include <bits/stdc++.h>  
 
using namespace std;
 
const int MOD = 1e9 + 7;
typedef unsigned long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define mp make_pair
#define fi first
#define se second
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

ll multiMod(ll a, ll b, ll mod){
    if(b == 0)
        return 0;
    if(b == 1)
        return a%mod;
    ll t = multiMod(a, b/2, mod);
    t = (t+t)%mod;
    if(b%2 == 1)
        t = (t+a)%mod;
    return t;
}

ll powMod(ll a, ll b, ll mod){
    if(b == 0)
        return 1;
    if(b == 1)
        return a%mod;
    ll t = powMod(a, b/2, mod);
    t = multiMod(t, t, mod);
    if(b%2 == 1)
        t = multiMod(t, a, mod);
    return t;
}

bool is_composite(ll n, ll a, ll d, ll s){
    ll x = powMod(a, d, n); //a^d mod n
    if(x == 1 || x == n-1)
        return false;
    for(int r = 1; r < s; r++){
        x = multiMod(x, x, n);
        if(x == n-1)
            return false;
    }
    return true;
}

bool MillerRabin(ll n){
    if(n < 2)
        return false;
    
    int r = 0;
    ll d = n-1;
    while((d&1) == 0){
        d >>= 1;
        r++;
    }

    for(int a: {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){
        if(n == a)
            return true;
        if(is_composite(n, a, d, r)) // check if n is a composite number
            return false;
    }
    return true;
}

void solve(ll n){
    if(MillerRabin(n))
        cout << "YES" << '\n';
    else cout << "NO" << '\n';
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        solve(n);
    }
}