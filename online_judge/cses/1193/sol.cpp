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
char t[] = {'U', 'D', 'L', 'R'};
const int MAXN = 1e3 + 5;
int trace[MAXN][MAXN];
char a[MAXN][MAXN];
int n, m;

bool check(int i, int j){
    return (0 <= i && i < n && 0 <= j && j < m && a[i][j] == '.');
}

int main(){
    io
    //freopen("test.inp", "r", stdin);
    cin >> n >> m;
    int si, sj, ei, ej;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            trace[i][j] = -1;
            if(a[i][j] == 'A'){
                si = i;
                sj = j;
                a[i][j] = '.';
            }
            if(a[i][j] == 'B'){
                ei = i;
                ej = j;
                a[i][j] = '.';
            }
        }
    
    auto bfs = [&](int i, int j){
        queue <ii> Q;
        Q.push({i, j});
        a[i][j] = '#';
        while(!Q.empty()){
            ii u = Q.front();
            Q.pop();
            for(int k = 0; k < 4; k++){
                int x = u.fi + dx[k];
                int y = u.se + dy[k];
                if(check(x, y)){
                    a[x][y] = '#';
                    trace[x][y] = k;
                    Q.push({x, y});
                }
            }
        }
    };

    bfs(si, sj);
    vector <int> path;
    if(a[ei][ej] == '.'){
        return cout << "NO", 0;
    }
    cout << "YES" << '\n';
    string ans = "";
    while(trace[ei][ej] >= 0){
        int k = trace[ei][ej];
        ei -= dx[k];
        ej -= dy[k];
        ans += t[k];
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    cout << ans << '\n';
}