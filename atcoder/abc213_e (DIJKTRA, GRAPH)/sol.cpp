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
const int MAXN = 505;
 
char s[MAXN][MAXN];
int cnt[MAXN][MAXN];
vii G[MAXN*MAXN];
 
bool check(char a, char b){
    if(a == '.' && b == '.')
        return true;
    if(a == '#' && b == '.')
        return true;
    return false;
}
 
int dist[MAXN*MAXN];
 
void dijktra(int u){
    for(int i = 1; i < MAXN*MAXN; i++)
        dist[i] = INT_MAX;
    priority_queue <ii, vii, greater <ii>> Q;
    Q.push({0, u});
    dist[u] = 0;
    while(!Q.empty()){
        ii v = Q.top();
        Q.pop();
        if(dist[v.se] != v.fi)
            continue;
        for(ii p: G[v.se]){
            if(dist[p.fi] > dist[v.se] + p.se){
                dist[p.fi] = dist[v.se] + p.se;
                Q.push({dist[p.fi], p.fi});
            }
        }
    }
}
 
int main(){
    io
    int H, W; cin >> H >> W;
    int num = 1;
    for(int i = 1; i <= H; i++)
        for(int j = 1; j <= W; j++){
            cin >> s[i][j];
            cnt[i][j] = num;
            num++;
        }
    for(int i = 1; i <= H; i++)
        for(int j = 1; j <= W; j++){
            if(i < H && check(s[i][j], s[i+1][j]))
                G[cnt[i][j]].push_back({cnt[i+1][j], 0});
            if(j < W && check(s[i][j], s[i][j+1]))
                G[cnt[i][j]].push_back({cnt[i][j+1], 0});   
            if(i > 1 && check(s[i][j], s[i-1][j]))
                G[cnt[i][j]].push_back({cnt[i-1][j], 0});
            if(j > 1 && check(s[i][j], s[i][j-1]))
                G[cnt[i][j]].push_back({cnt[i][j-1], 0}); 
 
            for(int p = -2; p <= 2; p++)
                for(int k = -2; k <= 2; k++){
                    int x = i + p, y = j + k;
                    if(abs(p) + abs(k) == 4)
                        continue;
                    if(1 <= x && x <= H && 1 <= y && y <= W){
                        G[cnt[i][j]].push_back({cnt[x][y], 1});
                    }
                }
        }
    dijktra(1);
    cout << dist[W*H] << '\n';
}