#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 100005;

vector<int> G[MAXN];
int w[MAXN];
int low[MAXN], num[MAXN], SCC[MAXN];
ll wSCC[MAXN];
int cntTime = 0, cntSCC = 0;
stack<int> st;

void DFS(int u) {
  num[u] = low[u] = ++cntTime;
  st.push(u);
  for (int v : G[u])
    if (num[v])
      low[u] = min(low[u], num[v]);
    else {
      DFS(v);
      low[u] = min(low[u], low[v]);
    }
  if (low[u] == num[u]) {
    int v;
    cntSCC++;
    do {
      v = st.top();
      st.pop();
      SCC[v] = cntSCC;
      wSCC[cntSCC] += w[v];
      low[v] = num[v] = INT_MAX;
    } while (u != v);
  }
}