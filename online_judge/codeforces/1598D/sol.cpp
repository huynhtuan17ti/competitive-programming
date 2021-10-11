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
const int MAXN = 5e5 + 5;
 
void solve(){
    int n; cin >> n;
    vector <int> a(n);
    vector <int> b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    ll res = 1LL*n*(n-1)*(n-2)/6;
    ll mn_res = 0;
    map <int, int> aM, bM;
    for(int i = 0; i < n; i++){
        aM[a[i]]++;
        bM[b[i]]++;
    }
    for(int i = 0; i < n; i++){
        mn_res += 1LL*(aM[a[i]]-1)*(bM[b[i]]-1);
    }
    cout << res - mn_res << '\n';
}
 
int main(){
    io
    int t; cin >> t;
    while(t--){
        solve();
    }
}
