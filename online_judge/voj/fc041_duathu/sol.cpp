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
const int MAXN = 1005;

int dp[MAXN][MAXN * 10];

int main(){
    io
    int n, k;
    cin >> n >> k;
    vii left, right;
    for(int i = 1; i <= n; i++){
        int x, t;
        cin >> x >> t;
        if(x < 0)
            left.push_back({-x, t});
        else right.push_back({x, t});
    }
    reverse(left.begin(), left.end());
    
    // (t - pre) + n * k + last >= s
    // (t - pre) + n * k + last - s = i
    // => (t - pre) + n * k + last = i + s
    // => n * k + last = i + s + (t - pre)
    // and last <= k

    auto minimumCost = [&](vii a) -> ll{
        if(a.size() == 0)
            return 0;
        // for(auto [u, v]: a)
        //     cout << u << ' ' << v << '\n';
        for(int i = 0; i < a.size(); i++){
            fill(dp[i], dp[i] + k + 1, INT_MAX);
        }
        if(k <= a[0].se){
            int n_trip = (a[0].se - k + k - 1)/k;
            int cost = n_trip * 2 * a[0].fi + a[0].fi;
            int remain = n_trip * k + k - a[0].se;
            assert(remain <= k);
            dp[0][remain] = cost;
            if(remain < k)
                dp[0][k] = cost + 2 * a[0].fi;
        }else{
            int cost = a[0].fi;
            int remain = k - a[0].se;
            dp[0][remain] = cost;
            if(remain < k)
                dp[0][k] = cost + 2 * a[0].fi;
        }
        
        for(int i = 1; i < a.size(); i++){
            for(int pre = 0; pre <= k; pre++){
                if(dp[i-1][pre] == INT_MAX) continue;
                if(pre <= a[i].se){
                    int n_trip = (a[i].se - pre + k - 1)/k;
                    int cost = n_trip * 2 * a[i].fi + (a[i].fi - a[i-1].fi);
                    int remain = n_trip * k + pre - a[i].se;
                    assert(remain <= k);
                    dp[i][remain] = min(cost + dp[i-1][pre], dp[i][remain]);
                    if(remain < k)
                        dp[i][k] = min(cost + 2 * a[i].fi + dp[i-1][pre], dp[i][k]);
                }else{
                    int cost = a[i].fi - a[i-1].fi;
                    int remain = pre - a[i].se;
                    dp[i][remain] = min(cost + dp[i-1][pre], dp[i][remain]);
                    if(remain < k)
                        dp[i][k] = min(cost + 2 * a[i].fi + dp[i-1][pre], dp[i][k]);
                }
            }
        }
        ll minCost = INT_MAX;
        for(int i = 0; i <= k; i++)
            if(dp[a.size() - 1][i] != INT_MAX)
                minCost = min(minCost, 1LL * dp[a.size()-1][i] + a[a.size()-1].fi);
        return minCost;
    };

    cout << minimumCost(left) + minimumCost(right) << '\n';
}