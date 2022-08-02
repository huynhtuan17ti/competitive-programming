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

vector <int> G[MAXN];
int numChild[MAXN];
ll sumDownPath[MAXN];

void DFS(int u, int pre){
    numChild[u] += 1;
    for(int v: G[u])
        if(v != pre){
            DFS(v, u);
            numChild[u] += numChild[v];
            sumDownPath[u] += sumDownPath[v] + numChild[v];
        }
}

ll sumUpPath[MAXN];

void DFS2(int u, int pre){
    if(pre > 0){
        sumUpPath[u] += (sumUpPath[pre] + sumDownPath[pre] - sumDownPath[u] - numChild[u]);
        sumUpPath[u] += (numChild[1] - numChild[u]);
    }
    for(int v: G[u])
        if(v != pre){
            DFS2(v, u);
        }
}

int main(){
    io
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);
    int n; cin >> n;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    DFS(1, 0);
    DFS2(1, 0);
    for(int i = 1; i <= n; i++)
        cout << sumUpPath[i] + sumDownPath[i] << " \n"[i == n];
}