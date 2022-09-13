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
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
const int MAXN = 5e5 + 5;

void solve(int iTest){
    int n, q;
    cin >> n;
    ll sqr_sum = 0, sum_A = 0, sum_B = 0;
    for(int i = 1, A, B; i <= n; i++){
        cin >> A >> B;
        sqr_sum += (1LL*A*A%MOD + 1LL*B*B%MOD)%MOD;
        sum_A += A;
        sum_B += B;
        sqr_sum %= MOD;
        sum_A %= MOD;
        sum_B %= MOD;
    }
    ll ans = 0;
    cin >> q;
    while(q--){
        int X, Y;
        cin >> X >> Y;
        ll cur = (1LL * n * (1LL*X*X%MOD + 1LL*Y*Y%MOD) % MOD + sqr_sum 
                - 1LL * 2*X*sum_A % MOD - 1LL * 2*Y*sum_B % MOD + 1LL * MOD * 2) % MOD;
        ans = (ans + cur) % MOD;
    }
    cout << "Case #" << iTest << ": " << ans << '\n';
}

int main(){
    io
    freopen("B1_test.txt", "r", stdin);
    freopen("test.out", "w", stdout);
    int t; cin >> t;
    for(int iTest = 1; iTest <= t; iTest++){
        solve(iTest);
    }
}