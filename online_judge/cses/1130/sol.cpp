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
int dp[MAXN][2];

void DFS(int u, int pre){
    int sumDp = 0;
    int maxDp = 0;
    for(int v: G[u])
        if(v != pre){
            DFS(v, u);
            sumDp += max(dp[v][0], dp[v][1]);
            maxDp = max(maxDp, dp[v][0] + 1 - max(dp[v][0], dp[v][1]));
        }
    dp[u][0] = sumDp;
    dp[u][1] = sumDp + maxDp;
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
    cout << max(dp[1][0], dp[1][1]);
}