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

