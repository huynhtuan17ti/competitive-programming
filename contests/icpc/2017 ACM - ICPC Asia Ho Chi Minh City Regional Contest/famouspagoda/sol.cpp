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
*/

ll cost(int l, int r, int k){
    if(l > r)
        return 0;
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

void calc(int L, int k, int l, int r, int optl, int optr){
    if(l > r)
        return;
    int mid = (l+r) >> 1;
    dp[mid][L] = INF;
    int optmid = 0;
    for(int i = optl; i <= optr; i++){
        ll cur_cost = dp[i][L-1] + cost(i+1, mid, k);
        if(dp[mid][L] > cur_cost){
            dp[mid][L] = cur_cost;
            optmid = i;
        }
    }
    calc(L, k, l, mid-1, optl, optmid);
    calc(L, k, mid+1, r, optmid, optr);
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int N, G, k;
    cin >> N >> G >> k;
    for(int i = 1; i <= N; i++){
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
        sqr_sum[i] = sqr_sum[i-1] + 1LL*a[i]*a[i];
    }
    for(int i = 1; i <= N; i++)
        dp[i][1] = cost(1, i, k);

    for(int L = 2; L <= G; L++)
        calc(L, k, 1, N, 1, N);
    cout << dp[N][G] << '\n';
}