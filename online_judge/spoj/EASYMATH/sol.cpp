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
 

ll get(ll val, vector <ll> nums){
    ll res = 0;
    int maxState = (1<<(int)nums.size());
    for(int state = 1; state < maxState; state++){
        int cnt = 0;
        ll ans = 0;
        for(int i = 0; i < nums.size(); i++)
            if(((state>>i)&1) == 1){
                cnt += 1;
                if(ans == 0)
                    ans = nums[i];
                ans = nums[i]/__gcd(nums[i], ans)*ans;
            }
        if(cnt%2 == 1){
            res += val/ans;
        }else
            res -= val/ans;
    }
    return val - res;
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int t; cin >> t;
    while(t--){
        ll n, m, a, d;
        cin >> n >> m >> a >> d;
        vector <ll> nums;
        for(int i = 0; i < 5; i++)
            nums.push_back(a + 1LL*i*d);
        cout << get(m, nums) - get(n-1, nums) << '\n';
    }
}