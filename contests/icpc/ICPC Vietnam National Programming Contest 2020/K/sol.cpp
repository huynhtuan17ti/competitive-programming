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
    ll val = 1LL*A.x*(B.y - C.y) + 1LL*B.x*(C.y - A.y) + 1LL*C.x*(A.y - B.y);
    if(val == 0)
        return 0; // coline
    if(val < 0)
        return 1; // clockwise
    return -1; //counter clockwise
}

// check if D inside (A, B, C)
bool is_inside(point A, point B, point C, point D){
    int q1 = cross(A, B, D);
    int q2 = cross(B, C, D);
    int q3 = cross(C, A, D);

    if(q1 == 0 || q2 == 0 || q3 == 0 || cross(A, B, C) == 0)
        return true;
    int Max = max(q1, max(q2, q3)), Min = min(q1, min(q2, q3));

    if (Max == Min)
        return true;
    return false;
}

void solve(int n){
    vector <point> points;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }
    int res = 0;
    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++)
            for(int k = j+1; k < n; k++){
                for(int c = k+1; c < n; c++)
                    if(!is_inside(points[i], points[j], points[k], points[c]) &&
                       !is_inside(points[i], points[j], points[c], points[k]) &&
                       !is_inside(points[i], points[c], points[k], points[j]) &&
                       !is_inside(points[c], points[j], points[k], points[i]))
                        res++;
            }
    cout << res << '\n';
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n;
    while(cin >> n){
        if(n == 0)
            break;
        solve(n);
    }
}