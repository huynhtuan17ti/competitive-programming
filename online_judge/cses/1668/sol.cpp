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

bool is_old_cycle = false;
int color[MAXN];
void DFS(int u, int c){
    color[u] = c;
    for(int v: G[u])
        if(color[v] == 0)
            DFS(v, 3 - c);
        else if(color[v] != 3-c)
            is_old_cycle = true;
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
        if(!color[i])
            DFS(i, 1);
    
    if(is_old_cycle)
        cout << "IMPOSSIBLE" << '\n';
    else
        for(int i = 1; i <= n; i++)
            cout << color[i] << ' ';
}