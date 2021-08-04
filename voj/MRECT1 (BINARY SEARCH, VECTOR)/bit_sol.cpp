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
const int MAXN = 3e5+5;

// utils
vector <int> compress(vector <int> S){
    S.push_back(INT_MIN); // to base 1
    S.push_back(INT_MAX);
    sort(S.begin(), S.end());
    S.resize(unique(S.begin(), S.end()) - S.begin());
    return S;
}

int norm(vector <int> S, int val){
    return lower_bound(S.begin(), S.end(), val) - S.begin();
}

vector <int> fake_bit[2][MAXN];
vector <int> bit[2][MAXN];

void compress_bit(int len_x, int len_y){
    for(int i = 0; i < len_x; i++){
        fake_bit[1][i] = compress(fake_bit[1][i]);
        bit[1][i].resize((int)fake_bit[1][i].size(), 0);
    }
    
    for(int i = 0; i < len_y; i++){
        fake_bit[0][i] = compress(fake_bit[0][i]);
        bit[0][i].resize((int)fake_bit[0][i].size(), 0);
    }
}

class FenwickTree{
    public:
        void update(int type, int pos, int id, int limit){
            for(int i = id; i < limit; i += i&(-i))
                bit[type][pos][i] += 1;
        }
        int get(int type, int pos, int id){
            int ans = 0;
            for(int i = id; i >= 1; i -= i&(-i))
                ans += bit[type][pos][i];
            return ans;
        }
        int get_range(int type, int pos, int id1, int id2){
            if(id1 > id2)
                return 0;
            return get(type, pos, id2) - get(type, pos, id1);
        }
        
};

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n; cin >> n;
    vector <int> Sx, Sy;
    vii points;
    map <ii, int> M;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        Sx.push_back(x);
        Sx.push_back(x-1);
        Sy.push_back(y);
        Sy.push_back(y-1);
        points.push_back({x, y});
       
    }
    
    Sx = compress(Sx);
    Sy = compress(Sy);

    for(int i = 0; i < points.size(); i++){
        points[i].fi = norm(Sx, points[i].fi);
        points[i].se = norm(Sy, points[i].se);
        //cout << points[i].fi << ' ' << points[i].se << '\n';
        M[points[i]] += 1;

        fake_bit[0][points[i].se].push_back(points[i].fi);
        fake_bit[0][points[i].se].push_back(points[i].fi-1);
        fake_bit[1][points[i].fi].push_back(points[i].se);
        fake_bit[1][points[i].fi].push_back(points[i].se-1);
    }

    compress_bit((int)Sx.size(), (int)Sy.size());

    FenwickTree fenwickTree;

    for(int i = 0; i < points.size(); i++){
        int norm_x = norm(fake_bit[0][points[i].se], points[i].fi);
        int norm_y = norm(fake_bit[1][points[i].fi], points[i].se);
        fenwickTree.update(0, points[i].se, norm_x, (int)fake_bit[0][points[i].se].size()); // update x
        fenwickTree.update(1, points[i].fi, norm_y, (int)fake_bit[1][points[i].fi].size()); // update y
    }

    int P; cin >> P;
    while(P--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 = norm(Sx, x1);
        y1 = norm(Sy, y1);
        x2 = norm(Sx, x2);
        y2 = norm(Sy, y2);
        //cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
        int horiz_len = fenwickTree.get_range(0, y1, norm(fake_bit[0][y1], x1-1), norm(fake_bit[0][y1], x2)) + 
                            fenwickTree.get_range(0, y2, norm(fake_bit[0][y2], x1-1), norm(fake_bit[0][y2], x2));

        int vert_len = fenwickTree.get_range(1, x1, norm(fake_bit[1][x1], y1-1), norm(fake_bit[1][x1], y2)) + 
                            fenwickTree.get_range(1, x2, norm(fake_bit[1][x2], y1-1), norm(fake_bit[1][x2], y2));

        int ans = horiz_len + vert_len - (M[mp(x1, y1)] + M[mp(x1, y2)] + M[mp(x2, y1)] + M[mp(x2, y2)]);

        cout << ans << '\n';
    }
}