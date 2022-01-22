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
int c[MAXN][MAXN];
int r[MAXN][MAXN];

void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> c[i][j];

    for(int i = 0; i <= n+2; i++){
        fill(r[i], r[i] + n + 2, 0);
    }
    
    for(int j = 1; j <= n; j++)
        r[1][j] = 1;

    int res = 0;    
    for(int i = 1; i < n; i++)
        for(int j = 1; j <= n; j++){
            r[i+1][j] = (c[i][j] ^ r[i][j-1] ^ r[i][j+1] ^ r[i-1][j]);
        }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            res ^= r[i][j];
    cout << res << '\n';
}   

int main(){
    io
    int t; cin >> t;
    while(t--){
        solve();
    }
}