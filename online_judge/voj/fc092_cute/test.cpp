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
const int MAXN = 1500;

int dp[20][MAXN+5];

int main(){
    io
    dp[0][0] = 1;
    for(int i = 1; i <= 18; i++){
        for(int digit = 0; digit <= 9; digit++)
            for(int j = MAXN; j >= digit*digit; j--)
                dp[i][j] += dp[i-1][j-digit*digit];
    }
    int cnt = 0;
    for(int i = 0; i <= MAXN; i++)
        if(dp[18][i] > 0){
            cnt++;
        }
    cout << cnt << '\n';
}