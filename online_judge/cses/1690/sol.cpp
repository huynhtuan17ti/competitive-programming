#include <bits/stdc++.h>  
using namespace std;

const int MOD = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define mp make_pair
#define fi first
#define se second
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
const int MAXN = 20;

vector <int> G[MAXN];
ll dp[(1<<MAXN)][MAXN];

int main(){
    io
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
    }

    auto getBit = [&](int val, int bit)->int{
        return (val >> bit)&1;
    };

    dp[1][0] = 1;
    int maxState = (1<<n)-1;
    for(int state = 0; state <= maxState; state++){
        for(int cur = 0; cur < n; cur++)
            if(getBit(state, cur)){
                if(dp[state][cur] == 0)
                    continue;
                for(int v: G[cur])
                    if(!getBit(state, v))
                        dp[state + (1<<v)][v] = (dp[state + (1<<v)][v] + dp[state][cur])%MOD;
            }
    }
    cout << dp[maxState][n-1] << '\n';
}