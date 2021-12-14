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

int vi[MAXN], par[MAXN];
int e_cycle, s_cycle;

void DFS(int u, int pre){
    vi[u] = 1;
    for(int v: G[u])
        if(!vi[v]){
            par[v] = u;
            DFS(v, u);
        }
        else 
            if(v != pre){
                e_cycle = v;
                s_cycle = u;
            }

}

int main(){
    io
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i = 1; i <= n; i++)
        if(!vi[i])
            DFS(i, 0);

    if(e_cycle == 0){
        return cout << "IMPOSSIBLE", 0;
    }
    
    vector <int> path;
    for(int u = e_cycle; u != s_cycle; u = par[u])
        path.push_back(u);
    path.push_back(s_cycle);
    
    reverse(path.begin(), path.end());
    path.push_back(path[0]);

    cout << path.size() << '\n';
    for(int u: path)
        cout << u << ' ';
}