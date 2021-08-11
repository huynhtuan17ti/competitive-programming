#include <bits/stdc++.h>  
 
using namespace std;
 
const int MOD = 1e5 + 3;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define mp make_pair
#define fi first
#define se second
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
/*
    Number of ways: (m - n + 1)Cm
*/

int F[MOD +  5];

void initialize(){
    F[0] = 1;
    for(int i = 1; i <= MOD; i++)
        F[i] = (1LL*F[i-1]*i)%MOD;
}

int powMod(int a, int b){
    if(b == 0)
        return 1;
    if(b == 1)
        return a;
    int t = powMod(a, b/2);
    t = 1LL*t*t%MOD;
    if(b%2 == 1)
        t = 1LL*t*a%MOD;
    return t;
}

int nCk(int n, int k){
    if(n < k)
        return 0;
    // Fermat's Little Theorem
    return 1LL*F[n]*powMod(1LL*F[k]*F[n-k]%MOD, MOD-2)%MOD;
}

int Lucas(ll n, ll k){
    int kr, nr;
    int res = 1;
    do{
        kr = k%MOD;
        nr = n%MOD;
        cout << kr << ' ' << nr << ' ' << nCk(nr, kr) << '\n';
        res = 1LL*res*nCk(nr, kr)%MOD;
        n /= MOD;
        k /= MOD;
    }while(kr != 0);
    return res;
}

int main(){
    io
    initialize();
    int T; cin >> T;
    while(T--){
        ll n, m;
        cin >> m >> n;
        cout << Lucas(m-n+1, n) << '\n';
    }
}