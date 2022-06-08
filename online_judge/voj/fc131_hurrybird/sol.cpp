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
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
const int MAXN = 5e5 + 5;

int main(){
    io
    int t; cin >> t;
    while(t--){
        ll n, m, x, y;
        cin >> n >> m >> x >> y;
        n--; m--;
        ll Min = min(n, m), Max = max(n, m);
        ll ans = Min * min(y, 2*x);
        if(n == 0){
            ans += (Max - Min) * x;
        }else{
            ans += min((Max - Min) * x, (Max - Min) / 2 * 2 * y + (Max - Min) % 2 * x);
        }
        cout << ans << '\n';
    }
}
