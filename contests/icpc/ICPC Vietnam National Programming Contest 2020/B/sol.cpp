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
const int MAXN = 1e6;

int dx[] = {-1, 1, 0, 0, -1, 1, -1, 1};
int dy[] = {0, 0, -1, 1, 1, -1, -1, 1};

vector <char> a[MAXN+5];
vector <vector <ll>> dp[2];

struct cell{
    int x, y, type;
    // type = 0 for upper
    // type = 1 for lower
};

void solve(int r, int c){
    for(int i = 1; i <= r; i++){
        a[i].resize(c+1);
        for(int j = 1; j <= c; j++)
            cin >> a[i][j];
    }
    a[0].resize(c+1);
    a[r+1].resize(c+1);

    dp[0].resize(r+2);
    dp[1].resize(r+2);
    for(int i = 0; i <= r+1; i++){
        dp[0][i].resize(c+2, INT_MAX);
        dp[1][i].resize(c+2, INT_MAX);
    }

    deque <cell> Q;
    // init upper
    for(int j = 1; j <= c; j++){
        dp[0][0][j] = 0;
        Q.push_back({0, j, 0});
    }
    for(int i = 1; i <= r; i++){
        dp[0][i][c+1] = 0;
        Q.push_back({i, c+1, 0});
    }

    // init lower
    for(int j = 1; j <= c; j++){
        dp[1][r+1][j] = 0;
        Q.push_back({r+1, j, 1});
    }
    for(int i = 1; i <= r; i++){
        dp[1][i][0] = 0;
        Q.push_back({i, 0, 1});
    }

    while(!Q.empty()){
        cell u = Q.front();
        int type = u.type;
        Q.pop_front();
        for(int k = 0; k < 8; k++){
            int X = u.x + dx[k];
            int Y = u.y + dy[k];
            if(1 <= X && X <= r && 1 <= Y && Y <= c){
                int w = INT_MAX;
                if(a[X][Y] == '.')
                    w = 1;
                else if(a[X][Y] == '#')
                    w = 0;
                if(dp[type][X][Y] > dp[type][u.x][u.y] + w){
                    dp[type][X][Y] = dp[type][u.x][u.y] + w;
                    if(w == 0)
                        Q.push_front({X, Y, type});
                    else Q.push_back({X, Y, type});
                }
            }
        }
    }

    ll res = INT_MAX;
    for(int i = 1; i <= r; i++)
        for(int j = 1; j <= c; j++)
            res = min(res, dp[0][i][j] + dp[1][i][j] - (a[i][j] == '.'));
    if(res == INT_MAX)
        cout << -1 << '\n';
    else
        cout << res << '\n';


    // reset
    for(int i = 0; i <= r+1; i++)
        a[i].clear();
    
    for(int i = 0; i <= r+1; i++){
        dp[0][i].clear();
        dp[1][i].clear();
    }
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int r, c;
    while(cin >> r >> c){
        if(r == 0 && c == 0)
            return 0;
        solve(r, c);
    }
}