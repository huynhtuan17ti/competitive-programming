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
const int MAXN = 500005;
 
void solve(){
    ll a, b, x;
    cin >> a >> b >> x;
    while(a > 0 && b > 0){
        if(a < b){
            swap(a, b);
        }
        ll g = a%b;
        if((x-g)%b == 0 && x <= a){
            cout << "YES" << '\n';
            return;
        }
        a = g;
    }
    cout << "NO" << '\n';
}
 
int main(){
    io
    int t; cin >> t;
    while(t--){
        solve();
    }
}