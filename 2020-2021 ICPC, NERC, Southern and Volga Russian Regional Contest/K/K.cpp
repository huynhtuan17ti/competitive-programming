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
#define PROB "K"
#define MAXN 400005

ii get(char c){
    if(c == 'L')
        return {-1, 0};
    if(c == 'R')
        return {1, 0};
    if(c == 'U')
        return {0, 1};
    if(c == 'D')
        return {0, -1};
}

int num[300];

int main(){
    _io
    freopen(PROB".inp", "r", stdin);
    freopen(PROB".out", "w", stdout);
    int t; cin >> t;
    while(t--){
        string s;
        cin >> s;
        ii start = {0, 0};
        vii a;
        for(char c: s){
            ii Move = get(c);
            start.fi += Move.fi;
            start.se += Move.se;
            a.pb(start);
        }
        bool ok = false;
        REP(i, 0, a.size()){
            ii x = {0, 0};
            for(char c: s){
                ii Move = get(c);
                if(x.fi + Move.fi == a[i].fi &&
                   x.se + Move.se == a[i].se)
                    continue;
                x.fi += Move.fi;
                x.se += Move.se;
            }
            if(x.fi == 0 && x.se == 0){
                ok = true;
                cout << a[i].fi << ' ' << a[i].se << '\n';
                break;
            }
        }
        if(!ok)
            cout << 0 << ' ' << 0 << '\n';
    }
}
