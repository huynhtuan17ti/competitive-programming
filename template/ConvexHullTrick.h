/*
    Given a set of pairs [a, b].
    With a number X, find the maximum value of a * X + b.
*/

const long double esp = 1e-7;

template <typename T> struct Line {
  T a, b;
  int id;
  Line(T a = 0, T b = 0, T id = 0) : a(a), b(b), id(id) {}

  bool operator<(const Line &l) const {
    if (a != l.a)
      return a < l.a;
    return b > l.b;
  }
  long double intersectX(const Line &l) const {
    return (l.b - b) / (a - l.a + esp);
  }
  T eval(T x) const { return a * x + b; }
};

template <typename T> struct ConvexHullTrick {
  vector<Line<T>> lines;
  void add(Line<T> line) {
    while (lines.size() >= 2 &&
           lines[lines.size() - 2].intersectX(lines.size() - 1) >=
               lines[lines.size() - 1].intersectX(line))
      lines.pop_back();
    lines.push_back(line);
  }

  Line<T> get(T x) {
    int l = 0, r = lines.size() - 1;
    int res = r;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (lines[mid].intersectX(lines[mid + 1]) >= x) {
        res = mid;
        r = mid;
      } else
        l = mid + 1;
    }
    return lines[res];
  }
};