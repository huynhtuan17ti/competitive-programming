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
const ld PI = acos(-1.0);

ld DEG_TO_RAD(ld d) { return d * PI / 180.0; }
ld RAD_TO_DEG(ld r) { return r * 180.0 / PI; }

inline int cmp(ld a, ld b) {
    return (a < b - EPS) ? -1 : ((a > b + EPS) ? 1 : 0);
}

struct Point{
    ld x, y;
    Point(){
        x = y = 0.0;
    }
    Point(ld x, ld y): x(x), y(y) {}

    Point operator + (const Point& a) const { return Point(x+a.x, y+a.y); }
    Point operator - (const Point& a) const { return Point(x-a.x, y-a.y); }
    Point operator * (ld k) const { return Point(x*k, y*k); }
    Point operator / (ld k) const { return Point(x/k, y/k); }

    ld dot(const Point& a) const { return x*a.x + y*a.y; } // dot product
    ld cross(const Point& a) const { return x*a.y - y*a.x; } // cross product

    int cmp(const Point& q) const {
        if (x != q.x) return ::cmp(x, q.x);
        return ::cmp(y, q.y);
    }

    #define Comp(x) bool operator x (Point q) const { return cmp(q) x 0; }
    Comp(>) Comp(<) Comp(==) Comp(>=) Comp(<=) Comp(!=)
    #undef Comp

    ld norm() { return x*x + y*y; }
    ld len() { return sqrt(norm()); }

    // Rotate vector
    Point rotate(ld alpha) {
        ld cosa = cos(alpha), sina = sin(alpha);
        return Point(x * cosa - y * sina, x * sina + y * cosa);
    }
};

istream& operator >> (istream& cin, Point& p) {
    cin >> p.x >> p.y;
    return cin;
}
ostream& operator << (ostream& cout, Point& p) {
    cout << p.x << ' ' << p.y;
    return cout;
}

struct Line{
    ld a, b, c;
    Point A, B;

    Line(ld a, ld b, ld c): a(a), b(b), c(c) {}

    Line(Point A, Point B): A(A), B(B) {
        a = B.y - A.y;
        b = A.x - B.x;
        c = -(a * A.x + b * A.y);
    }

    // initialize a line with slope k
    Line(Point P, ld k) {
        a = -k;
        b = 1;
        c = k * P.x - P.y;
    }

    ld f(Point A){
        return a * A.x + b * A.y + c;
    }
};

bool areParallel(Line l1, Line l2) {
    return cmp(l1.a*l2.b, l1.b*l2.a) == 0;
}

bool areSame(Line l1, Line l2) {
    return areParallel(l1, l2) && cmp(l1.c*l2.a, l2.c*l1.a) == 0
           && cmp(l1.c*l2.b, l1.b*l2.c) == 0;
}

bool areIntersect(Line l1, Line l2, Point &p) {
    if (areParallel(l1, l2))
        return false;
    ld dx = l1.b*l2.c - l2.b*l1.c;
    ld dy = l1.c*l2.a - l2.c*l1.a;
    ld d = l1.a*l2.b - l2.a*l1.b;
    p = Point(dx / d, dy / d);
    return true;
}

// distance from p to line ab
ld distToLine(Point p, Point a, Point b, Point &c) {
    Point ap = p - a, ab = b - a;
    ld k = ap.dot(ab) / ab.norm();
    c = a + (ab * k);
    return (p - c).len();
}

// closest point from p in line l.
void closestPoint(Line l, Point p, Point &ans) {
    if (fabs(l.b) < EPS) {
        ans.x = -(l.c) / l.a; ans.y = p.y;
        return;
    }
    if (fabs(l.a) < EPS) {
        ans.x = p.x; ans.y = -(l.c) / l.b;
        return;
    }
    Line perp(l.b, -l.a, - (l.b*p.x - l.a*p.y));
    areIntersect(l, perp, ans);
}

// reflect point p over line l 
void reflectionPoint(Line l, Point p, Point &ans) {
    Point b;
    closestPoint(l, p, b);
    ans = p + (b - p) * 2;
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    ld a, b, c;
    cin >> a >> b >> c;
    ld x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    Line l(a, b, c);
    Point A(x1, y1);
    Point B(x2, y2);

    ld min_dist = abs(x1 - x2) + abs(y1-y2);
    vector <Point> tmp;
    tmp.push_back(Point(x1, y2));
    tmp.push_back(Point(x2, y1));

    for(Point u: tmp){
        Line l1(A, u);
        Line l2(B, u);

        Point _a, _b;
        if(areIntersect(l, l1, _a) && areIntersect(l, l2, _b)){
            min_dist = min(min_dist, (A - _a).len() + (B - _b).len() + (_a - _b).len());
        }
    }

    for(int it = 1; it <= 2; it++){
        Line l1(A, tmp[0]);
        Line l2(B, tmp[1]);

        Point _a, _b;
        if(areIntersect(l, l1, _a) && areIntersect(l, l2, _b)){
            min_dist = min(min_dist, (A - _a).len() + (B - _b).len() + (_a - _b).len());
        }

        swap(tmp[0], tmp[1]);
    }

    cout << fixed << setprecision(10) << min_dist << '\n';
}