/*
    Easily to see that:
        - An edge (u, v) denotes "imposter" if u and v have different role.
        - Else u and v have same role
    Now, the maximum number of imposters is the maximum between number of both roles.
    Our graph now becomes a bipartite graph.
    For each component, if can divide its vertices into 2 disjoint sets then the maximum number of 
    imposters in this component is the maximum number of verties between 2 sets. Else, the graph contains contradiction.
*/

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
 
vector <int> G[MAXN], G_new[MAXN];
vector <int> comp[MAXN];
int visited[MAXN];
int cnt_comp = 0;
int num_comp[MAXN];
int id_comp[MAXN];
 
void DFS_comp(int u){
    id_comp[u] = cnt_comp;
    num_comp[cnt_comp]++;
    visited[u] = true;
    for(int v: comp[u])
        if(!visited[v])
            DFS_comp(v);
}
 
bool is_odd_cycle = false;
int cnt[2];
int _color[MAXN];
void DFS(int u, int color){
    _color[u] = color;
    visited[u] = true;
    cnt[color] += num_comp[u];
    for(int v: G_new[u])
        if(!visited[v])
            DFS(v, 1 - color);
        else if(1-color != _color[v]){
            is_odd_cycle = true;
        }
}
 
void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        num_comp[i] = 0;
        id_comp[i] = 0;
        _color[i] = -1;
        G[i].clear();
        G_new[i].clear();
        comp[i].clear();
    }
    while(m--){
        int u, v;
        string type;
        cin >> u >> v >> type;
        if(type[0] == 'i'){
            G[u].push_back(v);
            G[v].push_back(u);
        }else{
            comp[u].push_back(v);
            comp[v].push_back(u);
        }
    }
 
    cnt_comp = 0;
    fill(visited+1, visited+1+n, false);
    for(int i = 1; i <= n; i++)
        if(!visited[i]){
            cnt_comp++;
            DFS_comp(i);
        }
 
    bool is_ans = true;
    for(int i = 1; i <= n; i++){
        for(int v: G[i])
            if(id_comp[v] != id_comp[i]){
                G_new[id_comp[v]].push_back(id_comp[i]);
                G_new[id_comp[i]].push_back(id_comp[v]);
            }else{
                is_ans = false;
                break;
            }
    }
 
    if(!is_ans){
        cout << -1 << '\n';
        return;
    }
 
    int res = 0;
    fill(visited+1, visited+1+n, false);
    for(int i = 1; i <= cnt_comp; i++)
        if(!visited[i]){
            is_odd_cycle = false;
            cnt[0] = cnt[1] = 0;
            DFS(i, 0);
            if(is_odd_cycle){
                is_ans = false;
                break;
            }
            res += max(cnt[0], cnt[1]);
        }
    if(!is_ans){
        cout << -1 << '\n';
        return;
    }
    cout << res << '\n';
}
 
int main(){
    io
    int t; cin >> t;
    while(t--){
        solve();
    }
}