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
#define PROB "F"
#define MAXN 400005

ii a[MAXN];

int main(){
    _io
    freopen(PROB".inp", "r", stdin);
    freopen(PROB".out", "w", stdout);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        map <ii, int> M;
        FOR(i, 1, n){
            int x, y, u, v;
            cin >> x >> y >> u >> v;
            ii p = {x-u, y-v};
            int g = __gcd(abs(x-u), abs(y-v));
            p.fi /= g;
            p.se /= g;
            //cout << p.fi << ' ' << p.se << '\n';
            a[i] = p;
        }
        ll res = 0;
        FOR(i, 1, n){
            ii val = {-a[i].fi, -a[i].se};
            res += M[val];
            M[a[i]]++;
        }
        cout << res << '\n';
    }
}
