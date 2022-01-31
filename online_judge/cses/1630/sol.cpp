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
    int n; cin >> n;
    vii a(n);
    for(auto &[u, d]: a)
        cin >> u >> d;

    sort(a.begin(), a.end());
    ll ans = 0, prefixSum = 0;
    for(auto [u, d]: a){
        prefixSum += u;
        ans += (d - prefixSum);
    }
    cout << ans << '\n';
}