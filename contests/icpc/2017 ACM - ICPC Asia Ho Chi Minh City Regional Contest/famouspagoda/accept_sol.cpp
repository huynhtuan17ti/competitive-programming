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
const int MAXN = 2e3 + 5;
const ll INF = 1e16;

int a[MAXN];
ll dp[MAXN][MAXN];
ll sum[MAXN], sqr_sum[MAXN];

/*
    dp[i][k] = dp[j][k-1] + cost(j+1, i, k) with j < i
    if k = 2:
        median = (sum[r])
        ans = sqr_sum[r] - sqr_sum[l-1] + (r-l+1)*median*median - median*sum[r] + median*sum[l-1]
*/

ll cost(int l, int r, int k){
    if(k == 2){
        ll ans = 0;
        int median = round((double)(sum[r] - sum[l-1])/(r-l+1));
        ans = sqr_sum[r] - sqr_sum[l-1] + 1LL*(r-l+1)*median*median - 2LL*median*(sum[r] - sum[l-1]);
        return ans;
    }else{
        int mid = (r+l) >> 1;
        ll ans = 0;
        ans += (sum[r] - sum[mid]) - 1LL*a[mid]*(r - mid);
        ans += 1LL*a[mid]*(mid-l+1) - (sum[mid] - sum[l-1]);
        return ans;
    }
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.ans", "w", stdout);
    int N, G, k;
    cin >> N >> G >> k;
    for(int i = 1; i <= N; i++){
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
        sqr_sum[i] = sqr_sum[i-1] + 1LL*a[i]*a[i];
    }
    for(int i = 0; i <= N; i++)
        for(int j = 0; j <= G; j++)
            dp[i][j] = INF;

    dp[0][0] = 0;
    for(int i = 1; i <= N; i++)
        for(int j = 0; j < i; j++)
            for(int l = 1; l <= G; l++)
                dp[i][l] = min(dp[i][l], dp[j][l-1] + cost(j+1, i, k));
    
    cout << dp[N][G] << '\n';
}