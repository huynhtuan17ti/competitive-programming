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
 
const int MAXN = 2005;

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int t; cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        ll res = 1;
        int cnt = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++){
                char x;
                cin >> x;
                if(x == '#'){
                    res = 2LL*res%MOD;
                    cnt++;
                }
            }
        if(cnt == n*m)
            res = (res - 1 + MOD)%MOD;
        cout << res << '\n';
    }
}