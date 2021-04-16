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
#define PROB "text"
#define MAXN 400005

int f[MAXN], t[MAXN];

int main(){
    _io
    int d; cin >> d;
    for(int iTest = 1; iTest <= d; iTest++){
        int n, s;
        cin >> n >> s;
        int Max = INT_MIN;
        for(int i = 1; i <= n; i++){
            cin >> f[i] >> t[i];
            Max = max(Max, f[i] - max(0, t[i] - s));
        }
        cout << "Case #" << iTest << ": " << Max << '\n';
    }
}
