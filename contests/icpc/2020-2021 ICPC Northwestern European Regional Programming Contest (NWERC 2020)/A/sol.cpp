/* Tuan Kkura */
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define base 31
#define MOD 1e9+7
#define pb push_back
#define _io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

typedef pair <int, int> ii;
typedef vector <ii> vii;
#define fi first
#define se second
#define mp make_pair
#define PROB "A"
#define MAXN 205
const int limit = 5e6;
const ll inf = 1e18;
const int range = 1e6;

ll a[MAXN];
ll dp[limit+5];

int main(){
    _io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= limit; i++)
        dp[i] = inf;
    int minId = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        dp[i] = a[i];
        if(minId == 0 || a[i]*minId < a[minId]*i)
            minId = i;
    }
    for(int j = n+1; j <= limit; j++)
        for(int i = 1; i <= n; i++)
            dp[j] = min(dp[j], dp[j-i] + dp[i]);
    while(q--){
        int k;
        cin >> k;
        if(k <= range){
            cout << dp[k] << '\n';
        }else{
            k -= range;
            int s = k%minId + range;
            cout << dp[s] + 1LL*k/minId * a[minId] << '\n';
        }
    }

}