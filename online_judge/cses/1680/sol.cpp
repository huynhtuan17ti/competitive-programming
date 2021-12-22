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

vector <int> G[MAXN];
int vi[MAXN];
stack <int> st;

void DFS(int u){
    vi[u] = 1;
    for(int v: G[u])
        if(!vi[v])
            DFS(v);
    st.push(u);
}

int main(){
    io
    //freopen("test.inp", "r", stdin);
    int n, m;
    cin >> n >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
    }
    DFS(1);

    fill(vi+1, vi+1+n, false);
    vector <int> dp(n+1, -n-1), parent(n+1);
    while(!st.empty()){
        int u = st.top();
        if(u == 1)
            dp[u] = 0;
        vi[u] = true;
        for(int v: G[u])
            if(vi[v]){
                return cout << "IMPOSSIBLE", 0;
            }else if(dp[u] + 1 > dp[v]){
                dp[v] = dp[u] + 1;
                parent[v] = u;
            }
        st.pop();
    }
    if(dp[n] < 0)
        return cout << "IMPOSSIBLE", 0;
    vector <int> path;
    for(int u = n; u > 0; u = parent[u])
        path.push_back(u);
    reverse(path.begin(), path.end());
    cout << path.size() << '\n';
    for(int u: path)
        cout << u << ' ';
}