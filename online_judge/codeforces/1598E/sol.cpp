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
const int MAXN = 1e3 + 5;
 
int n, m;
ll Sum = 0;
 
ll dp[MAXN][MAXN][2]; // 0 is horizontal, 1 is vertical
bool vi[MAXN][MAXN];
 
void _update(int d, int i, int j, ll val){
    int dx = 1, dy = 0;
    if(d == 0)
        swap(dx, dy);
    d = 1 - d;
    int row = i, col = j;
    while(row <= n && col <= m){
        if(vi[row][col])
            return;
        
        Sum -= dp[row][col][d];
        dp[row][col][d] = dp[row][col][d] + val;
        Sum += dp[row][col][d];
        
        // update
        row += dx; col += dy;
        swap(dx, dy);
        d = 1 - d;
    }
}
 
 
void solve(){
    int q;
    cin >> n >> m >> q;
    //initialize dp table
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            dp[i][j][0] = dp[i][j][1] = 1;
            if(j > 1)
                dp[i][j][0] += dp[i][j-1][1];
            if(i > 1)
                dp[i][j][1] += dp[i-1][j][0];
            Sum += dp[i][j][0] + dp[i][j][1];
        }
    
    int discount = n*m;
 
    while(q--){
        int x, y;
        cin >> x >> y;
        vi[x][y] = !vi[x][y];
        ll coeff = (vi[x][y])? -1: 1;
 
        ll temp1, temp2;
        if(!vi[x][y]){ //if cell is free
            discount += 1;
            dp[x][y][0] = dp[x][y-1][1] + 1;
            dp[x][y][1] = dp[x-1][y][0] + 1;
            Sum += (dp[x][y][0] + dp[x][y][1]);
            temp1 = dp[x][y-1][1] + 1;
            temp2 = dp[x-1][y][0] + 1;
        }else{
            temp1 = dp[x][y][0];
            temp2 = dp[x][y][1];
            discount -= 1;
            Sum -= (dp[x][y][0] + dp[x][y][1]);
            dp[x][y][0] = dp[x][y][1] = 0;
        }
 
        _update(0, x+1, y, coeff*temp1);
        _update(1, x, y+1, coeff*temp2);
        cout << Sum - discount << '\n';
    }
}
 
int main(){
    io
    int t; t = 1;
    while(t--){
        solve();
    }
}