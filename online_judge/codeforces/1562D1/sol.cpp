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
    int n, q;
    cin >> n >> q;
    vector <int> s(n+1);
    for(int i = 1; i <= n; i++){
        char ch; cin >> ch;
        s[i] = s[i-1] + ((i%2 == 1)?1 : -1) * ((ch == '+')? 1: -1);
    }
    while(q--){
        int l, r;  cin >> l >> r;
        int val = s[r] - s[l-1];
        if(l%2 == 0)
            val = -val;
        if(val == 0){
            cout << 0 << '\n';
        }else{
            if((r-l+1)%2 == 0)
                cout << 2 << '\n';
            else cout << 1 << '\n';
        }
    }
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int t; cin >> t;
    while(t--){
        solve();
    }
}