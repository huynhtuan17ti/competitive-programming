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

#define EPS 1e-6
const double PI = acos(-1.0);

double DEG_TO_RAD(double d) { return d * PI / 180.0; }
double RAD_TO_DEG(double r) { return r * 180.0 / PI; }

inline int cmp(double a, double b) {
    return (a < b - EPS) ? -1 : ((a > b + EPS) ? 1 : 0);
}

struct Point{
    int x, y;
    Point(){
        x = y = 0;
    }
    Point(int x, int y): x(x), y(y) {}

    Point operator + (const Point& a) const { return Point(x+a.x, y+a.y); }
    Point operator - (const Point& a) const { return Point(x-a.x, y-a.y); }
    Point operator * (int k) const { return Point(x*k, y*k); }
    Point operator / (int k) const { return Point(x/k, y/k); }

    int dot(const Point& a) const { return x*a.x + y*a.y; } // dot product
    int cross(const Point& a) const { return x*a.y - y*a.x; } // cross product

    int cmp(const Point& q) const {
        if (x != q.x) return ::cmp(x, q.x);
        return ::cmp(y, q.y);
    }

    #define Comp(x) bool operator x (Point q) const { return cmp(q) x 0; }
    Comp(>) Comp(<) Comp(==) Comp(>=) Comp(<=) Comp(!=)
    #undef Comp

    double norm() { return x*x + y*y; }
    double len() { return sqrt(norm()); }
};

struct Line{
    int a, b, c;
    Point A, B;

    Line(int a, int b, int c): a(a), b(b), c(c) {}

    Line(Point A, Point B): A(A), B(B) {
        a = B.y - A.y;
        b = A.x - B.x;
        c = -(a * A.x + b * A.y);
        int G = __gcd(__gcd(a, b), c);
        a /= G; b /= G; c /= G;
    }

    // initialize a line with slope k
    Line(Point P, double k) {
        a = -k;
        b = 1;
        c = k * P.x - P.y;
    }

    int f(Point A){
        return a * A.x + b * A.y + c;
    }
};

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n; cin >> n;
    vector <Point> points;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        Point p(x, y);
        points.push_back(p);
    }
    vector <Line> lines;
    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++){
            Line l(points[i], points[j]);
            lines.push_back(l);
        }
    sort(lines.begin(), lines.end(), [](const Line &A, const Line &B){
        return (A.a == B.a)? ((A.b == B.b)? A.c < B.c: A.b < B.b): A.a < B.a;
    });

    map <ii, int> M;
    int cnt = 1;
    for(int i = 0; i < lines.size(); i++){
        //cout << lines[i].a << ' ' << lines[i].b << ' ' << lines[i].c << '\n';
        if(i == lines.size()-1 || 
            (lines[i].a != lines[i+1].a || lines[i].b != lines[i+1].b || lines[i].c != lines[i+1].c)){
            int G = __gcd(lines[i].a, lines[i].b);
            M[mp(lines[i].a/G, lines[i].b/G)]++;
        }
    }

    ll res = 0, sum = 0;
    for(auto u: M){
        res += 1LL*u.se*sum;
        sum += u.se;
    }
    cout << res << '\n';
}