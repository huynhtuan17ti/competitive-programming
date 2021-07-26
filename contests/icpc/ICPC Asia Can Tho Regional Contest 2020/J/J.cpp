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

typedef pair <ll, ll> ii;
typedef vector <ii> vii;
#define fi first
#define se second
#define mp make_pair
#define PROB "text"
#define MAXN 4000005

ii G[50][2];

bool check(int len, ll mid, ll m){
    ll num = 0;
    REP(i, 0, len){
        FOR(j, 0, 1){
            if(i == 0 && j == 1)
                continue;
            num += max(0LL, min(mid - G[i][j].fi + 1, G[i][j].se - G[i][j].fi + 1));
        }
        //cout << G[i][0].fi << ' ' << G[i][0].se << '\n';
        //cout << G[i][1].fi << ' ' << G[i][1].se << '\n';
        //cout << num << '\n';
    }
    //cout << num << '\n';
    return (num >= m);
}

int main(){
    _io
    int t;
    cin >> t;
    while(t--){
        ll m, n;
        cin >> n >> m;
        vector <ll> a;
        ll F = 1;
        a.pb(1);
        ll val = 2;
        while(val <= n){
            a.pb(val);
            F = F*3;
            val = (a[a.size()-1] + F);
        }
        REP(i, 0, a.size()){
            ll l = 1, r = a[i];
            if(i == a.size()-1){
                l = r - (n - r)/2;
            }
            G[i][0] = {l, r};

            l = a[i]*2, r = a[i]*3 - 2;
            if(i == a.size()-1){
                r = l + (n- a[i]-1)/2;
            }
            G[i][1] = {l, r};
            //cout << 0 << ' ' << G[i][0].fi << ' ' << G[i][0].se << '\n';
            //cout << 1 << ' ' << G[i][1].fi << ' ' << G[i][1].se << '\n';
        }
//        cout << check(a.size(), 5, m) << '\n';
//        return 0;
        ll L = 1, R = G[a.size()-1][1].se;
        while(L <= R){
            ll mid = (L+R) >> 1;
            if(check(a.size(), mid, m))
                R = mid-1;
            else L = mid+1;
        }
        cout << R+1 << '\n';
    }
}