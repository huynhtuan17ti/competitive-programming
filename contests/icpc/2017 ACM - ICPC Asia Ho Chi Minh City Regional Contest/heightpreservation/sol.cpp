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
const int MAXN = 1e6 + 5;

vector <int> s[MAXN];
vii G[MAXN];
int dp[MAXN];

int getIndex(int i, int j, int n){
    return i*n + j;
}

void gen_graph(int m, int n){
    for(int i = 0; i < m; i++){
        vii st;
        for(int j = 0; j < n; j++)
            st.push_back({s[i][j], getIndex(i, j, n)});
        sort(st.begin(), st.end());
        for(int j = 1; j < n; j++)
            if(st[j].fi != st[j-1].fi){
                G[st[j].se].push_back({st[j-1].se, 1});
            }
            else G[st[j].se].push_back({st[j-1].se, 0});
    }

    for(int j = 0; j < n; j++){
        vii st;
        for(int i = 0; i < m; i++){
            st.push_back({s[i][j], getIndex(i, j, n)});
        }
        sort(st.begin(), st.end());
        for(int i = 1; i < m; i++)
            if(st[i].fi != st[i-1].fi)
                G[st[i].se].push_back({st[i-1].se, 1});
            else G[st[i].se].push_back({st[i-1].se, 0});
    }
}

stack <int> S;
bool vi[MAXN];

void DFS(int u){
    vi[u] = true;
    for(ii v: G[u])
        if(!vi[v.fi])
            DFS(v.fi);
    S.push(u);
}

void topoSort(int len){
    for(int i = 0; i < len; i++)
        if(!vi[i])
            DFS(i);
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int m, n; cin >> m >> n;
    for(int i = 0; i < m; i++){
        s[i].resize(n+1);
        for(int j = 0; j < n; j++)
            cin >> s[i][j];
    }
    
    gen_graph(m, n);
    topoSort(m*n);
    int res = 0;
    while(!S.empty()){
        int u = S.top();
        S.pop();
        for(ii v: G[u])
            dp[v.fi] = max(dp[v.fi], dp[u] + v.se);
        res = max(res, dp[u] + 1);
    }
    cout << res;
}