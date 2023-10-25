#include <bits/stdc++.h>

using namespace std;

constexpr int INF = 1e9;
constexpr int N = 300;
static vector<vector<int>> G(N, vector<int>(N, INF));

inline void Floyd(int n) {
  for (int i = 0; i < n; ++i)
    G[i][i] = 0;

  // floyd
  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        if (G[i][k] != INF && G[k][j] != INF && G[i][j] > G[i][k] + G[k][j]) {
          G[i][j] = G[i][k] + G[k][j];
        }
      }

  // check negative cycles
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      for (int k = 0; k < n; ++k)
        if (G[i][k] != INF && G[k][j] != INF && G[k][k] < 0)
          G[i][j] = -INF;
}
