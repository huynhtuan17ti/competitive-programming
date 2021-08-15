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
 
int main(){
    io
    string s; cin >> s;
    s = ' ' + s;
    int n = s.size();
    vector <ll> dp(n);
    vector <ll> last(30);
    for(int i = 1; i < n; i++){
        dp[i] = 1;
        for(int j = 0; j < 27; j++)
            if(last[j] > 0)
                dp[i] = (dp[i] + dp[last[j]])%MOD;
 
        if(i > 1)
            last[s[i-1]-'a'] = i-1;
    }
    last[s[n-1] - 'a'] = n-1;
    ll res = 0;
    for(int i = 0; i < 27; i++)
        if(last[i] > 0){
            res = (res + dp[last[i]])%MOD;
        }
    cout << res << '\n';
}