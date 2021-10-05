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
const int MAXN = 1e5 + 5;
 
int a[MAXN];
vector <int> G[MAXN];
int sum_xor[MAXN];
int cnt = 0;
 
void DFS(int u, int pre, int sum){
    sum_xor[u] ^= a[u];
    for(int v: G[u])
        if(v != pre){
            DFS(v, u, sum);
            sum_xor[u] ^= sum_xor[v];
        }
    if(sum_xor[u] == sum){
        sum_xor[u] = 0;
        cnt++;
    }
}
 
void solve(){
    int k, n;
    cin >> n >> k;
    int sum = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum ^= a[i];
    }
 
    cnt = 0;
    for(int i = 1; i <= n; i++){
        sum_xor[i] = 0;
        G[i].clear();
    }
 
    vii edges;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
        edges.push_back({u, v});
    }
    if(sum == 0){
        cout << "YES" << '\n';
    }else{
        DFS(1, 0, sum);
        if(k == 2){
            cout << "NO" << '\n';
            return;
        }
        int num_split = cnt-1;
        if(num_split >= 2)
            cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}
 
int main(){
    io
    int t; cin >> t;
    while(t--){
        solve();
    }
}