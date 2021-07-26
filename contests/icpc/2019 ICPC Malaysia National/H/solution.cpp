/* Tuan Kkura */
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define base 31
#define MOD 1e9+7
#define pb push_back
#define _io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

typedef pair <int, int> ii;
typedef vector <ii> vii;
#define fi first
#define se second
#define mp make_pair
#define PROB "text"
#define MAXN 400005

int ccw(ii a, ii b, ii c){
    ll val = 1LL*a.fi*(b.se - c.se) + 1LL*b.fi*(c.se - a.se) + 1LL*c.fi*(a.se - b.se);
    if(val > 0)
        return 1;
    if(val < 0)
        return -1;
    if(val == 0)
        return 0;
}

vector <ii> ConvexHull(vector <ii> points, int n){
    sort(points.begin(), points.end(), [](const ii &A, const ii &B){
            return (A.fi == B.fi)? (A.se < B.se): (A.fi < B.fi);
         });
    vii Up, Down;
    ii A = points[0], B = points.back();
    Up.pb(A);
    Down.pb(A);
    for(int i = 1; i < points.size(); i++){
        if(i == points.size()-1 || ccw(A, points[i], B) == -1){
            while(Up.size() >= 2 && ccw(Up[Up.size()-2], Up[Up.size()-1], points[i]) >= 0)
                Up.pop_back();
            Up.pb(points[i]);
        }
        if(i == points.size()-1 || ccw(A, points[i], B) == 1){
            while(Down.size() >= 2 && ccw(Down[Down.size()-2], Down[Down.size()-1], points[i]) <= 0)
                Down.pop_back();
            Down.pb(points[i]);
        }
    }
    vii convex;
    for(int i = 0; i < Up.size(); i++)  convex.pb(Up[i]);
    for(int i = Down.size()-2; i > 0; i--)  convex.pb(Down[i]);
    return convex;
}

bool checkInConvex(ii ckPoint, vii convex){
    for(int i = 1; i <= convex.size(); i++)
        if(ccw(convex[i-1], convex[(i%convex.size())], ckPoint) == 1)
            return false;
    return true;
}

int main(){
    _io
    int t; cin >> t;
    for(int iTest = 1; iTest <= t; iTest++){
        int c, p;
        cin >> c >> p;
        vii a(c);
        for(int i = 0; i < c; i++){
            cin >> a[i].fi >> a[i].se;
        }
        cout << "Case " << iTest << '\n';
        vii convex = ConvexHull(a, c);
        cout << convex[0].fi << ' ' << convex[0].se << '\n';
        for(int i = convex.size()-1; i >= 0; i--)
            cout << convex[i].fi << ' ' << convex[i].se << '\n';
        for(int i = 0; i < p; i++){
            ii x;
            cin >> x.fi >> x.se;
            string s = " is safe!";
            if(checkInConvex(x, convex))
                s = " is unsafe!";
            cout << x.fi << ' ' << x.se << s << '\n';
        }
        cout << '\n';
    }
}
