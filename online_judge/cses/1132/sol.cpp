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

ii dp[MAXN][2];

void DFS(int u, int pre){
    dp[u][0].fi = 0;
    dp[u][0].se = 0;

    dp[u][1].fi = -1;
    dp[u][1].se = -1;

    for(int v: G[u])
        if(v != pre){
            DFS(v, u);
            if(dp[v][0].fi + 1 >= dp[u][0].fi){
                dp[u][1] = dp[u][0];
                dp[u][0].fi = dp[v][0].fi + 1;
                dp[u][0].se = v;
            }else if(dp[v][0].fi + 1 > dp[u][1].fi){
                dp[u][1].fi = dp[v][0].fi + 1;
                dp[u][1].se = v;
            }
        }
}

int longest_path_up[MAXN];
void DFS_longest_path_up(int u, int pre){
    if(pre >= 1)
        longest_path_up[u] = max(longest_path_up[pre], (dp[pre][0].se != u)? dp[pre][0].fi : dp[pre][1].fi) + 1;
    for(int v: G[u])
        if(v != pre){
            DFS_longest_path_up(v, u);
        }
}


int main(){
    io
    //freopen("test.inp", "r", stdin);
    int n; cin >> n;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    DFS(1, 0);
    DFS_longest_path_up(1, 0);

    for(int i = 1; i <= n; i++){
        cout << max(longest_path_up[i], dp[i][0].fi) << ' ';
    }
}