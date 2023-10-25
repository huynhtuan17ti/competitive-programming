#include <bits/stdc++.h>
using namespace std;

/*
    https://cses.fi/problemset/task/2166/
    Problem:
    Given an array with n elements and q queries.
    There are 2 type of query:
    - Query 1: 1 k v
        Update value at position k to v
    - Query 2: 2 a b
        Find maximum prefix sum in subarray from position a to b
*/

typedef long long ll;
const int MAXN = 2e5 + 5;
const ll inf = 1e15;
ll sum[MAXN];

template <typename T> class LazySegmentTree {
private:
  struct node {
    T val, lazy;
    node() { val = lazy = 0; }
  };

private:
  void push(int id, T val) {
    IT[id].val += val;
    IT[id].lazy += val;
  }

  void down(int id) {
    T k = IT[id].lazy;
    if (k == 0)
      return;

    push(2 * id, k);
    push(2 * id + 1, k);

    IT[id].lazy = 0;
  }

  void build(int id, int l, int r) {
    if (l == r) {
      IT[id].val = sum[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    IT[id].val = max(IT[2 * id].val, IT[2 * id + 1].val);
  }

  void update(int id, int l, int r, int u, int v, T val) {
    if (v < l || r < u)
      return;
    if (u <= l && r <= v) {
      push(id, val);
      return;
    }
    down(id);
    int mid = (l + r) >> 1;
    update(2 * id, l, mid, u, v, val);
    update(2 * id + 1, mid + 1, r, u, v, val);
    IT[id].val = max(IT[2 * id].val, IT[2 * id + 1].val);
  }

  T get(int id, int l, int r, int u, int v) {
    if (u == v && v == 0)
      return 0;
    if (v < l || r < u)
      return -inf;
    if (u <= l && r <= v)
      return IT[id].val;
    down(id);
    int mid = (l + r) >> 1;
    T L = get(2 * id, l, mid, u, v);
    T R = get(2 * id + 1, mid + 1, r, u, v);
    return max(L, R);
  }

public:
  int nVertex;
  vector<node> IT;

public:
  LazySegmentTree(int n) : nVertex(n) { IT.resize(4 * n + 5); }

  void build(int l, int r) { build(1, nVertex); }

  void update(int u, int v, T val) { update(1, 1, nVertex, u, v, val); }

  T get(int u, int v) { return get(1, 1, nVertex, u, v); }
};