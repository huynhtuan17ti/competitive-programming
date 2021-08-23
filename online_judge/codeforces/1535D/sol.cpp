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
const int MAXN = 1e6;
 
vector <int> G[MAXN];
int dp[MAXN], parent[MAXN];
int n;
string s;

void up(int u, int L, int R){
    if(s[u - n - 1] == '?')
        dp[u] = dp[L] + dp[R];
    else if(s[u - n - 1] == '0'){
        dp[u] = dp[L];
    }else
        dp[u] = dp[R];
}

void build(int u){
    if(G[u].size() == 0){
        dp[u] = 1;
        return;
    }
    int L = G[u][0], R = G[u][1];
    parent[L] = u; parent[R] = u;
    build(L);
    build(R);
    up(u, L, R);
}
 
void update(int u, int x){
    if(x == 0)
        return;
    int L = G[x][0], R = G[x][1];
    up(x, L, R);
    update(u, parent[x]);
}
 
int main(){
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    io
    int k; cin >> k;
    n = (1<<k);
    cin >> s;
    queue <int> Q;
    for(int i = 1; i <= n; i++)
        Q.push(i);
    int node = n;
    while(Q.size() >= 2){
        int u = Q.front();
        Q.pop();
        int v = Q.front();
        Q.pop();
        node++;
        G[node].push_back(u);
        G[node].push_back(v);
        Q.push(node);
    }
    build(node);
    int q; cin >> q;
    while(q--){
        int pos;
        char c;
        cin >> pos >> c;
        s[pos-1] = c;
        update(node, pos + n);
        cout << dp[node] << '\n';
    }
}