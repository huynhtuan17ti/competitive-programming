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
const int MAXN = 1e6;

vector <int> G[MAXN];
int num_child[MAXN];
int n;
string s;

void build(int u){
    if(G[u].size() == 0){
        num_child[u] = 1;
        return;
    }
    int L = G[u][0], R = G[u][1];
    build(L);
    build(R);
    if(s[u - n - 1] == '?')
        num_child[u] = num_child[L] + num_child[R];
    else if(s[u - n - 1] == '0'){
        num_child[u] = num_child[L];
    }else
        num_child[u] = num_child[R];
}

void update(int u, int x){
    if(u < x)
        return;
    if(u == x){
        int L = G[u][0], R = G[u][1];
        if(s[x - n - 1] == '?')
            num_child[u] = num_child[L] + num_child[R];
        else if(s[x - n - 1] == '0'){
            num_child[u] = num_child[L];
        }else
            num_child[u] = num_child[R];
        return;
    }
    int L = G[u][0], R = G[u][1];
    update(L, x);
    update(R, x);
    if(s[u - n - 1] == '?')
        num_child[u] = num_child[L] + num_child[R];
    else if(s[u - n - 1] == '0'){
        num_child[u] = num_child[L];
    }else
        num_child[u] = num_child[R];
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int k; cin >> k;
    n = (1<<k);
    cin >> s;
    queue <int> Q;
    for(int i = 1; i <= n; i++){
        Q.push(i);
    }
    int node = n;
    while(Q.size() >= 2){
        int u = Q.front();
        Q.pop();
        int v = Q.front();
        Q.pop();
        node++;
        //cout << node << ' ' << u << ' ' << v << '\n';
        G[node].push_back(u);
        G[node].push_back(v);
        Q.push(node);
    }
    build(node);
    int q; cin >> q;
    while(q--){
        int pos;
        char c;
        cin >> pos >> c;
        s[pos-1] = c;
        update(node, pos + n);
        cout << num_child[node] << '\n';
    }
}