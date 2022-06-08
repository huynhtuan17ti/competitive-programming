#include <bits/stdc++.h>  
using namespace std;

const int MOD = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define mp make_pair
#define fi first
#define se second
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
const int MAXN = 5e5 + 5;
const int MAX = 1e6 + 1;

struct Point{
    int x, y;
    int id;
};

template <typename T>
class FenwickTreeLower
{
private:
    vector<T> fenw;
    int n;

public:
    FenwickTreeLower(int _n)
    {
        this->n = _n;
        fenw.resize(n + 1, -2*MAX);
    }

    void reset(){
        fill(fenw.begin(), fenw.end(), -2*MAX);
    }

    void update(int id, T val)
    {
        while (id <= n)
        {
            fenw[id] = max(fenw[id], val);
            id += id & (-id);
        }
    }

    T get(int id)
    {
        T ans = -2*MAX;
        while (id >= 1)
        {
            ans = max(ans, fenw[id]);
            id -= id & (-id);
        }
        return ans;
    }
};

template <typename T>
class FenwickTreeUpper
{
private:
    vector<T> fenw;
    int n;

public:
    FenwickTreeUpper(int _n)
    {
        this->n = _n;
        fenw.resize(n + 1, -2 * MAX);
    }

    void reset()
    {
        fill(fenw.begin(), fenw.end(), -2*MAX);
    }

    void update(int id, T val)
    {
        while (id >= 1)
        {
            fenw[id] = max(fenw[id], val);
            id -= id & (-id);
        }
    }

    T get(int id)
    {
        T ans = -2*MAX;
        while (id <= n)
        {
            ans = max(ans, fenw[id]);
            id += id & (-id);
        }
        return ans;
    }
};

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n; cin >> n;
    vector <Point> points(n+1);
    for(int i = 1, x; i <= n; i++){
        cin >> x;
        points[i].x = x;
        points[i].id = i;
    }
    vector <int> listY;
    listY.push_back(INT_MIN);
    for(int i = 1, y; i <= n; i++){
        cin >> y;
        listY.push_back(y);
        points[i].y = y;
        points[i].id = i;
    }

    sort(points.begin() + 1, points.end(), [](const Point &A, const Point &B){
        return A.x < B.x;
    });


    sort(listY.begin(), listY.end());
    listY.resize(unique(listY.begin(), listY.end()) - listY.begin());

    auto getId = [&](int val){
        return lower_bound(listY.begin(), listY.end(), val) - listY.begin();
    };

    FenwickTreeLower <int> fenwLower(listY.size());
    FenwickTreeUpper <int> fenwUpper(listY.size());

    vector <int> res(n+1);

    for(int i = 1; i <= n; i++){
        int id = getId(points[i].y);
        res[points[i].id] = max(res[points[i].id], points[i].x + points[i].y + fenwLower.get(id));
        res[points[i].id] = max(res[points[i].id], points[i].x - points[i].y + fenwUpper.get(id));
        fenwLower.update(id, -points[i].x - points[i].y);
        fenwUpper.update(id, -points[i].x + points[i].y);
    }

    fenwLower.reset();
    fenwUpper.reset();

    for(int i = n; i >= 1; i--){
        int id = getId(points[i].y);
        //cout << id << ' ' << fenwLower.get(id) << '\n';
        res[points[i].id] = max(res[points[i].id], -points[i].x + points[i].y + fenwLower.get(id));
        res[points[i].id] = max(res[points[i].id], -points[i].x - points[i].y + fenwUpper.get(id));
        fenwLower.update(id, points[i].x - points[i].y);
        fenwUpper.update(id, points[i].x + points[i].y);
    }

    for(int i = 1; i <= n; i++)
        cout << res[i] << " \n"[i == n];
}