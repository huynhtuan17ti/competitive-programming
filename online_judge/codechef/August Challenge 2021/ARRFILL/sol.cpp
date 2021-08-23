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

ll calc_LCM(ll a, ll b){
    return a*b/__gcd(a, b);
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int m; cin >> m;
        vii a;
        while(m--){
            int x, y;
            cin >> x >> y;
            a.push_back({x, y});
        }
        sort(a.begin(), a.end(), greater <ii> ());
        ll res = 0;
        ll LCM = 1;
        int _n = n;
        for(int i = 0; i < a.size(); i++){
            LCM = calc_LCM(LCM, a[i].se);

            res += 1LL*(n - _n/LCM)*a[i].fi;
            n = _n/LCM;
            if(LCM > _n)
                break;
        }
        cout << res << '\n';
    }
}