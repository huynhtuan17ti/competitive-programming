/* Tutorial: https://codeforces.com/blog/entry/92864*/
#include <bits/stdc++.h>

using namespace std;
#define MAXN 200005
const int MOD = 1e9+7;

int F[MAXN];

void init(){
    F[0] = 1;
    for(int i = 1; i <= MAXN-5; i++)
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
        t = (1LL*t*a)%MOD;
    return t;
}

int nCk(int n, int k){
    if(k > n || k < 0)
        return 0;
    return 1LL*F[n]*powMod(1LL*F[k]*F[n-k]%MOD, MOD-2)%MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    init();
    int t; cin >> t;
    while(t--){
        int n, l, r;
        cin >> n >> l >> r;
        int half = n/2;
        int num = min(1 - l, r - n);
        int res = 1LL*num*nCk(n, half)%MOD;
        if(n%2 == 1)
            res = (res + 1LL*num*nCk(n, half+1)%MOD)%MOD;

        for(int i = num+1; ; i++){
            int L = max(1, l + i);
            int R = min(n, r - i);

            if(R + 1 - L < 0)
                break;

            res = (res + nCk(R - L + 1, half - L + 1))%MOD;
            if(n%2 == 1)
                res = (res + nCk(R - L + 1, half - L + 2))%MOD;
        }
        cout << res << '\n';
    }
}