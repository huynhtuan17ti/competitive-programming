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

struct serve{
    int val, id;
};

struct cmp1{
    bool operator() (const serve &A, const serve &B) const{
        if(A.val == B.val)
        return A.id < B.id;
    return A.val > B.val;
    }
};

struct cmp2{
    bool operator() (const serve &A, const serve &B) const{
        return A.id < B.id;
    }
};

int main(){
    _io
    freopen(PROB".inp", "r", stdin);
    freopen(PROB".out", "w", stdout);
    int q; cin >> q;
    set <serve, cmp1> S1;
    set <serve, cmp2> S2;
    int cnt = 1;
    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int m; cin >> m;
            S1.insert({m, cnt});
            S2.insert({m, cnt});
            cnt++;
        }
        if(t == 2){
            auto it = S2.begin();
            cout << it->id << '\n';
            S2.erase(it);
            S1.erase(*it);
        }
        if(t == 3){
            auto it = S1.begin();
            cout << it->id << '\n';
            S1.erase(it);
            S2.erase(*it);
        }
    }
}
