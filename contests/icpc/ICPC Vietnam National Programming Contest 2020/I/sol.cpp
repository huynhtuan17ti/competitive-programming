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
const int MAXN = 2e6;
int F[MAXN+5], Fi[MAXN+5];

void initialize(){
    F[0] = 1;
    for(int i = 1; i <= MAXN; i++)
        F[i] = 1LL*F[i-1]*i%MOD;
    
    Fi[0] = 0;
    Fi[1] = 1;
    for(int i = 2; i <= MAXN; i++)
        Fi[i] = (Fi[i-2] + Fi[i-1])%MOD;
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
    if(k > n)
        return 0;
    return 1LL*F[n]*powMod(1LL*F[k]*F[n-k]%MOD, MOD-2)%MOD;
}

int main(){
    io
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    initialize();
    int x, y;
    cin >> x >> y;
    ll res = 0;
    for(int i = 0; i <= x; i++){
        int ans = 1LL*Fi[i]*nCk(x+y-1-i, y-1)%MOD;
        res = (res + ans)%MOD;
    }
    for(int i = 0; i <= y; i++){
        int ans = 1LL*Fi[i]*nCk(x+y-1-i, x-1)%MOD;
        res = (res + ans)%MOD;
    }
    cout << res;
}