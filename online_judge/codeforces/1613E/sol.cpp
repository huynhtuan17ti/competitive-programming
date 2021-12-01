#include <bits/stdc++.h>  
 
using namespace std;
 
const int MOD = 998244353;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define mp make_pair
#define fi first
#define se second
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int MAXN = 5e5 + 5;
int a[MAXN];
#define add 3

void solve(){
    int n, m;
    cin >> n >> m;
    vector <vector <char>> a(n);
    for(int i = 0; i < n; i++)
        a[i].resize(m);
    int si, sj;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] == 'L'){
                si = i;
                sj = j;
            }
        }
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    vector <vector <int>> vi(n);
    for(int i = 0; i < n; i++)
        vi[i].resize(m);
    
    auto check = [&](int i, int j){
        return (0 <= i && i < n && 0 <= j && j < m && a[i][j] == '.');
    };

    queue <ii> Q;
    Q.push({si, sj});
    vi[si][sj] = 1;
    while(!Q.empty()){
        ii u = Q.front();
        Q.pop();
        int cnt = 0;
        for(int k = 0; k < 4; k++){
            int x = u.fi + dx[k];
            int y = u.se + dy[k];
            cnt += check(x, y);
        }
        //cerr << u.fi << ' ' << u.se << ' ' << cnt << '\n';
        if(cnt <= 1 && a[u.fi][u.se] == '.'){
            a[u.fi][u.se] = '+';
        }
        if(a[u.fi][u.se] != 'L' && cnt > 1){
            vi[u.fi][u.se] = 0;
            continue;
        }
        for(int k = 0; k < 4; k++){
            int x = u.fi + dx[k];
            int y = u.se + dy[k];

            if(check(x, y) && !vi[x][y]){
                vi[x][y] = 1;
                Q.push({x, y});
            }        
        }
        
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cout << a[i][j];
        cout << '\n';
    }
}   

int main(){
    io
    int t; cin >> t;
    while(t--){
        solve();
    }
}