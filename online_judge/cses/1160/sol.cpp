/*
    The idea is to find all possible lengths, and then using algorithm of Planets Queries I to check all lengths.
*/

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
const int MAXD = 30;
int parent[MAXN][MAXD];

int G[MAXN];
bool vi[MAXN], instack[MAXN];
int par[MAXN];
int cntCycle = 0;
int cycle[MAXN], lenCycle[MAXN];
int len[MAXN];

void DFS(int u){
    vi[u] = 1;
    instack[u] = 1;
    int v = G[u];
    if(!vi[v]){
        par[v] = u;
        DFS(v);
        len[u] = len[v] + 1;
    }
    else 
        if(instack[v]){
            len[u] = 1;
            cntCycle++;
            lenCycle[cntCycle] = 0;
            for(int p = u; p != par[v]; p = par[p]){
                lenCycle[cntCycle]++;
                cycle[p] = cntCycle;
            }
        }else
            len[u] = len[v] + 1;

    instack[u] = 0;
}

int main(){
    io
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> G[i];
        parent[i][0] = G[i];
    }

    for(int i = 1; i <= n; i++)
        if(!vi[i])
            DFS(i);

    for(int j = 1; j < MAXD; j++)
        for(int i = 1; i <= n; i++)
            parent[i][j] = parent[parent[i][j-1]][j-1];

    auto jump =[&](int x, int k) -> int{
        for(int bit = 0; bit < MAXD; bit++)
            if((k>>bit)&1)
                x = parent[x][bit];
        return x;
    };

    while(q--){
        int u, v;
        cin >> u >> v;
        vector <int> candidateAns;
        if(cycle[u] == cycle[v] && cycle[u] != 0){ // if in same cycle
            if(len[u] < len[v])
                candidateAns.push_back(lenCycle[cycle[u]] - len[v] + len[u]);
            else candidateAns.push_back(len[u] - len[v]);
        }else if(cycle[u] == 0 && cycle[v] > 0){ // if u is not in cycle and v is in cycle
            candidateAns.push_back(len[u] - len[v]);
            candidateAns.push_back(len[u] + lenCycle[cycle[v]] - len[v]); // special case
        }else
            candidateAns.push_back(len[u] - len[v]);
        
        // checking for each possible lengths, if there are any answer, print and break
        bool isAns = false;
        for(int ans: candidateAns){
            if(ans >= 0 && jump(u, ans) == v){
                cout << ans << '\n';
                isAns = true;
                break;
            }
        }

        if(!isAns)
            cout << -1 << '\n';
    }
}