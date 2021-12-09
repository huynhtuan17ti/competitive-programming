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

void solve(){
    int n; cin >> n;
    vector <int> a(n+1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    
    ll ans = 0;
    map <int, int> M;
    for(int i = 1; i <= n; i++){
        ans += 1LL*(n - i + 1)*M[a[i]];
        M[a[i]] += i;
    }
    cout << ans << '\n';
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