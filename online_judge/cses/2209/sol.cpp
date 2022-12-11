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

int powMod(int a, int b){
    if(b == 0)
        return 1;
    if(b == 1)
        return a;
    int t = powMod(a, b/2);
    t = 1LL * t * t % MOD;
    if(b%2 == 1)
        t = 1LL * t * a % MOD;
    return t;
}

int main(){
    io
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int n, m;
    cin >> n >> m;

    vector <ll> powM(n+1);
    powM[0] = 1;
    for(int i = 1; i <= n; i++)
        powM[i] = (powM[i-1] * m) % MOD;

    ll ans = 0;
    vector <ll> nums(n+1);
    
    for(int i = n; i >= 1; i--){
        if(n % i != 0)
            continue;
        
        nums[i] = powM[n/i];
        for(int j = i*2; j <= n; j += i)
            nums[i] = (nums[i] - nums[j] + MOD) % MOD;

        ans = (ans + 1LL * nums[i] * powMod(n/i, MOD-2) % MOD) % MOD;
    }
    cout << ans << '\n';
}
