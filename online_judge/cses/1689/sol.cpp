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
int dx[] = {-1, 1, 2, 2, -2, -2, -1, 1};
int dy[] = {2, 2, -1, 1, 1, -1, -2, -2};
const int MAXN = 15;

int G[MAXN][MAXN];

bool inGrid(int x, int y){
    return (1 <= x && x <= 8 && 1 <= y && y <= 8 && !G[x][y]);
}

int getDeg(int x, int y){
    int cnt = 0;
    for(int k = 0; k < 8; k++){
        cnt += inGrid(x + dx[k], y + dy[k]);
    }
    return cnt;
}

bool find(int num, int x, int y){
    G[x][y] = num;
    if(num == 8*8) // have reached all cells
        return true;
    typedef pair <int, ii> pip;
    vector <pip> s;
    for(int i = 0; i < 8; i++){
        int X = x + dx[i], Y = y + dy[i];
        if(inGrid(X, Y)){
            s.push_back({getDeg(X, Y), mp(X, Y)});
        }
    }
    sort(s.begin(), s.end()); // greedy to run with small degree cell
    for(auto [_n, p]: s)
        if(find(num+1, p.fi, p.se))
            return true;
    G[x][y] = 0;
    return false;
}

int main(){
    io
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int x, y;
    cin >> y >> x;
    find(1, x, y);
    for(int i = 1; i <= 8; i++)
        for(int j = 1; j <= 8; j++)
            cout << G[i][j] << " \n"[j == 8];
}