#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
#define mp make_pair
#define fi first
#define se second
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
const int MAXN = 5e5 + 5;

int main()
{
    io
    int n, x;
    cin >> n >> x;
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    vector<ll> dp(x + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = c[i]; j <= x; j++)
            if (dp[j - c[i]])
                dp[j] = (dp[j] + dp[j - c[i]]) % MOD;
    cout << dp[x];
}