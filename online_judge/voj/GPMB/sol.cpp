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
    int x, y, val;
};

int main(){
    io
    int n; cin >> n;
    vector <point> a;
    for(int i = 0; i < n; i++){
        int x, y, s;
        cin >> x >> y >> s;
        a.push_back({x, y, s});
    }
    ll res = 0;
    for(int i = 0; i < n; i++){
        map <ld, ll> S;
        ll zero_S = 0;
        for(int j = i+1; j < n; j++)
            if(a[j].y != a[i].y)
                S[(ld)(a[j].x-a[i].x)/(a[j].y-a[i].y)] += (a[j].val*a[j].val + 5);
            else zero_S += (a[j].val*a[j].val + 5);
        res = max(res, zero_S + (a[i].val*a[i].val + 5));
        for(auto it: S)
            res = max(res, it.se + (a[i].val*a[i].val + 5));
    }
    cout << res;
}