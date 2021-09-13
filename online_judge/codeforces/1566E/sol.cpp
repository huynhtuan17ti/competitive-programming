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

vector <int> G[MAXN];
int F[MAXN]; // 0: norm, 1: leaf, 2: bud 

void DFS(int u, int pre){
    if(G[u].size() == 1 && u != 1){
        F[u] = 1;
        return;
    }

    vector <int> a;
    int Min = 3, Max = 0;
    for(int v: G[u])
        if(v != pre){
            DFS(v, u);
            Min = min(Min, F[v]);
            Max = max(Max, F[v]);
        }
    if(Min == Max){
        if(Max == 2)
            F[u] = 1;
        if(Max == 1 && u != 1)
            F[u] = 2;
    }else if(u != 1)
        F[u] = 2;
}

void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++)
        G[i].clear();
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    fill(F+1, F+1+n, 0);
    DFS(1, 0);
    int num_leaf = 0, num_bud = 0;
    for(int i = 1; i <= n; i++){
        if(F[i] == 1)
            num_leaf++;
        if(F[i] == 2)
            num_bud++;
    }
    cout << num_leaf - num_bud << '\n';
}

int main(){
    io
    int t; cin >> t;
    while(t--){
        solve();
    }
}