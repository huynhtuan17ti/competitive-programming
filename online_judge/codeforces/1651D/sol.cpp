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
const int MAXN = 1e6 + 5;
const int inf = 1e9;
 
vector <int> G[MAXN];
 
void solve(){
    int n; cin >> n;
    vii points(n);
    map <ii, int> M;
    for(int i = 0; i < n; i++){
        cin >> points[i].fi >> points[i].se;
        M[points[i]] = i;
    }
    
    vector <int> tp;
    
    int curPos = n;
    for(int i = 0; i < n; i++){
        ii p = points[i];
        for(int k = 0; k < 4; k++){
            int x = p.fi + dx[k];
            int y = p.se + dy[k];
 
            if(M.find(mp(x, y)) == M.end()){
                points.push_back(mp(x, y));
                G[i].push_back(curPos);
                G[curPos].push_back(i);
                M[mp(x, y)] = curPos;
 
                tp.push_back(curPos);
 
                curPos += 1;
            }else{
                G[i].push_back(M[mp(x, y)]);
                G[M[mp(x, y)]].push_back(i);
            }
        }
    }
 
    queue <int> Q;
    vector <int> len(points.size(), inf);
    vector <int> ans(points.size(), 0);
    
    for(int u: tp){
        Q.push(u);
        len[u] = 0;
        ans[u] = u;
    }
    
 
    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        for(int v: G[u]){
            if(len[v] > len[u] + 1){
                len[v] = len[u] + 1;
                ans[v] = ans[u];
                Q.push(v);
            }
        }
    }
 
    for(int i = 0; i < n; i++){
        int pos = ans[i];
        cout << points[pos].fi << ' ' << points[pos].se << '\n';
    }
}
 
int main(){
    io
    int t = 1;
    while(t--){
        solve();
    }
}
