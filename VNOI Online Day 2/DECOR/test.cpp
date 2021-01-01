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
#define PROB "EnduringExodus"
#define MAXN 400005

int a[MAXN];

int main(){
    _io
    freopen(PROB".inp", "r", stdin);
    freopen(PROB".ans", "w", stdout);
    int n, k;
    cin >> n >> k;
    string s; cin >> s;
    int t = 0;
    for(char c : s)
        t += (c == '1');
    int j = 0;
    REP(i, 0, s.size())
        if(s[i] != '1'){
            a[j] = i+1;
            j+= 1;
        }
    int ans = a[n-t-1] - a[0];
    for(int i = 0; i < n-t-k; i++){
        int l = i;
        int r = i + k;
        while(r-l > 1){
            int m = l + (r-l)/2;
            if(a[m] - a[i] > a[i+k] - a[m])
                r = m;
            else l = m;
        }
        ans = min(ans, max(a[l] - a[i], a[i + k] - a[l]));
    }
    cout << ans;
}

