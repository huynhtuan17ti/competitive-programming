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
const ll MODSHIT = 1e15;

int main(){
    io
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int n; cin >> n;
    long double ans = 0;
    ll F = 1;
    for(int i = 0; i <= n; i++){
        if(i > 0)
            F = (F*i)%MODSHIT;
        ans += (long double)1/F;
    }
    cout << fixed << setprecision(15) << ans << '\n';
}