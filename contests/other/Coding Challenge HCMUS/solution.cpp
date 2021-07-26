/* Tuan Kkura */
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define base 31
#define MOD 1e9+7
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORs(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, a, b) for(int i = a; i < b; i++)
#define __FOR(i, a, b, k) for(int i = a; i <= b; i+= k)
#define __REP(i, a, b, k) for(int i = a; i < b; i+= k)
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

int vi[MAXN][MAXN];
int _vi[MAXN][MAXN];
ii trace[MAXN][MAXN];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool ok = false;
int n;

void DFS(int u, int v, int s, int t, int val){
    if(ok)
        return;
    //cerr << u << ' ' << v << '\n';
    for(int k = 0; k < 4; k++){
        int xx = u + dx[k];
        int yy = v + dy[k];
        if(xx < 1)
            xx = n;
        if(xx > n)
            xx = 1;
        if(yy < 1)
            yy = n;
        if(yy > n)
            yy = 1;
        if(xx == s && yy == t){
            trace[xx][yy] = mp(u, v);
            ok = true;
        }
        if(ok)
            return;
        if(_vi[xx][yy] < val){
            trace[xx][yy] = mp(u, v);
            _vi[xx][yy] = val;
            DFS(xx, yy, s, t, val);
        }
    }
}

void BFS(int u, int v, int s, int t, int val){
    queue <ii> Q;
    Q.push({u, v});
    while(!Q.empty()){
        ii top = Q.front();
        Q.pop();
        for(int k = 0; k < 4; k++){
            int xx = top.fi + dx[k];
            int yy = top.se + dy[k];
            if(xx < 1)
                xx = n;
            if(xx > n)
                xx = 1;
            if(yy < 1)
                yy = n;
            if(yy > n)
                yy = 1;
            if(xx == s && yy == t){
                trace[xx][yy] = top;
                ok = true;
                return;
            }
            if(_vi[xx][yy] < val){
                trace[xx][yy] = top;
                _vi[xx][yy] = val;
                Q.push({xx, yy});
            }
        }
    }
}

vector <ii> BackTrack(int u, int v){
    vector <ii> path;
    while(u > 0){
        path.pb({u, v});
        int _u = u, _v = v;
        u = trace[_u][_v].fi;
        v = trace[_u][_v].se;
    }
    reverse(path.begin(), path.end());
    return path;
}

struct pn{
    ii node[2];
};

pn pair_node[MAXN*MAXN];
int num[MAXN*MAXN];

int manhattan_distance(ii a, ii b){
    return abs(a.fi - b.fi) + abs(a.se - b.se);
}

int manhattan_distance2(ii a, ii b){
    return min(abs(a.fi - b.fi), min(abs(n + a.fi - b.fi), abs(n - a.fi + b.fi)))
            + min(abs(a.se - b.se), min(abs(n - a.se + b.se), abs(n + a.se - b.se)));
}

int manhattan_distanceX(ii a, ii b){
    return min(abs(a.fi - b.fi), min(abs(n + a.fi - b.fi), abs(n - a.fi + b.fi)));
}

int manhattan_distanceY(ii a, ii b){
    return min(abs(a.se - b.se), min(abs(n - a.se + b.se), abs(n + a.se - b.se)));
}

int main(){
    _io
    freopen("text.inp", "r", stdin);
    freopen("text.out", "w", stdout);
    int m;
    cin >> n >> m;
    for(int i = 1; i <= 2*m; i++){
        int c, x, y;
        cin >> c >> x >> y;
        pair_node[c].node[num[c]] = mp(x, y);
        _vi[x][y] = INT_MAX;
        num[c]++;
    }
    sort(pair_node+1, pair_node+1+m, [](const pn &A, const pn &B){
            return manhattan_distanceY(A.node[0], A.node[1]) < manhattan_distanceY(B.node[0], B.node[1]);
        });
    for(int i = 1; i <= m; i++){
        ii u = pair_node[i].node[0];
        ii v = pair_node[i].node[1];
        ok = false;
        //cout << u.fi << ' ' << u.se << ' ' << v.fi << ' ' << v.se << '\n';
        BFS(u.fi, u.se, v.fi, v.se, i);
        //cerr << ok << '\n';
        if(!ok){
            _vi[u.fi][u.se] = 0;
            _vi[v.fi][v.se] = 0;
            continue;
        }
        vector <ii> path = BackTrack(v.fi, v.se);
        if(path.size() == 0)
            continue;
        cout << path.size() << '\n';
        for(ii v : path){
            cout << v.fi << ' ' << v.se << ' ';
            _vi[v.fi][v.se] = INT_MAX;
        }
        cout << '\n';
    }
}

