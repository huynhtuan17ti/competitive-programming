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
    int n, x; cin >> n >> x;
    ll preSum = 0;
    map <ll, int> cnt;
    cnt[0]++;
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        int u; cin >> u;
        preSum += u;
        ans += cnt[preSum-x];
        cnt[preSum]++;
    }
    cout << ans << '\n';
}