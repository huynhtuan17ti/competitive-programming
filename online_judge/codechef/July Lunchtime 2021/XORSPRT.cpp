#include <bits/stdc++.h>  
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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

const int MAXN = 1e5 + 5;
const int max_bit = 55;
ll dp[MAXN][60];
gp_hash_table <ll, int> F[60];

int get_bit(ll val, int id){
    return (val >> id)&1LL;
}

ll pow2[MAXN];

int mod(ll val){
    if(val >= MOD)
        val -= MOD;
    return val;
}

void initialize(){
    pow2[0] = 1;
    for(int i = 1; i <= 100000; i++)
        pow2[i] = mod(pow2[i-1]*2);
}

void solve(){
    int n; cin >> n;
    vector <ll> a(n+1);
    vector <ll> sum(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum[i] = (sum[i-1]^a[i]);
    }
    for(int bit = 0; bit <= max_bit; bit++){
        F[bit].clear();
        for(int i = 0; i <= n; i++)
            dp[i][bit] = 0;
    }
    for(int i = 1; i <= n; i++){
        ll val = sum[i];
        for(int bit = max_bit; bit >= 0; bit--){
            ll rest = 1LL*get_bit(sum[i], bit)*(1LL<<bit);
            
            if(bit > 0)
                dp[i][bit] = mod(dp[i][bit] + F[bit-1][val-rest]);
            else dp[i][bit] = mod(dp[i][bit] + 1);
            
            F[bit][val] = mod(F[bit][val] + dp[i][bit]);
            val -= rest;
        }
    }
    ll res = 0;
    for(int bit = 0; bit <= max_bit; bit++)
        res = mod(res + dp[n][bit]);

    int cnt = 1;
    for(int i = n-1; i >= 1; i--)
        if(sum[i] == sum[n]){
            res = mod(res + dp[i][max_bit]*pow2[cnt-1]%MOD);
            cnt++;
        }
    cout << res << '\n';
}

int main(){
    io
    initialize();
    int t; cin >> t;
    while(t--){
        solve();
    }
}