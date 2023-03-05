#include <algorithm>
#include <bits/stdc++.h>  
#include <iomanip>
using namespace std;
 
constexpr int MOD = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define mp make_pair
#define fi first
#define se second
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};
constexpr int MAXN = 3e5 + 5;
constexpr ll INF = 1e15;

static vector<int> actual_x;

template <typename data_t>
struct Line {
    data_t a, b;

    Line() : a(0), b(-INF) {}
    Line(data_t a, data_t b) : a(a), b(b) {}

    data_t Eval(data_t x) {
        return a * actual_x[x] + b;
    }
};

template <typename data_t>
struct Node {
    Line<data_t> line = Line<data_t>();
    Node* left = nullptr;
    Node* right = nullptr;

    ~Node() {
        delete left;
        delete right;
    }
}; 

template <typename T>
class LiChaoTree {
public:
    using LineType = Line<T>;
    using NodeType = Node<T>;

    LiChaoTree(int xmin, int xmax) : xmin_(xmin), xmax_(xmax) {
        root_ = new NodeType();
    }

    void InsertSegment(int l, int r, LineType line) {
        InsertSegment(root_, xmin_, xmax_, l, r, line);
    }

    T Query(int x) {
        return Query(root_, xmin_, xmax_, x);
    }

    ~LiChaoTree() {
        delete root_;
    }
    
private:
    void InsertSegment(NodeType* &node, int L, int R, T l, T r, LineType x) {
        if(R < l || r < L || L > R || l > r) return;
        if(node == nullptr) node = new NodeType();
        if(l <= L && R <= r) return InsertLine(node, L, R, x);
        int mid = (L + R) >> 1;
        InsertSegment(node->left, L, mid, l, r, x);
        InsertSegment(node->right, mid+1, R, l, r, x);
    }

    void InsertLine(NodeType* &node, int L, int R, LineType x) {
        if(node == nullptr) node = new NodeType();
        if(node->line.Eval(L) < x.Eval(L)) swap(node->line, x);
        if(node->line.Eval(R) >= x.Eval(R)) return;
        if(L == R) return;
        int mid = (L + R) >> 1;
        if(node->line.Eval(mid) > x.Eval(mid)) {
            InsertLine(node->right, mid + 1, R, x);
        } else {
            swap(node->line, x);
            InsertLine(node->left, L, mid, x);
        }
    }

    T Query(NodeType* &node, int L, int R, int x) {
        if(node == nullptr) return -INF;
        if(L == R) return node->line.Eval(x);
        T res = node->line.Eval(x);
        int mid = (L + R) >> 1;
        if(x <= mid)
            res = max(res, Query(node->left, L, mid, x));
        else res = max(res, Query(node->right, mid+1, R, x));
        return res;
    }

    NodeType* root_;
    T xmin_, xmax_;
};

int main() {
    io
    // input section
    int m; cin >> m;
    vector<int> t(m);
    for(int i = 0; i < m; ++i) cin >> t[i];
    
    vector<int> store;
    int n; cin >> n;
    vector<int> s(n);
    for(int i = 0; i < n; ++i) {
        cin >> s[i];
        store.push_back(s[i]);
    }
    sort(store.begin(), store.end());
    store.resize(unique(store.begin(), store.end()) - store.begin());
    actual_x = std::move(store);
    const int N = (int)actual_x.size();

    // main section 
    LiChaoTree<long double> lc_tree(0, N-1);
    for(int i = 0; i < m; ++i) {
        auto id = upper_bound(actual_x.begin(), actual_x.end(), t[i]) - actual_x.begin() - 1;
        if(id < 0) continue;
        auto h = (long double)1/(i+1);
        // cerr << t[i] <<  ' ' << id << ' ' << -h << ' ' << h * t[i] << '\n';
        lc_tree.InsertSegment(0, id, {-h, h * t[i]}); 
    } 
    for(int i = 0; i < n; ++i) {
        auto id = lower_bound(actual_x.begin(), actual_x.end(), s[i]) - actual_x.begin();
        long double _v = lc_tree.Query(id);
        cout << fixed << setprecision(6) << (long double)1/_v << '\n';
    }
}
