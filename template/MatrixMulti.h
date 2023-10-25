#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

template <typename T> struct Matrix {
  static int dim;
  vector<vector<T>> data;

  Matrix(bool identity = false) {
    data.resize(dim);
    for (int i = 0; i < dim; ++i)
      data[i].resize(dim, 0);
    if (identity)
      for (int i = 0; i < dim; ++i)
        data[i][i] = 1;
  }

  Matrix operator*(const Matrix<T> &other) {
    Matrix<T> res;
    for (int k = 0; k < dim; ++k)
      for (int i = 0; i < dim; ++i)
        for (int j = 0; j < dim; ++j) {
          res.data[i][j] += data[i][k] * other.data[k][j] % MOD;
          res.data[i][j] %= MOD;
        }
    return res;
  }

  // fast calculating A^b
  static Matrix fastPow(Matrix<T> &A, ll b) {
    if (b == 0)
      return Matrix(true);
    if (b == 1)
      return A;
    Matrix t = fastPow(A, b >> 1);
    t = t * t;
    if (b & 1)
      t = t * A;
    return t;
  }
};

template <typename T> int Matrix<T>::dim = 2;
