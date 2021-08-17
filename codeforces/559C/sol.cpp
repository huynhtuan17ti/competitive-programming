#include <bits/stdc++.h>

using namespace std;
const int MOD = 1e9 + 7;
typedef long long ll;
typedef pair <int, int> ii;
typedef vector <ii> vii;
#define fi first
#define se second
const int MAXH = 2e5;
const int MAXN = 5e3;

int F[MAXH+5];
void initialize(){
    F[0] = 1;
    for(int i = 1; i <= MAXH; i++)
        F[i] = 1LL*F[i-1]*i%MOD;
}

int powMod(int a, int b){
    if(b == 0)
        return 1;
    if(b == 1)
        return a;
    ll t = powMod(a, b/2);
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

int dp[MAXN+5];

int main(){
    initialize();
    int h, w, n;
    cin >> h >> w >> n;
    vii black_cells;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        black_cells.push_back({x, y});
    }
    black_cells.push_back({h, w});
    sort(black_cells.begin(), black_cells.end(), [](const ii &A, const ii &B){
        return (A.fi == B.fi)? (A.se < B.se): (A.fi < B.fi);
    });

    for(int i = 0; i <= n; i++){
        dp[i] = nCk(black_cells[i].fi + black_cells[i].se-2, black_cells[i].fi-1);
        for(int j = 0; j < i; j++){
            if(black_cells[i].se < black_cells[j].se)
                continue;
            int y_d = black_cells[i].fi - black_cells[j].fi;
            int x_d = black_cells[i].se - black_cells[j].se;
            dp[i] = (dp[i] - 1LL*dp[j]*nCk(y_d+x_d, y_d)%MOD + MOD)%MOD;
        }
    }
    cout << dp[n];
}