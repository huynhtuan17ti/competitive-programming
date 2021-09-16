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

/*
    Let's call dp[i][j] is the minimum operations that use to convert s[1..i] to t[1..j]
    We have 3 operations:
    - Op 1: Insert character ch at position pos
    - Op 2: Delete a character at postition pos
    - Op 3: Replace the character at postion pos to ch

    The dynamic formula:
    3 operations above corresponding to 3 formula
    dp[i][j] = dp[i][j-1] + 1
    dp[i][j] = dp[i-1][j] + 1
    dp[i][j] = dp[i-1][j-1] + 1

    The base value:
    - dp[0][0] = 0
    - dp[0][1..i] = i
    - dp[1..i][0] = i
*/

struct query{
    string q;
    int pos;
    char ch;
};

const int MAXN = 1e3 + 5;
int dp[MAXN][MAXN];

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    s = ' ' + s; // to 0-base
    t = ' ' + t; // to 0-base

    // initialize the baseline
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++)
        dp[i][0] = i;
    for(int i = 1; i <= m; i++)
        dp[0][i] = i;

    // dynamic calculation
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            dp[i][j] = INT_MAX;
            if(s[i] != t[j]){
                dp[i][j] = min(dp[i][j], dp[i][j-1] + 1); // INSERT
                dp[i][j] = min(dp[i][j], dp[i-1][j] + 1); // DELETE
                dp[i][j] = min(dp[i][j], dp[i-1][j-1] + 1); // REPLACE
            }else{
                dp[i][j] = dp[i-1][j-1];
            }
        }
    stack <query> Q;
    int u = n, v = m;
    while(dp[u][v] > 0){
        if(u > 0 && v > 0 && s[u] == t[v] && dp[u][v] == dp[u-1][v-1]){
            u--;
            v--;
        }else{
            if(v > 0 && dp[u][v] == dp[u][v-1] + 1){
                Q.push({"INSERT", u+1, t[v]});
                v--;
            }
            if(u > 0 && dp[u][v] == dp[u-1][v] + 1){
                Q.push({"DELETE", u});
                u--;
            }
            if(u > 0 && v > 0 && dp[u][v] == dp[u-1][v-1] + 1){
                Q.push({"REPLACE", u, t[v]});
                u--;
                v--;
            }
        }
    }

    cout << Q.size() << '\n';
    int bonus = 0;
    while(!Q.empty()){
        query q = Q.top();
        Q.pop();
        if(q.q == "DELETE"){
            
            cout << q.q << ' ' << q.pos + bonus << '\n';
            bonus--;
        }
        else if(q.q == "INSERT"){
            cout << q.q << ' ' << q.pos + bonus << ' ' << q.ch << '\n';
            bonus++;
        }else
            cout << q.q << ' ' << q.pos + bonus << ' ' << q.ch << '\n';
    }
}