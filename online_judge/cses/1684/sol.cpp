/*
    2-SAT problem
    Ref: https://drive.google.com/file/d/15UbO4GWo1G6cUBDnV6uWk0KxjuEdurCG/view
*/
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
vector <int> Gv2[MAXN];

int low[MAXN], num[MAXN];
int cntTime = 0, cntSCC = 0, SCC[MAXN];
vector <int> inSCC[MAXN];
stack <int> st;
queue <int> q;

void DFS(int u){
    low[u] = num[u] = ++cntTime;
    st.push(u);
    for(int v: G[u])
        if(num[v])
            low[u] = min(low[u], num[v]);
        else{
            DFS(v);
            low[u] = min(low[u], low[v]);
        }
    if(low[u] == num[u]){
        int v;
        cntSCC++;
        do{
            v = st.top();
            st.pop();
            SCC[v] = cntSCC;
            inSCC[cntSCC].push_back(v);
            low[v] = num[v] = INT_MAX;
        }while(u != v);
    }
}

void DFS_topo(int u){
    num[u] = 1;
    for(int v: Gv2[u])
        if(!num[v])
            DFS_topo(v);
    q.push(u);
}

int main(){
    io
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int n, m;
    cin >> m >> n;
    
    auto getNot = [&](int u)->int{
        if(u > n)
            return u - n;
        return u + n;
    };

    while(m--){
        char c1, c2;
        int u, v;
        cin >> c1 >> u >> c2 >> v;
        if(c1 == '-') u += n;
        if(c2 == '-') v += n;
        G[getNot(u)].push_back(v);
        G[getNot(v)].push_back(u);
    }

    for(int i = 1; i <= 2*n; i++)
        if(!num[i])
            DFS(i);
    
    vector <int> notSCC(2*n+1);

    // check if exist u and -u are in the same component
    for(int i = 1; i <= n; i++)
        if(SCC[i] == SCC[i+n])
            return cout << "IMPOSSIBLE", 0;
        else{
            notSCC[SCC[i]] = SCC[i+n];
            notSCC[SCC[i+n]] = SCC[i];
        }

    // build new graph
    for(int i = 1; i <= 2*n; i++)
        for(int v: G[i])
            if(SCC[i] != SCC[v]){
                Gv2[SCC[i]].push_back(SCC[v]);
            }

    // topological sort
    fill(num+1, num+1+2*n, 0);
    for(int i = 1; i <= cntSCC; i++)
        if(!num[i])
            DFS_topo(i);

    vector <int> ansSCC(2*n+1, -1);
    vector <int> ans(2*n+1, 0);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(ansSCC[u] == -1){ // not pick
            ansSCC[u] = 1;
            ansSCC[notSCC[u]] = 0;
        }

        for(int v: inSCC[u]){
            ans[v] = ansSCC[u];
        }
    }

    for(int i = 1; i <= n; i++)
        cout << ((ans[i])? '+' : '-') << ' ';
}