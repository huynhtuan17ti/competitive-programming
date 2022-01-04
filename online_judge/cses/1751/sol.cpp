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
const int MAXN = 5e5 + 5;
int G[MAXN];
bool vi[MAXN], instack[MAXN];
int par[MAXN];

int cntCycle = 0;
int cycle[MAXN], lenCycle[MAXN];
int len[MAXN];

void updateLength(int u, int v){
    if(cycle[u] > 0){
        len[u] = lenCycle[cycle[u]];
        return;
    }

    if(cycle[v] == 0)
        len[u] = len[v] + 1;
    else
        len[u] = 1 + lenCycle[cycle[v]];
}

void DFS(int u){
    vi[u] = 1;
    instack[u] = 1;
    int v = G[u];
    if(!vi[v]){
        par[v] = u;
        DFS(v);
        updateLength(u, v);
        //cout << u << ' ' << v << ' ' << len[u] << '\n';
    }
    else 
        if(instack[v]){
            cntCycle++;
            lenCycle[cntCycle] = 0;
            for(int p = u; p != par[v]; p = par[p]){
                lenCycle[cntCycle]++;
                cycle[p] = cntCycle;
            }
            len[u] = lenCycle[cntCycle];
        }else{
            updateLength(u, v);
            //cout << u << ' ' << v << ' ' << len[v] << '\n';
        }
    instack[u] = 0;
}

int main(){
    io
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        G[i] = x;
    }
    for(int i = 1; i <= n; i++)
        if(!vi[i])
            DFS(i);

    for(int i = 1; i <= n; i++){
        cout << len[i] << " \n"[i == n];
    }
}