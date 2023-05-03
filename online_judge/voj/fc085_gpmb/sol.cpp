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

template <typename T>
class Sum2D{
public:
    Sum2D(int n, int m): n_(n), m_(m) {
        data_.resize(n_+2);
        sum_.resize(n_+2);
        for(int i = 0; i <= n_; ++i) {
            data_[i].resize(m_+2);
            sum_[i].resize(m_+2);
        }
    }

    void Reset() {
        for(int i = 0; i <= n_; ++i) {
            fill(data_[i].begin(), data_[i].end(), 0);
            fill(sum_[i].begin(), sum_[i].end(), 0);
        }
    }

    void Update(int i, int j, int u, int v, T val) {
        data_[i][j] += val;
        data_[u+1][j] -= val;
        data_[i][v+1] -= val;
        data_[u+1][v+1] += val;
    }

    void Finalize() {
        for(int i = 1; i <= n_; ++i)
            for(int j = 1; j <= m_; ++j) {
                data_[i][j] += data_[i-1][j] + data_[i][j-1] - data_[i-1][j-1];
                sum_[i][j] = sum_[i-1][j] + sum_[i][j-1] - sum_[i-1][j-1] + data_[i][j];
            }
    }

    int Get(int i, int j, int u, int v) {
        if(i > u || j > v)
            return -1;
        return sum_[u][v] - sum_[u][j-1] - sum_[i-1][v] + sum_[i-1][j-1];
    }
private:
    vector<vector<T>> data_;
    vector<vector<T>> sum_;
    int n_, m_;
};

using ResidentArea = tuple<int, int, int, int>;

int main() {
    io
    int L, A, M;
    cin >> L >> A >> M;
    vector<ResidentArea> areas;
    vector<int> s_x, s_y;

    auto store_x = [&](int x) {
        s_x.push_back(x);
        if(x - 1 >= 1) s_x.push_back(x - 1);
        if(x + 1 <= L) s_x.push_back(x + 1);
        if(x - A >= 1) s_x.push_back(x - A);
        if(x + A <= L) s_x.push_back(x + A);
    };

    auto store_y = [&](int y) {
        s_y.push_back(y);
        if(y - 1 >= 1) s_y.push_back(y - 1);
        if(y + 1 <= L) s_y.push_back(y + 1);
        if(y - A >= 1) s_y.push_back(y - A);
        if(y + A <= L) s_y.push_back(y + A);
    };

    s_x.push_back(1); s_x.push_back(A);
    s_x.push_back(L); s_x.push_back(L-A+1);
    s_y.push_back(1); s_y.push_back(A);
    s_y.push_back(L); s_y.push_back(L-A+1);

    for(int i = 1, h, l, x, y; i <= M; ++i) {
        cin >> h >> l >> x >> y;
        areas.push_back({h, l, x, y});
        store_x(x);
        store_x(x+l-1);
        store_y(y);
        store_y(y+l-1);
    }
    
    // indices compression
    s_x.push_back(0); s_y.push_back(0); // to base-1
    sort(s_x.begin(), s_x.end());
    sort(s_y.begin(), s_y.end());
    s_x.resize(unique(s_x.begin(), s_x.end()) - s_x.begin());
    s_y.resize(unique(s_y.begin(), s_y.end()) - s_y.begin());
    vector<int> x_id(L+1), y_id(L+1);
    for(unsigned i = 1; i < s_x.size(); ++i) x_id[s_x[i]] = i;
    for(unsigned i = 1; i < s_y.size(); ++i) y_id[s_y[i]] = i;

    sort(areas.begin(), areas.end(), [](const ResidentArea &A, const ResidentArea &B) {
            return get<0>(A) > get<0>(B);
        });
    
    Sum2D<int> sum_2d(s_x.size(), s_y.size()); 
    
    auto sanitizer_check = [&](int i, int j, int u, int v) -> bool{
        if(i > u || j > v || i <= 0 || j <= 0 || u > L || v > L)
            return false;
        if(x_id[i] == 0 || x_id[u] == 0 || y_id[j] == 0 || y_id[v] == 0)
            return false;
        return sum_2d.Get(x_id[i], y_id[j], x_id[u], y_id[v]) == 0;
    };

    auto check = [&](int threshold)-> bool {
        sum_2d.Reset();
        vector<int> px, py;
        px.push_back(1);
        px.push_back(L);
        py.push_back(1);
        py.push_back(L);
        for(auto [h, l, x, y] : areas) {
            if(h <= threshold) break;
            if(x-1 >= 1) px.push_back(x-1);
            if(x+l <= L) px.push_back(x+l);
            if(y-1 >= 1) py.push_back(y-1);
            if(y+l <= L) py.push_back(y+l);

            sum_2d.Update(x_id[x], y_id[y], x_id[x+l-1], y_id[y+l-1], 1);
        }
        sum_2d.Finalize();
        for(int x: px)
            for(int y: py) {
                if(sanitizer_check(x-A+1, y-A+1, x, y)) return true;
                if(sanitizer_check(x, y-A+1, x+A-1, y)) return true;
                if(sanitizer_check(x-A+1, y, x, y+A-1)) return true;
                if(sanitizer_check(x, y, x+A-1, y+A-1)) return true;
            }
        return false;
    };

    int l = 1, r = 255;
    while(l <= r) {
        int mid = (l+r) >> 1;
        if(check(mid))
            r = mid - 1;
        else l = mid + 1;
    }
    cout << r + 1 << '\n';
}
