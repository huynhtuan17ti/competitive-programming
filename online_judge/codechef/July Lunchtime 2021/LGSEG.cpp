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
int a[MAXN], F[MAXN], vi[MAXN];
ll sum[MAXN];
vector <int> G[MAXN];
int cnt = 0;
int in[MAXN], out[MAXN];

void DFS_level(int u){
    cnt += 1;
    in[u] = out[u] = cnt;
    for(int v: G[u]){
        F[v] = F[u] + 1;
        DFS_level(v);
        out[u] = max(out[u], out[v]);
    }
}

int res = 0;

void DFS(int u, int pre, int k){
    int num = 0;
    if(F[u] - F[pre] > k){
        for(int v: G[pre])
            if(in[v] <= in[u] && in[u] <= out[v]){
                pre = v;
                num++;
            }
    }
    res = max(res, u - pre);
    for(int v: G[u]){
        DFS(v, pre, k);
    }
}

void solve(){
    int n, k, s;
    cin >> n >> k >> s;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }
    for(int i = 0; i <= n; i++)
        G[i].clear();
    int j = 0;
    for(int i = 1; i <= n; i++){
        while(j < i && sum[i] - sum[j] > s)
            j += 1;
        G[j].push_back(i);
    }
    res = 0;
    cnt = 0;
    for(int i = 0; i <= n; i++){
        in[i] = out[i] = 0;
    }
    DFS_level(0);
    DFS(0, 0, k);
    cout << res << '\n';
}

int main(){
    io
    int t; cin >> t;
    while(t--){
        solve();
    }
}