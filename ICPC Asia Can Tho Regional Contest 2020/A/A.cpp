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
#define MAXN 1005

int dp[MAXN][MAXN];

vector <int> trace(int m){
    //cout << dp[1][5] << '\n';
    vector <int> res;
    int val = m;
    FORs(i, m, 1){
        if(dp[i][val] == dp[i-1][(val^i)] + 1){
            //cout << i  << ' ' << (val^i) << ' ' << dp[i][val] << ' ' << dp[i-1][(val^i)] << '\n';
            res.pb(i);
            val = (val^i);
        }
    }
    return res;
}

int main(){
    _io
    FOR(i, 0, 1000)
        FOR(j, 0, 1000)
            dp[i][j] = INT_MIN;
    dp[0][0] = 0;
    FOR(i, 1, 1000){
        FOR(j, 0, 1000){
            dp[i][j] = max(dp[i-1][j], dp[i][j]);
            if((j^i) <= 1000)
                dp[i][j] = max(dp[i][j], dp[i-1][(j^i)] + 1);
        }
    }
    //cout << ((1^7)) << '\n';
    int t; cin >> t;
    while(t--){
        int m; cin >> m;
        cout << dp[m][m] << '\n';
        vector <int> a = trace(m);
        FORs(i, a.size()-1, 0)
            cout << a[i] << ' ';
        cout << '\n';
    }
}