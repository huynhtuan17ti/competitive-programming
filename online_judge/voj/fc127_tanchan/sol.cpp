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
const long double esp = 1e-7;

template <typename T>
struct Line {
    T a, b;
    int id;
    Line(T a = 0, T b = 0, T id = 0) : a(a), b(b), id(id) {}

    bool operator < (const Line& l) const {
        if (a != l.a) return a < l.a;
        return b > l.b;
    }
    long double intersectX(const Line& l) const {
        return (l.b - b) / (a - l.a + esp);
    }
    T eval(T x) const {
        return a * x + b;
    }
};

template <typename T>
struct ConvexHullTrick {
    vector <Line<T>> lines;
    void add(Line<T> line){
        while(lines.size() >= 2 && 
            lines[lines.size()-2].intersectX(lines.size()-1) >= lines[lines.size()-1].intersectX(line))
            lines.pop_back();
        lines.push_back(line);
    }

    Line<T> get(T x){
        int l = 0, r = lines.size()-1;
        int res = r;
        while(l < r){
            int mid = (l+r) >> 1;
            if(lines[mid].intersectX(lines[mid+1]) >= x){
                res = mid;
                r = mid;
            }else l = mid + 1;
        }
        return lines[res];
    }
};

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n; cin >> n;
    vector <ll> S(n+1), s(n+1);
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        S[i] = S[i-1] + 1LL * i * x;
        s[i] = s[i-1] + x;
    }

    ConvexHullTrick<ll> optimizer;
    ll best = LLONG_MIN;
    ii ans_pair;
    for(int i = 0; i <= n; i++){
        if(i > 0){
            Line<ll> line = optimizer.get(-s[i]);
            ll curResult = line.eval(-s[i]) + S[i];
            if(best < curResult){
                best = curResult;
                ans_pair = {line.id+1, i};
            }
        }
        optimizer.add({i, - S[i] + 1LL * i * s[i], i});
    }

    cout << best << '\n';
    cout << ans_pair.fi << ' ' << ans_pair.se << '\n';
}