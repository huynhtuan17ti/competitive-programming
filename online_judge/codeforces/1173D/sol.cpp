#include <bits/stdc++.h>  
 
using namespace std;
 
const int MOD = 998244353;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define mp make_pair
#define fi first
#define se second
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int MAXN = 200005; 

int num_child[MAXN];
ll dp[MAXN];
vector <int> G[MAXN];
ll F[MAXN];

void initialize(int n){
    F[0] = 1;
    for(int i = 1; i <= n; i++)
        F[i] = (F[i-1]*i)%MOD;
}

void DFS(int u, int pre){
    num_child[u] = 1;
    dp[u] = F[(int)G[u].size()];
    for(int v: G[u])
        if(v != pre){
            DFS(v, u);
            num_child[u] += num_child[v];
            dp[u] = (dp[u]*dp[v])%MOD;
        }
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n; cin >> n;
    initialize(n);
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    DFS(1, 0);
    cout << (dp[1]*n)%MOD;
}