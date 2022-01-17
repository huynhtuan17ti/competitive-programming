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
int low[MAXN], num[MAXN], cntSCC = 0, SCC[MAXN], cntTime = 0;
stack <int> st;

void DFS(int u){
    low[u] = num[u] = ++cntTime;
    st.push(u);
    for(int v: G[u])
        if(num[v])
            low[u] = min(low[u], num[v]);
        else{
            DFS(v);
            low[u] = min(low[v], low[u]);
        }
    if(num[u] == low[u]){
        int v;
        cntSCC++;
        do{
            v = st.top();
            st.pop();
            SCC[v] = cntSCC;
            low[v] = num[v] = INT_MAX;
        }while(u != v);
    }
}

int main(){
    io
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
    }
    for(int i = 1; i <= n; i++)
        if(!num[i])
            DFS(i);
    cout << cntSCC << '\n';
    for(int i = 1; i <= n; i++)
        cout << SCC[i] << ' ';
}