template <typename T> class SegmentTree {
private:
  struct node {
    T val;
    node() { val = 0; }
  };

private:
  void update(int id, int l, int r, int u, T val) {
    if (u < l || r < u)
      return;
    if (l == r && l == u) {
      IT[id].val = val;
      return;
    }
    int mid = (l + r) >> 1;
    update(2 * id, l, mid, u, val);
    update(2 * id + 1, mid + 1, r, u, val);
    IT[id].val = min(IT[2 * id].val, IT[2 * id + 1].val);
  }

  T get(int id, int l, int r, int u, int v) {
    if (v < l || r < u)
      return inf;
    if (u <= l && r <= v)
      return IT[id].val;
    int mid = (l + r) >> 1;
    T L = get(2 * id, l, mid, u, v);
    T R = get(2 * id + 1, mid + 1, r, u, v);
    return min(L, R);
  }

public:
  int nVertex;
  vector<node> IT;

public:
  SegmentTree(int n) {
    IT.resize(4 * n + 5);
    nVertex = n;
  }
  void update(int u, T val) { update(1, 1, nVertex, u, val); }
  T get(int u, int v) { return get(1, 1, nVertex, u, v); }
};