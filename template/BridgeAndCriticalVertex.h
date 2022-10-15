#include <bits/stdc++.h>  
using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int MAXN = 5e5 + 5;

vector<int> G[MAXN];

int cnt = 0;
int low[MAXN], num[MAXN];
int numChild[MAXN], criVertex[MAXN], bridgeCnt = 0;
stack<int> st;
void DFS(int u, int pre) {
    num[u] = ++cnt;
    low[u] = INT_MAX;

    for(int v: G[u]) {
        if(v == pre) continue;
        if(num[v]) {
            low[u] = min(low[u], num[v]);
        }else {
            numChild[u]++;
            DFS(v, u);
            if(low[v] >= num[u]) criVertex[u] = 1;
            if(low[v] > num[u]) bridgeCnt++;
            low[u] = min(low[u], low[v]);
        }
    }
}

int main(){
    io
    int n, m;
    cin >> n >> m;
    while(m--) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i = 1; i <= n; i++)
        if(!num[i]) {
            DFS(i, 0);
            if(numChild[i] < 2)
                criVertex[i] = 0;
        }
    int criVertexCnt = 0;
    for(int i = 1; i <= n; i++)
        criVertexCnt += criVertex[i];
    cout << criVertexCnt << ' ' << bridgeCnt << '\n';
}