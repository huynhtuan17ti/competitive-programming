#include <bits/stdc++.h>  
 
using namespace std;
 
const int MOD = 998244353;
typedef unsigned long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define mp make_pair
#define fi first
#define se second
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int MAXN = 2e5+5;
 
int minL[MAXN], maxL[MAXN];
int minR[MAXN], maxR[MAXN];
 
vii points;
vector <int> x_points;
 
bool check(int val){
    int n = points.size()-1;
    for(int i = 0; i < points.size(); i++){
        int x = points[i].fi;
        int y = points[i].se;
        int L = upper_bound(x_points.begin(), x_points.end(), x-val) - x_points.begin() - 1;
        int R = lower_bound(x_points.begin(), x_points.end(), x+val) - x_points.begin();
        
        L = max(L, 0);
        R = min(R, n);
 
        int disLeft = -1;
        int disRight = -1;
 
        if(x - x_points[L] >= val){
            disLeft = max(y - minL[L], maxL[L] - y);
        }
 
        if(x_points[R] - x >= val){
            disRight =  max(y - minR[R], maxR[R] - y);
        }
 
        int dis_y = max(disLeft, disRight);
 
        if(dis_y >= val){
            return true;
        }
    }
    return false;
}
 
int main(){
    io
    int N; cin >> N;
    
    for(int i = 1; i <= N; i++){
        int x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }
 
    sort(points.begin(), points.end());
    for(int i = 0; i < points.size(); i++)
        x_points.push_back(points[i].fi);
 
    minL[0] = points[0].se;
    maxL[0] = points[0].se;
    for(int i = 1; i < points.size(); i++){
        minL[i] = min(minL[i-1], points[i].se);
        maxL[i] = max(maxL[i-1], points[i].se);
    }
 
    minR[points.size()-1] = points[points.size()-1].se;
    maxR[points.size()-1] = points[points.size()-1].se;
 
    for(int i = points.size()-2; i >= 0; i--){
        minR[i] = min(minR[i+1], points[i].se);
        maxR[i] = max(maxR[i+1], points[i].se);
    }
 
    // cout << check(10) << '\n';
    // return 0;
 
    int l = 0, r = 1e9;
    while(l <= r){
        int mid = (l+r) >> 1;
        if(check(mid))
            l = mid + 1;
        else r = mid - 1;
    }
    cout << l-1 << '\n';
}