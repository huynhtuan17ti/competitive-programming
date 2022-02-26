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
const int inf = 1e9;

int main(){
    io
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int n, x;
    cin >> n >> x;
    vector <int> a(n);
    for(auto &u: a)
        cin >> u;
    vector <int> dp(x+1, inf);
    dp[0] = 0;
    for(int u: a)
        for(int j = u; j <= x; j++)
            dp[j] = min(dp[j], dp[j-u] + 1);

    cout << ((dp[x] == inf)? -1: dp[x]) << '\n';
}