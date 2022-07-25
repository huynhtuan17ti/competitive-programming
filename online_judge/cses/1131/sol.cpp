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
int dp[MAXN];

void DFS(int u, int pre, int& diameter){
    vector <int> curDp;
    for(int v: G[u])
        if(v != pre){
            DFS(v, u, diameter);
            curDp.push_back(dp[v] + 1);
            dp[u] = max(dp[u], dp[v] + 1);
        }
    sort(curDp.begin(), curDp.end(), greater <int> ());
    diameter = max(diameter, dp[u]);
    if(curDp.size() >= 2)
        diameter = max(diameter, curDp[0] + curDp[1]);
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
    int diameter = 0;
    DFS(1, 0, diameter);
    cout << diameter << '\n';
}