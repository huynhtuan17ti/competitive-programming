#include <bits/stdc++.h>  
using namespace std;
 
constexpr int MOD = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define mp make_pair
#define fi first
#define se second
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};
constexpr int MAXN = 2001;

set<int> s;
vector<int> G[MAXN];
int vi[MAXN], d[MAXN];

void DFS(int u, int root, int len) {
    vi[u] = 1;
    for(int v: G[u])
        if(!vi[v]) {
            DFS(v, root, len + 1);
        }
}

int main() {
    io
    int n, m;
    cin >> n >> m;
    while(m--) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for(int i = 1; i <= n; ++i) {
       fill(vi+1, vi+1+n, 0);
       DFS(i, i, 0);
    }

    int P = 0;
    for(auto v: s) {
        P = __gcd(P, v);
    }

    vector<int> ans;
    for(int i = 1; i <= P; ++i)
        if(P % i == 0)
            ans.push_back(i);
    
    for(int u: ans)
        cout << u << " ";
    cout << '\n';
}
