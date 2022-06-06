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

vector <int> getDigits(int x){
    vector <int> digits;
    while(x > 0){
        digits.push_back(x%10);
        x /= 10;
    }
    return digits;
}

int main(){
    io
    int n; cin >> n;
    vector <int> dp(n+1, n+1);
    dp[0] = 0;
    vector <int> digits;
    for(int i = 1; i <= n; i++){
        digits = getDigits(i);
        for(int d: digits)
            dp[i] = min(dp[i], dp[i-d] + 1);
    }
    cout << dp[n] << '\n';
}