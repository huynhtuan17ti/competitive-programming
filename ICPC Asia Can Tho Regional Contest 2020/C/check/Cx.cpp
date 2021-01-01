/* Tuan Kkura */
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define base 31
#define MOD 1e9+7
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORs(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, a, b) for(int i = a; i < b; i++)
#define __FOR(i, a, b, k) for(int i = a; i <= b; i+= k)
#define __REP(i, a, b, k) for(int i = a; i < b; i+= k)
#define pb push_back
#define _io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

typedef pair <long double, long double> ii;
typedef vector <ii> vii;
#define fi first
#define se second
#define mp make_pair
#define PROB "text"
#define MAXN 400005

struct line{
    int a, b, c;
};

struct point{
    long double x, y;
};

int getType(point a, point b, point c){
    long double val = a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y);
    if(val == 0)
        return 0;
    if(val > 0)
        return 1;
    if(val < 0)
        return -1;
}

int main(){
    _io
    freopen("C.inp", "r", stdin);
    freopen("C.ans", "w", stdout);
    int t; cin >> t;
    while(t--){
        int a, b, c1, c2;
        cin >> a >> b >> c1 >> c2;
        line l1 = {a, b, c1}, l2 = {a, b, c2};
        vector <point> Q;
        int k; cin >> k;
        FOR(i, 1, k){
            int x, y;
            cin >> x >> y;
            Q.pb({x, y});
        }
        point left_l1, right_l1, left_l2, right_l2;
        if(b == 0){
            left_l1 = {(long double)c1/a, -1e5};
            right_l1 = {(long double)c1/a, 1e5};

            left_l2 = {(long double)c2/a, -1e5};
            right_l2 = {(long double)c2/a, 1e5};
        }else{
            left_l1 = {-1e5, (long double)(c1-a*-1e5)/b};
            right_l1 = {1e5, (long double)(c1-a*1e5)/b};

            left_l2 = {-1e5, (long double)(c2-a*-1e5)/b};
            right_l2 = {1e5, (long double)(c2-a*1e5)/b};
        }
        //cout << left_l1.x << ' ' << left_l1.y << '\n';
        //cout << right_l1.x << ' ' << right_l1.y << '\n';
        //cout << left_l2.x << ' ' << left_l2 .y << '\n';
        //cout << right_l2.x << ' ' << right_l2.y << '\n';
        bool ok = false;
        REP(i, 0, k){
            int typel1_0 = getType(left_l1, right_l1, Q[i]);
            int typel1_1 = getType(left_l1, right_l1, Q[(i+1)%k]);
            int typel2_0 = getType(left_l2, right_l2, Q[i]);
            int typel2_1 = getType(left_l2, right_l2, Q[(i+1)%k]);
            //cout << typel1_0 << ' ' << typel1_1 << ' ' << typel2_0 << ' ' << typel2_1 << '\n';
            if((typel1_0 <= 0 && typel1_1 <= 0 && typel2_0 <= 0 && typel2_1 <= 0) ||
               (typel1_0 >= 0 && typel1_1 >= 0 && typel2_0 >= 0 && typel2_1 >= 0))
                ok = false;
            else {
                ok = true;
                break;
            }
        }
        if(ok)
            cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}
