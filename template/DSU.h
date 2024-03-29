#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
  vector<int> parent;

  DSU(int n) { parent.resize(n + 1, -1); }

  int findSet(int u) {
    while (parent[u] > 0)
      u = parent[u];
    return u;
  }

  bool Union(int u, int v) {
    u = findSet(u);
    v = findSet(v);
    if (u == v)
      return false;

    int x = parent[u] + parent[v];
    if (parent[u] > parent[v]) {
      parent[v] = x;
      parent[u] = v;
    } else {
      parent[u] = x;
      parent[v] = u;
    }
    return true;
  }
};
