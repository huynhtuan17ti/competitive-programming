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
#define PROB "text"
#define MAXN 1005

int g[MAXN][MAXN];

struct local{
    int x, y;
    int val;
};

bool operator < (const local &A, const local &B){
    return A.val < B.val;
}

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main(){
    _io
    int T; cin >> T;
    for(int iTest = 1; iTest <= T; iTest++){
        int r, c;
        cin >> r >> c;
        ll sum = 0;
        for(int i = 1; i <= r; i++)
            for(int j = 1; j <= c; j++)
            {
                cin >> g[i][j];
                sum += g[i][j];
            }

        priority_queue <local> Q;
        for(int i = 1; i <= r; i++)
            for(int j = 1; j <= c; j++)
                Q.push({i, j, g[i][j]});

        while(!Q.empty()){
            local u = Q.top();
            Q.pop();
            for(int k = 0; k < 4; k++){
                int X = u.x + dx[k];
                int Y = u.y + dy[k];
                if(1 <= X && X <= r && 1 <= Y && Y <= c && g[X][Y] < g[u.x][u.y]-1){
                    g[X][Y] = g[u.x][u.y]-1;
                    Q.push({X, Y, g[X][Y]});
                }
            }
        }
        ll res = 0;
        for(int i = 1; i <= r; i++)
            for(int j = 1; j <= c; j++)
                res += g[i][j];
        cout << "Case #" << iTest << ": " << res - sum << '\n';
    }
}
