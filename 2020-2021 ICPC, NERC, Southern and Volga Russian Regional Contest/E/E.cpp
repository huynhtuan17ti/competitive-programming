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
#define PROB "E"
#define MAXN 400005

int main(){
    _io
    freopen(PROB".inp", "r", stdin);
    freopen(PROB".out", "w", stdout);
    int t; cin >> t;
    while(t--){
        int a[4];
        cin >> a[0] >> a[1] >> a[2] >> a[3];
        sort(a, a+4);
        cout << a[0]*a[2] << '\n';
    }
}
