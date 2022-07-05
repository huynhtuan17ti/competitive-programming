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
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);
    int n, x;
    cin >> n >> x;
    vector <int> h(n+1), s(n+1);
    for(int i = 1; i <= n; i++)
        cin >> h[i];
    for(int i = 1; i <= n; i++)
        cin >> s[i];
    
    int res = 0;

    vector <int> dp(x+1);
    for(int i = 1; i <= n; i++)
        for(int j = x; j >= h[i]; j--){
            dp[j] = max(dp[j], dp[j-h[i]] + s[i]);
            res = max(res, dp[j]);
        }
    cout << res << '\n';
}