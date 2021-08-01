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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        map <int, int> cnt;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            cnt[x] += 1;
        }
        ll res = 1LL*n*(n-1);
        for(auto x: cnt)
            res -= 1LL*x.se*(x.se-1);
        cout << res << '\n';
    }
}