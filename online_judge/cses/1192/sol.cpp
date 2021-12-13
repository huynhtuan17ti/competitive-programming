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
const int MAXN = 1e3 + 5;
char a[MAXN][MAXN];
int n, m;

bool check(int i, int j){
    return (0 <= i && i < n && 0 <= j && j < m && a[i][j] == '.');
}

void DFS(int i, int j){
    a[i][j] = '#';
    for(int k = 0; k < 4; k++){
        int X = i + dx[k];
        int Y = j + dy[k];
        if(check(X, Y)){
            DFS(X, Y);
        }
    }
}

int main(){
    io
    //freopen("test.inp", "r", stdin);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    int cnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(a[i][j] == '.'){
                DFS(i, j);
                cnt++;
            }
    cout << cnt << '\n';
}