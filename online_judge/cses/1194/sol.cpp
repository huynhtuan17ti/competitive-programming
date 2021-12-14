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
char dt[] = {'U', 'D', 'L', 'R'}; 
const int inf = 1e9;
const int MAXN = 5e5 + 5;

int main(){
    io
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector <vector <char>> a(n, vector <char> (m));
    vii monsters;
    ii human;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] == 'M')
                monsters.push_back({i, j});
            if(a[i][j] == 'A')
                human = {i, j};
        }
    
    auto check = [&](int i, int j) -> bool{
        return (0 <= i && i < n && 0 <= j && j < m && a[i][j] == '.');
    };

    queue <ii> q;
    vector <vector <int>> len(n, vector <int> (m, inf));
    for(ii u: monsters){
        q.push(u);
        len[u.fi][u.se] = 0;
    }
    while(!q.empty()){
        ii u = q.front();
        q.pop();
        for(int k = 0; k < 4; k++){
            int x = u.fi + dx[k];
            int y = u.se + dy[k];
            if(check(x, y) && len[x][y] > len[u.fi][u.se] + 1){
                len[x][y] = len[u.fi][u.se] + 1;
                q.push({x, y});
            }
        }
    }

    vector <vector <int>> humanLen(n, vector <int> (m, inf));
    vector <vector <int>> trace(n, vector <int> (m, -1));
    q.push(human);
    humanLen[human.fi][human.se] = 0;
    while(!q.empty()){
        ii u = q.front();
        q.pop();
        if(u.fi == 0 || u.fi == n-1 || u.se == 0 || u.se == m-1){
            cout << "YES" << '\n';
            string ans = "";
            int ei = u.fi, ej = u.se;
            while(trace[ei][ej] >= 0){
                int k = trace[ei][ej];
                ei -= dx[k];
                ej -= dy[k];
                ans += dt[k];
            }
            reverse(ans.begin(), ans.end());
            cout << ans.size() << '\n';
            cout << ans << '\n';
            return 0 ;
        }
        for(int k = 0; k < 4; k++){
            int x = u.fi + dx[k];
            int y = u.se + dy[k];
            if(check(x, y) && len[x][y] > humanLen[u.fi][u.se] + 1){
                humanLen[x][y] = humanLen[u.fi][u.se] + 1;
                a[x][y] = '#';
                trace[x][y] = k;
                q.push({x, y});
            }
        }
    }
    cout << "NO";
}