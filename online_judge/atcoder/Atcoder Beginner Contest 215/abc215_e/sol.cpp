#include <bits/stdc++.h>  
 
using namespace std;
 
const int MOD = 998244353;
typedef unsigned long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define mp make_pair
#define fi first
#define se second
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int MAXN = 1050;
 
ll dp[MAXN][10];
 
int get_bit(int state, int id){
    return (state>>id)&1;
}
 
int main(){
    io
    int len; cin >> len;
    string s; cin >> s;
    int n = s.size();
    s = " " + s;
    ll res = 0;
    int maxState = (1<<10);
    for(int i = 1; i <= n; i++){
        int x = s[i] - 'A';
        for(int state = maxState-1; state >= 0; state--){
            if(get_bit(state, x) == 1){
                dp[state][x] += dp[state][x];
                dp[state][x] %= MOD;
 
                int prestate = state - (1<<x);
                if(prestate == 0){
                    dp[state][x] += 1;
                }
 
                for(int p = 0; p < 10; p++){
                    if(get_bit(prestate, p)){
                        dp[state][x] += dp[prestate][p];
                        dp[state][x] %= MOD;
                    }
                }
            }
        }
    }
    for(int state = 0; state < maxState; state++){
        for(int p = 0; p < 10; p++)
            if(get_bit(state, p))
                res = (res + dp[state][p])%MOD;
    }
    cout << res << '\n';
}