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
#define MAXN 1000005

int F[MAXN];
int dp[MAXN];

void initialize(int n){
    F[0] = 1;
    for(int i = 1; i <= n; i++)
        F[i] = 1LL*F[i-1]*i%MOD;
}

int powMod(int a, int b){
    if(b == 0)
        return 1;
    if(b == 1)
        return a;
    int t = powMod(a, b/2);
    t = 1LL*t*t%MOD;
    if(b%2 == 1)
        t = (1LL*t*a)%MOD;
    return t;
}

int nCk(int n, int k){
    if(k > n || k < 0)
        return 0;
    return 1LL*F[n]*powMod(1LL*F[k]*F[n-k]%MOD, MOD-2)%MOD;
}

bool isGood(int x, int a, int b){
    while(x > 0){
        if(x%10 != a && x%10 != b)
            return false;
        x /= 10;
    }
    return true;
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int a, b, n;
    cin >> a >> b >> n;
    initialize(n);
    int res = 0;
    for(int i = 0; i <= n; i++){
        int sum = i*a + (n-i)*b;
        if(isGood(sum, a, b)){
            res = (res + 1LL*nCk(n, i))%MOD;
        }
    }
    cout << res;
}