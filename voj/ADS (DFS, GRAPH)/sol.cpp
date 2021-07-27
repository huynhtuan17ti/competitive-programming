#include <bits/stdc++.h>

using namespace std;
#define MAXN 2005

vector <int> adj[MAXN];
int vi[MAXN], cnt_node = 0, cnt_edge = 0;

void DFS(int u){
    cnt_node++;
    vi[u] = 1;
    for(int v: adj[u]){
        cnt_edge += 1;
        if(!vi[v])
            DFS(v);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int res = 0;
    for(int i = 1; i <= n; i++){
        if(!vi[i]){
            cnt_node = 0;
            cnt_edge = 0;
            DFS(i);
            cnt_edge /= 2;
            res += (cnt_edge + 1 - cnt_node);
        }
    }
    cout << res << '\n';
}