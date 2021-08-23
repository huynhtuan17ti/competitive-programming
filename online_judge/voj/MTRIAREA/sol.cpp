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

struct point{
    int x, y;
};

int cross(point A, point B, point C){
    int val = A.x*(B.y - C.y) + B.x*(C.y - A.y) + C.x*(A.y - B.y);
    if(val == 0)
        return 0; // coline
    if(val < 0)
        return 1; // clockwise
    return -1; //counter clockwise
}

int doubleTriangleArea(point A, point B, point C){
    int S = A.x*(B.y - C.y) + B.x*(C.y - A.y) + C.x*(A.y - B.y);
    return abs(S);
}

vector <point> findConvexHull(vector <point> points){
    vector <point> convex;
    sort(points.begin(), points.end(), [](const point &A, const point &B){
        return (A.x == B.x)? (A.y < B.y): (A.x < B.x);
    });
    vector <point> Up, Down;
    point A = points[0], B = points.back();
    Up.push_back(A);
    Down.push_back(A);

    for(int i = 0; i < points.size(); i++){
        if(i == points.size()-1 || cross(A, points[i], B) > 0){
            while(Up.size() > 2 && cross(Up[Up.size()-2], Up[Up.size()-1], points[i]) <= 0)
                Up.pop_back();
            Up.push_back(points[i]);
        }
        if(i == points.size()-1 || cross(A, points[i], B) < 0){
            while(Down.size() > 2 && cross(Down[Down.size()-2], Down[Down.size()-1], points[i]) >= 0)
                Down.pop_back();
            Down.push_back(points[i]);
        }
    }
    for(int i = 0; i < Up.size(); i++)  convex.push_back(Up[i]);
    for(int i = Down.size()-2; i > 0; i--)  convex.push_back(Down[i]);
    return convex;
}

double findLargestTriangle(vector <point> convex){
    int res = 0;
    int n = convex.size();
    for(int i = 0; i < n; i++){
        int k = (i+1)%n;
        for(int j = (i+2)%n; j != i; j=(j+1)%n){
            int nextk = (k+1)%n;
            while(nextk != j && doubleTriangleArea(convex[i], convex[k], convex[j]) <= doubleTriangleArea(convex[i], convex[nextk], convex[j])){
                k = nextk;
                nextk = (k+1)%n;
            }
            res = max(res, doubleTriangleArea(convex[i], convex[k], convex[j]));
        }
    }
    return (double)res/2.0;
}

void solve(int n){
    vector <point> points(n);
    for(int i = 0; i < n; i++){
        cin >> points[i].x >> points[i].y;
    }
    points = findConvexHull(points);
    double largestTriangle = findLargestTriangle(points);
    cout << fixed << setprecision(2) << largestTriangle << '\n';
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n;
    while(cin >> n){
        if(n == -1)
            break;
        solve(n);
    }
}