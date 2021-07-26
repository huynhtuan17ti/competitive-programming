/* Tuan Kkura */
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define base 31
#define MOD 1000000007
#define pb push_back
#define _io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

typedef pair <int, int> ii;
typedef vector <ii> vii;
#define fi first
#define se second
#define mp make_pair
#define PROB "text"
#define MAXN 2005

int d[MAXN][MAXN];
ll dp[MAXN][1300], tmp[1300];

int get_bit(int val, int id){
    return (val >> id)&1;
}

int nextState(int state, int e){
    return (state - get_bit(state, 0))/2;
}

int main(){
    _io
    int n, e, k;
    cin >> n >> e >> k;
    for(int i = 1; i <= k; i++){
        int u, v;
        cin >> u >> v;
        d[u][v] = 1;
    }
    dp[0][0] = 1;
    tmp[0] = 1;
    int maxState = (1<<(2*e + 1));
    for(int i = 1; i <= n; i++){
        for(int state = 0; state < maxState; state++){
            dp[i][state] += tmp[state];
            dp[i][state] %= MOD;
            for(int j = 0; j < 2*e+1; j++){
                if(i - e + j <= n && i - e + j >= 1 &&
                        get_bit(state, j) && d[i][i - e + j] == 0){
                    dp[i][state] += tmp[state - (1<<j)];
                    dp[i][state] %= MOD;
                }
            }
        }
        for(int state = 0; state < maxState; state++)
            tmp[state] = 0;
        for(int state = 1; state < maxState; state++){
            int lastBit = max(e-i+1, 0);
            if(lastBit == 0 && get_bit(state, lastBit) == 0)
                continue;
            tmp[nextState(state, e)] += dp[i][state];
            tmp[nextState(state, e)] %= MOD;
        }
    }
    int lastState = 0, bit = e;
    for(int i = n; i >= max(1, n-e); i--){
        lastState += (1<<bit);
        bit--;
    }
    cout << dp[n][lastState] << '\n';
}
