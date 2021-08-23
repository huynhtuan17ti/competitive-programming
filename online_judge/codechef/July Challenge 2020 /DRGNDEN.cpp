//Tuan Kkura
#include <bits/stdc++.h>

using namespace std;
#define PROB "text"
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef pair <int, int> ii;
typedef vector <ii> vii;
 
#define MAXN 200005
int n;
int h[MAXN], a[MAXN];
vector <int> DSK[2][MAXN];
int vi[MAXN];

void init(){
    stack <int> S;
    for(int i = 1; i <= n; i++){
        while(!S.empty() && h[S.top()] <= h[i])
            S.pop();
        if(!S.empty()){
            //cout << i << ' ' << S.top() << '\n';
            DSK[0][i].pb(S.top());
            DSK[0][S.top()].pb(i);
        }
        S.push(i);
    }
    while(!S.empty())   S.pop(); //clear stack
    for(int i = n; i >= 1; i--){
        while(!S.empty() && h[S.top()] <= h[i])
            S.pop();
        if(!S.empty()){
            //cout << i << ' ' << S.top() << '\n';
            DSK[1][i].pb(S.top());
            DSK[1][S.top()].pb(i);
        }
        S.push(i);
    }
}

int St[2][MAXN], Fi[2][MAXN], Num[2][MAXN], cnt = 0;
long long D[2][MAXN];

void DFS(int type, int u, int pre){
    vi[u] = 1;
    cnt ++;
    Num[type][u] = cnt;
    D[type][Num[type][u]] = D[type][Num[type][pre]] + a[u];
    St[type][u] = Fi[type][u] = cnt;
    for(int v : DSK[type][u])
        if(v != pre){
            DFS(type, v, u);
            Fi[type][u] = max(Fi[type][u], Fi[type][v]);
        }
}

long long bit[2][MAXN];

void update(int type, int id, long long val){
    while(id >= 1){
        bit[type][id] += val;
        id -= id&(-id);
    }
}

long long get(int type, int id){
    if(id == 0) return 0;
    long long res = 0;
    while(id <= n){
        res += bit[type][id];
        id += id&(-id);
    }
    return res;
}

int IT_max[4*MAXN];

void updateMax(int id, int l, int r, int i){
    if(i < l || r < i)  return;
 
    if(l == r && l == i){
        IT_max[id] = h[l];
        return;
    }
 
    int mid = (l+r) >> 1;
 
    updateMax(2*id, l, mid, i);
    updateMax(2*id+1, mid+1, r, i);
 
    IT_max[id] = max(IT_max[2*id], IT_max[2*id+1]);
}

int getMax(int id, int l, int r, int u, int v){
    if(v < l || r < u)  return 0;
 
    if(u <= l && r <= v){
        return IT_max[id];
    }
 
    int mid = (l+r) >> 1;
 
    int L = getMax(2*id, l, mid, u, v);
    int R = getMax(2*id+1, mid+1, r, u, v);
 
    return max(L, R);
}

int parent[2][MAXN];
int high[2][MAXN];
 
void DFSlevel(int type, int u, int pre)
{
    vi[u] = 1;
    for(int i = 0; i < DSK[type][u].size(); i++)
    {
        int w = DSK[type][u][i];
        if(w != pre)
        {
            parent[type][w] = u;
            high[type][w] = high[type][u] + 1;
            DFSlevel(type, w, u);
        }
    }
}

int R[2][MAXN][50];
 
void Make_RMQ(int type)
{
    for(int i = 1; i <= n; i++)
    {
        R[type][i][0] = parent[type][i];
    }
 
    for(int j = 1; j <= log2(n); j++)
    {
        for(int i = 1; i <= n; i++)
        {
            R[type][i][j] = R[type][R[type][i][j-1]][j-1];
        }
    }
}

int lca(int type, int u, int v)
{
    if(high[type][u] < high[type][v]) swap(u, v);
 
    for(int i = log2(high[type][u]); i >= 0; i--)
    {
        if(high[type][u] - (1<<i) >= high[type][v])
            u = R[type][u][i];
    }
 
    if(u == v)  return u;
 
    for(int i = log2(high[type][u]); i >=0; i--)
    {
        if(R[type][u][i] != 0 && R[type][u][i] != R[type][v][i])
        {
            u = R[type][u][i];
            v = R[type][v][i];
        }
    }
 
    return parent[type][u];
}

int main(){
    int q; cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> h[i];
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    init();

    for(int i = 1; i <= n; i++)
        if(!vi[i])
            DFS(0, i, 0);
    cnt = 0;
    fill(vi+1, vi+1+n, 0);
    for(int i = 1; i <= n; i++)
        if(!vi[i])
            DFS(1, i, 0);

    fill(vi+1, vi+1+n, 0);
    for(int i = 1; i <= n; i++)
        if(!vi[i])
            DFSlevel(0, i, 0);
    
    fill(vi+1, vi+1+n, 0);
    for(int i = 1; i <= n; i++)
        if(!vi[i]){
            //cout << i << '\n';
            DFSlevel(1, i, 0);
        }
    
    Make_RMQ(0); Make_RMQ(1);
    for(int i = 1; i <= n; i++){
        //cout << Num[0][i] << ' ' << D[0][Num[0][i]] << '\n'; 
        update(0, Num[0][i], D[0][Num[0][i]]);
        update(0, Num[0][i]-1, -D[0][Num[0][i]]);
        update(1, Num[1][i], D[1][Num[1][i]]);
        update(1, Num[1][i]-1, -D[1][Num[1][i]]);
    }
    //cout << get(0, Num[0][1]) << '\n';
    for(int i = 1; i <= n; i++)
        updateMax(1, 1, n, i);
    while(q--){
        int t, b, c;
        cin >> t >> b >> c;
        if(t == 1){
            //cout << St[0][b] << ' ' << Fi[0][b] << '\n';
            update(0, Fi[0][b], -a[b] + c);
            update(0, St[0][b]-1, a[b] - c);
            update(1, Fi[1][b], -a[b] + c);
            update(1, St[1][b]-1, a[b] - c);
            a[b] = c;
        }else{
            if(b == c){
                cout << a[b] << '\n';
                continue;
            }
            int Max = getMax(1, 1, n, min(b, c)+1, max(b, c)-1);
            if(Max >= max(h[b], h[c]) || h[b] <= h[c]){
                cout << -1 << '\n';
                continue;
            }
            if(b < c){
                int cha = lca(0, b, c);
                //cout << cha << '\n';
                //cout << get(0, Num[0][b]) << '\n';
                long long res = get(0, Num[0][b]) + get(0, Num[0][c])
                                - get(0, Num[0][cha])
                                - get(0, Num[0][parent[0][cha]]);
                cout << res << '\n';
            }else{
                int cha = lca(1, b, c);
                //cout << get(0, Num[1][b]) << '\n';
                long long res = get(1, Num[1][b]) + get(1, Num[1][c])
                                - get(1, Num[1][cha]) 
                                - get(1, Num[1][parent[1][cha]]);
                cout << res << '\n';
            }

        }
    }
}