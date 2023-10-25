/*
    Find Euler path from node 1 to n
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;
vector<int> G[MAXN];

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> inDeg(n + 1), outDeg(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    inDeg[v]++;
    outDeg[u]++;
  }

  if (outDeg[1] != inDeg[1] + 1 || inDeg[n] != outDeg[n] + 1)
    return cout << "IMPOSSIBLE", 0;

  for (int i = 2; i < n; i++)
    if (inDeg[i] != outDeg[i])
      return cout << "IMPOSSIBLE", 0;

  vector<int> ans;
  stack<int> st;
  st.push(1);
  while (!st.empty()) {
    int u = st.top();
    if (G[u].empty()) {
      ans.push_back(u);
      st.pop();
    } else {
      int v = G[u].back();
      G[u].pop_back();
      st.push(v);
    }
  }

  if (ans.size() != m + 1)
    return cout << "IMPOSSIBLE", 0;

  reverse(ans.begin(), ans.end());
  for (int u : ans)
    cout << u << ' ';
}