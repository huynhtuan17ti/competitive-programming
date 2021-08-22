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
const int MAXN = 1e3 + 5;

char a[MAXN][MAXN];

vii G[MAXN][MAXN];

void solve(int iTest){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            G[i][j].clear();
            cin >> a[i][j];
        }

    for(int i = 1; i <= n; i++){
        int pre = 1;
        a[i][m+1] = '#';
        for(int j = 1; j <= m+1; j++){
            if(a[i][j-1] == '#' && a[i][j] != '#'){
                pre = j;
            }
            if(a[i][j-1] != '#' && a[i][j] == '#'){
                int k = j-1;
                for(int p = pre; p < j; p++){
                    if(k == p){
                        k--;
                        continue;
                    }
                    G[i][p].push_back({i, k});
                    k--;
                }
            }
        }
    }

    for(int j = 1; j <= m; j++){
        int pre = 1;
        a[n+1][j] = '#';
        for(int i = 1; i <= n+1; i++){
            if(a[i-1][j] == '#' && a[i][j] != '#'){
                pre = i;
            }
            if(a[i-1][j] != '#' && a[i][j] == '#'){
                int k = i-1;
                for(int p = pre; p < i; p++){
                    if(k == p){
                        k--;
                        continue;
                    }
                    G[p][j].push_back({k, j});
                    k--;
                }
            }
        }
    }

    queue <ii> Q;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(a[i][j] != '#' && a[i][j] != '.'){
                Q.push({i, j});
            }

    int cnt = 0;
    while(!Q.empty()){
        ii u = Q.front();
        Q.pop();
        for(ii v: G[u.fi][u.se]){
            if(a[v.fi][v.se] == '.'){
                cnt++;
                //cout << u.fi << ' ' << u.se << "->" << v.fi << ' '<< v.se << '\n';
                a[v.fi][v.se] = a[u.fi][u.se];
                Q.push(v);
            }
        }
    }
    cout << "Case #" << iTest << ": ";
    cout << cnt << '\n';
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            cout << a[i][j];
        cout << '\n';
    }
}

int main(){
    io
    int t;
    cin >> t;
    for(int iTest = 1; iTest <= t; iTest++){
        solve(iTest);
    }
}