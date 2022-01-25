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
    vector <int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    auto get = [&](int val)->ll{
        ll ans = 0;
        for(int x: a)
            ans += abs(x - val);
        return ans;
    };
    sort(a.begin(), a.end());
    ll ans = min(get(a[n/2-1]), get(a[n/2]));
    cout << ans << '\n';
}