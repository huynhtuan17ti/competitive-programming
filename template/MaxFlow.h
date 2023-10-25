#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// [trick lord]
// min-cur vertices
// ---> split a vertex into 2 different vertices and make an edge between them, 
// can use in(v) and out(v) where in(v) = 2*v and out(v) = 2*v + 1, the capacity is 1 and others is 2
class MaxFlow {
 public:
  MaxFlow(size_t n) : n_(n) {
    G.resize(n+1);
    Fill2DVector(c, n+1);
    Fill2DVector(f, n+1);
    len.resize(n+1);
    trace.resize(n+1);
    st.resize(n+1);
  }

  void AddEdge(int u, int v, int w, bool is_directed = true) {
    G[u].push_back(v);
    G[v].push_back(u);
    c[u][v] = w; 
    if (!is_directed)
      c[v][u] = w;
  } 

  bool ShortPaths(int s, int e) {
    fill(len.begin(), len.end(), INF);
    fill(st.begin(), st.end(), 2);
    fill(trace.begin(), trace.end(), -1);
    deque<int> q;
    q.push_back(s); len[s] = 0;
    while(!q.empty()){
      int u = q.front();
      q.pop_front();
      st[u] = 0;
      for(int v: G[u]){
        int cost = (f[u][v] >= 0)? 1 : -1;
        if(c[u][v] > f[u][v] && len[v] > len[u] + cost){
          len[v] = len[u] + cost;
          trace[v] = u;
          if(st[v] == 0){
            st[v] = 1;
            q.push_front(v);
          }
          if(st[v] == 2){
            st[v] = 1;
            q.push_back(v);
          }
        }
      }
    }
    return (len[e] != INF);
  }

  // Perform finding max-flow
  int Finalize(int s, int e) {
    int max_flow = 0;
    while(ShortPaths(s, e)){
      int flow = INF;
      for(int v = e; v != s; v = trace[v]){
        int u = trace[v];
        flow = min(flow, c[u][v] - f[u][v]);
      }
      
      for(int v = e; v != s; v = trace[v]){
        int u = trace[v];
        f[u][v] += flow;
        f[v][u] -= flow;
      }
      max_flow += flow;
    }
    return max_flow;
  } 

  // NOTE: note sure it is correct
  vector<ii> MinCutEdges(int s) {
    vector<int> vi(n_ + 1);
    vector<int> ver;
    function<void(int)> dfs = [&](int u) {
      vi[u] = 1;
      ver.push_back(u);
      for(int v: G[u])
        if(!vi[v] && c[u][v] - f[u][v] > 0)
          dfs(v);
    };

    vii edges;
    dfs(s);
    for(int u: ver)
      for(int v: G[u]) {
        if (vi[v]) continue;
        if (c[u][v] != 0 && c[u][v] - f[u][v] <= 0)
          edges.emplace_back(u, v);
      }
    return edges;
  }

  int residual(int u, int v) const noexcept {
    return c[u][v] - f[u][v];
  }

  vector<vector<int>>& graph() noexcept {
    return G;
  }


 private:
  vector<vector<int>> G;
  vector<vector<int>> c, f;
  vector<int> len, trace, st;

  template <typename T>
  void Fill2DVector(vector<vector<T>>& x, int sz) {
    x.resize(sz);
    for(int i = 0; i < sz; ++i)
      x[i].resize(sz);
  }

  size_t n_;
};