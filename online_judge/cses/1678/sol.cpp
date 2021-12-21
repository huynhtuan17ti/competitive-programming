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

bool vi[MAXN];
int parent[MAXN];
int instack[MAXN];
int s = -1, e = -1;

void DFS(int u){
    vi[u] = 1;
    instack[u] = 1;
    for(int v: G[u])
        if(!vi[v]){
            parent[v] = u;
            DFS(v);
        }
        else if(instack[v]){
            s = v;
            e = u;
            break;
        }
    instack[u] = 0;
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
    for(int i = 1; i <= n; i++)
        if(!vi[i])
            DFS(i);
    
    if(s == -1)
        cout << "IMPOSSIBLE" << '\n';
    else{
        vector <int> path;
        for(int u = e;; u = parent[u]){
            path.push_back(u);
            if(u == s)
                break;
        }
        reverse(path.begin(), path.end());
        path.push_back(s);
        cout << path.size() << '\n';
        for(int u: path)
            cout << u << ' ';
    }
}