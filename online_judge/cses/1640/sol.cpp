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

int main(){
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    io
    int n, X;
    cin >> n >> X;
    map <int, int> M;
    ii ans;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        if(M.find(X-x) != M.end()){
            ans = mp(M[X-x], i);
        }
        M[x] = i;
    }
    if(ans.fi == 0)
        cout << "IMPOSSIBLE";
    else cout << ans.fi << ' ' << ans.se << '\n';
}