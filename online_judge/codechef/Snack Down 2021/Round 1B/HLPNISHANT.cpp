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

void solve(){
    ll k;
    cin >> k;
    ll p = (int)sqrt((k-1)*2);
    if(p*(p+1) > (k-1)*2)
        p--;
    if((p+1)*(p+2) <= (k-1)*2)
        p++;
    cout << p*2 + 2 << '\n';
}

int main(){
    io
    int t; cin >> t;
    while(t--){
        solve();
    }
}