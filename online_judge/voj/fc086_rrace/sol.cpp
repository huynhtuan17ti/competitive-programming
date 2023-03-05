#include <bits/stdc++.h>  
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
constexpr int64_t INF = 1e18;

static vector<int> actual_x;

template <typename data_t>
struct Line {
    data_t a, b;

    Line() : a(0), b(INF) {}
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

    LiChaoTree(T xmin, T xmax) : xmin_(xmin), xmax_(xmax) {
        root_ = new NodeType();
    }

    void InsertSegment(T l, T r, LineType line) {
        InsertSegment(root_, xmin_, xmax_, l, r, line);
    }

    T Query(T x) {
        return Query(root_, xmin_, xmax_, x);
    }

    ~LiChaoTree() {
        delete root_;
    }
    
private:
    void InsertSegment(NodeType* &node, T L, T R, T l, T r, LineType x) {
        if(R < l || r < L || L > R || l > r) return;
        if(node == nullptr) node = new NodeType();
        if(l <= L && R <= r) return InsertLine(node, L, R, x);
        T mid = (L + R) >> 1;
        InsertSegment(node->left, L, mid, l, r, x);
        InsertSegment(node->right, mid+1, R, l, r, x);
    }

    void InsertLine(NodeType* &node, T L, T R, LineType x) {
        if(node == nullptr) node = new NodeType();
        if(node->line.Eval(L) > x.Eval(L)) swap(node->line, x);
        if(node->line.Eval(R) <= x.Eval(R)) return;
        if(L == R) return;
        T mid = (L + R) >> 1;
        if(node->line.Eval(mid) < x.Eval(mid)) {
            InsertLine(node->right, mid + 1, R, x);
        } else {
            swap(node->line, x);
            InsertLine(node->left, L, mid, x);
        }
    }

    T Query(NodeType* &node, T L, T R, T x) {
        if(node == nullptr) return INF;
        if(L == R) return node->line.Eval(x);
        T res = node->line.Eval(x);
        T mid = (L + R) >> 1;
        if(x <= mid)
            res = min(res, Query(node->left, L, mid, x));
        else res = min(res, Query(node->right, mid+1, R, x));
        return res;
    }

    NodeType* root_;
    T xmin_, xmax_;
};

int main() {
    io
    int n, k;
    cin >> n >> k;
    using Runner = tuple<int, int, int>;
    vector<Runner> runners;
    vector<int> store;
    for(int i = 1, a, b, v; i <= n; ++i) {
        cin >> a >> b >> v;
        runners.emplace_back(a, b, v);
        store.push_back(a);
        store.push_back(b);
    }
    // compression
    sort(store.begin(), store.end());
    store.resize(unique(store.begin(), store.end()) - store.begin());

    auto get_compressed_id = [&store](int val)->int  {
        return lower_bound(store.begin(), store.end(), val) - store.begin();
    };

    for(auto &[a, b, v]: runners) {
        a = get_compressed_id(a);
        b = get_compressed_id(b);
    }
    
    actual_x = std::move(store);
    const int N = (int)actual_x.size();

    sort(runners.begin(), runners.end(), [](const Runner& A, const Runner &B) {
        return get<0>(A) < get<0>(B);
    });    

    // main section
    LiChaoTree<ll> lc_tree(0, N-1);
    lc_tree.InsertSegment(0, 0, {0, 0});
    
    for(auto &[a, b, v]: runners) {
        ll min_tm = lc_tree.Query(a); // the minimum time at index a 
        // Line = (v, -actual_x[a] * v + min_tm)
        // segment range = [a, b]
        lc_tree.InsertSegment(a, b, {v, 1LL * -actual_x[a] * v + min_tm});
    }
    cout << lc_tree.Query(N-1);
}
