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
#define PROB "D"
#define MAXN 400005

int s[MAXN];

bool check(int val, int len_time){
    int cnt = 1;
    FORs(i, val, 1){
        if(cnt+s[i] > len_time)
            return false;
        cnt++;
    }
    return true;
}

int main(){
    _io
    freopen(PROB".inp", "r", stdin);
    freopen(PROB".out", "w", stdout);
    int t; cin >> t;
    while(t--){
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        FOR(i, 1, m)
            cin >> s[i];
        int num = abs(b-a)-1;
        int last;
        if(a < b)
            last = 1;
        else last = n;
        int len_time = abs(last-b);
        //cout << len_time << ' ' << num << '\n';
        sort(s+1, s+1+m);
        int l = 1, r = min(num, m);
        while(l <= r){
            int mid = (l+r) >> 1;
            if(check(mid, len_time))
                l = mid+1;
            else r = mid-1;
        }
        cout << l-1 << '\n';
    }
}
