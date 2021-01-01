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

typedef pair <int, int> ii;
typedef vector <ii> vii;
#define fi first
#define se second
#define mp make_pair
#define PROB "C"
#define MAXN 400005

int get(int a, int b, int c, int x, int y){
    return a*x + b*y - c;
}

int main(){
    _io
    freopen(PROB".inp", "r", stdin);
    freopen(PROB".out", "w", stdout);
    int t; cin >> t;
    while(t--){
        int a, b, c1, c2;
        cin >> a >> b >> c1 >> c2;
        int k;
        cin >> k;
        int Max = 0, Min = INT_MAX;
        FOR(i, 1, k){
            int x, y;
            cin >> x >> y;
            int f = get(a, b, c1, x, y);
            Max = max(Max, f);
            Min = min(Min, f);
            f = get(a, b, c2, x, y);
            Max = max(Max, f);
            Min = min(Min, f);
        }
        if(Min < 0 && Max > 0)
            cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}
