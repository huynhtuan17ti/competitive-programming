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
const int MAXN = 5e5 + 5;

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n, s;
    cin >> n >> s;
    vector <pair <ii, int>> d;
    for(int i = 0; i < n; i++){
        int x, y, w;
        cin >> x >> y >> w;
        d.push_back({mp(x, y), w});
    }

    auto dist = [&](ii p1, ii p2) -> double{
        return sqrt((p1.fi - p2.fi)*(p1.fi - p2.fi) + (p1.se - p2.se)*(p1.se - p2.se));
    };

    auto getBit = [&](int val, int id) -> bool{
        return (val >> id)&1;
    };  

    int maxState = (1<<n)-1;
    vector <vector <double>> dp(maxState+1, vector <double>(n, 1e9));
    for(int i = 0; i < n; i++)
        dp[(1<<i)][i] = dist(mp(0, 0), d[i].fi) + d[i].se;
    
    int ansState = 0, last = -1;
    for(int state = 1; state <= maxState; state++){
        for(int i = 0; i < n; i++)
            if(getBit(state, i)){
                int preState = state - (1<<i);
                for(int j = 0; j < n; j++)
                if(getBit(preState, j))
                    dp[state][i] = min(dp[state][i], dp[preState][j] + dist(d[j].fi, d[i].fi) + d[i].se);
            }
        if(__builtin_popcount(ansState) < __builtin_popcount(state)){
            int _last = 0;
            for(int i = 1; i < n; i++)
                if(dp[state][i] + dist(d[i].fi, mp(0, 0)) < dp[state][_last] + dist(d[_last].fi, mp(0, 0)))
                    _last = i;
            if(dp[state][_last] + dist(d[_last].fi, mp(0, 0)) <= s){
                ansState = state;
                last = _last;
            }
        }
    }
    if(last == -1){
        return cout << 0, 0;
    }
    // trace back
    vector <int> path;
    path.push_back(last+1);
    while(1){
        int preState = ansState - (1<<last);
        if(preState == 0)
            break;
        for(int i = 0; i < n; i++)
            if(getBit(preState, i) && dp[ansState][last] == dp[preState][i] + dist(d[i].fi, d[last].fi) + d[last].se){
                ansState = preState;
                last = i;
                break;
            }
        path.push_back(last+1);
        ansState = preState;
    }
    reverse(path.begin(), path.end());
    cout << path.size() << '\n';
    for(int u: path)
        cout << u << ' ';
}