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
    int n, m;
    cin >> n >> m;
    vector <int> pos(n+1);
    vector <int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pos[a[i]] = i;
    }
    pos[0] = n+1;
    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans += (pos[i-1] > pos[i]);

    vector <bool> vi(n+1);
    auto remove = [&](int val){
        ans -= (!vi[val-1] && pos[val-1] > pos[val]);
        if(val < n)
            ans -= (!vi[val+1] && pos[val] > pos[val+1]);
        vi[val] = 1;
    };

    auto add = [&](int val){
        ans += (!vi[val-1] && pos[val-1] > pos[val]);
        if(val < n)
            ans += (!vi[val+1] && pos[val] > pos[val+1]);
        vi[val] = 1;
    };
    
    while(m--){
        int u, v;
        cin >> u >> v;
        remove(a[u]);
        remove(a[v]);
        vi[a[u]] = vi[a[v]] = 0;
        pos[a[u]] = v;
        pos[a[v]] = u;
        add(a[u]);
        add(a[v]);
        vi[a[u]] = vi[a[v]] = 0;
        swap(a[u], a[v]);

        cout << ans << '\n';
    }
}