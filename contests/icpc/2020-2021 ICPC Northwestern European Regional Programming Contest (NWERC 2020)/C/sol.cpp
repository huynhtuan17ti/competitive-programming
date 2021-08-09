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
 

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    int d, s;
    cin >> d >> s;
    ld ans = (ld)(d*n - s*k)/(n-k);
    if(ans <= 100 && ans >= 0)
        cout << fixed << setprecision(10) << ans << '\n';
    else cout << "impossible" << '\n';
}