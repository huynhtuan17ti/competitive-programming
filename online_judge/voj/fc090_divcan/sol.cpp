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
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
const int MAXN = 5e5 + 5;

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
    if(n < 0 || k < 0)
        return 0;
    int kr, nr;
    int res = 1;
    while(k != 0){
        kr = k%MOD;
        nr = n%MOD;
        res = 1LL*res*nCk(nr, kr)%MOD;
        n /= MOD;
        k /= MOD;
    }
    return res;
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    initialize();
    int n;
    ll m;
    cin >> n >> m;
    vector <ll> a(n);
    for(auto &x: a)
        cin >> x;
    
    auto getBit = [&](int val, int id) -> bool{
        return (val >> id)&1;
    };

    ll ans = 0;
    int maxState = (1<<n)-1;
    for(int state = 0; state <= maxState; state++){
        ll sum = m;
        int cnt = 0;
        for(int i = 0; i < n; i++)
            if(getBit(state, i)){
                sum -= (a[i]+1);
                cnt++;
            }
        int coeff = (cnt%2 == 0)? 1: -1;
        ans = (ans + coeff * Lucas(sum+n-1, sum) + MOD)%MOD;
    }
    cout << ans << '\n';
}