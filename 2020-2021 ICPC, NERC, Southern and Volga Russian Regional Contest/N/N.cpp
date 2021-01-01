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
#define PROB "N"
#define MAXN 400005

int main(){
    _io
    freopen(PROB".inp", "r", stdin);
    freopen(PROB".out", "w", stdout);
    int t; cin >> t;
    while(t--){
        int c1, c2, c3;
        cin >> c1 >> c2 >> c3;
        int a1, a2, a3, a4, a5;
        cin >> a1 >> a2 >> a3 >> a4 >> a5;
        if(c1+c2+c3 < a1+a2+a3+a4+a5){
            cout << "NO" << '\n';
            continue;
        }
        if(c1 < a1){
            cout << "NO" << '\n';
            continue;
        }
        if(c2 < a2){
            cout << "NO" << '\n';
            continue;
        }
        if(c3 < a3){
            cout << "NO" << '\n';
            continue;
        }
        if(c1 + c3 < a1 + a3 + a4){
            cout << "NO" << '\n';
            continue;
        }
        if(c2 + c3 < a2 + a3 + a5){
            cout << "NO" << '\n';
            continue;
        }
        cout << "YES" << '\n';
    }
}
