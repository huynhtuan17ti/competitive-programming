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
const int MAXN = 2e5 + 5;
vector <int> G[MAXN];
bool vi[MAXN];

int num_vertex = 0;
int num_edge = 0;

void DFS(int u, int pre){
    num_vertex++;
    vi[u] = true;
    for(int v: G[u]){
        num_edge++;
        if(!vi[v]){
            DFS(v, u);
        }
    }
}

int main(){
    io
    int n, m;
    cin >> n >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    ll res = 1;
    for(int i = 1; i <= n; i++){
        if(!vi[i]){
            num_edge = 0;
            num_vertex = 0;
            DFS(i, 0);
            num_edge /= 2;
            if(num_vertex - num_edge == 0)
                res = (res*2)%MOD;
            else res = 0;
        }
    }
    cout << res << '\n';
}