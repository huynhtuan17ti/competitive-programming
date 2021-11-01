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

/*
       X     Y
      / \   / \
     /   \ /   \
    A     G     B
    
    gcd(a+g, a+b+g, b+g) = gcd(a, b, g)
*/

map <vector <int>, ll> sum;
vector <int> state[MAXN];

void solve(){
    int n, m;
    cin >> n >> m;
    vector <ll> c(n+1);
    for(int i = 1; i <= n; i++)
        cin >> c[i];
    for(int i = 1; i <= n; i++)
        state[i].clear();
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        state[v].push_back(u);
    }
    
    for(int i = 1; i <= n; i++){
        sort(state[i].begin(), state[i].end());
    }
    sum.clear();
    
    for(int i = 1; i <= n; i++){
        sum[state[i]] += c[i];
    }
    ll ans = 0;
    for(auto u: sum)
        if(u.fi.size() > 0)
            ans = __gcd(ans, u.se);
    cout << ans << '\n';
}

int main(){
    io
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);

    int t; cin >> t;
    while(t--){
        solve();
    }
}