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
const int MAXN = 1e5;
int block_size;
int a[MAXN+5];
int ST[MAXN+5], EN[MAXN+5];
vector <int> nodes;
int cur = 1;

vector <int> G[MAXN+5];

void compress(int n){
    vector <int> S;
    for(int i = 1; i <= n; i++)
        S.push_back(a[i]);
    S.push_back(INT_MIN);
    sort(S.begin(), S.end());
    S.resize(unique(S.begin(), S.end()) - S.begin());
    for(int i = 1; i <= n; i++)
        a[i] = lower_bound(S.begin(), S.end(), a[i]) - S.begin();
}

void DFS(int u){
    nodes.push_back(u);
    ST[u] = nodes.size()-1;
    for(int v: G[u])
        if(!ST[v]){
            //cout << u << ' ' << v << '\n';
            DFS(v);
        }
    nodes.push_back(u);
    EN[u] = nodes.size()-1;
}

int R[MAXN][50];
int h[MAXN];

class LCA{
    public:
        void initialize(int n){
            DFS_level(1, 0);
            for(int j = 1; j <= log2(n); j++)
                for(int i = 1; i <= n; i++)
                    R[i][j] = R[R[i][j-1]][j-1];
        }
        void DFS_level(int u, int pre){
            for(int v: G[u])
                if(v != pre){
                    h[v] = h[u] + 1;
                    R[v][0] = u;
                    DFS_level(v, u);
                }
        }
        // get parent of (u, v)
        int get(int u, int v){
            if(h[u] < h[v])
                swap(u, v);
            for(int i = log2(h[u]); i >= 0; i--)
                if(h[u] - (1<<i) >= h[v])
                    u = R[u][i];
            if(u == v)
                return u;
            for(int i = log2(h[u]); i >= 0; i--)
                if(R[u][i] != 0 && R[u][i] != R[v][i]){
                    u = R[u][i];
                    v = R[v][i];
                }
            return R[u][0];
        }
};

struct query{
    int l, r, pos;
};

int cur_ans = 0;
int cnt_id[MAXN], cnt_val[MAXN];

// remove a[pos]
void del(int pos){
    if(pos == 0)
        return;

    pos = nodes[pos];
    int val = a[pos];

    cnt_id[pos]--;
    if(cnt_id[pos] == 1)
        cnt_val[val]++;
    else cnt_val[val]--;

    if(cnt_val[val] == 1 && cnt_id[pos] == 1)
        cur_ans++;

    if(cnt_val[val] == 0 && cnt_id[pos] == 0)
        cur_ans--;
}

// add a[pos]
void add(int pos){
    if(pos == 0)
        return;

    pos = nodes[pos];
    int val = a[pos];

    cnt_id[pos]++;
    if(cnt_id[pos] == 1)
        cnt_val[val]++;
    else cnt_val[val]--;

    if(cnt_val[val] == 1 && cnt_id[pos] == 1)
        cur_ans++;

    if(cnt_val[val] == 0 && cnt_id[pos] == 2)
        cur_ans--;   
}

void update(int &L, int &R, int qL, int qR){
    while (L > qL) add(--L);
    while (R < qR) add(++R);

    while (L < qL) del(L++);
    while (R > qR) del(R--);
}

vector <int> MoQueries(int n, vector <query> Q){
    block_size = sqrt((int)nodes.size());
    sort(Q.begin(), Q.end(), [](const query &A, const query &B){
        return (ST[A.l]/block_size != ST[B.l]/block_size)? (ST[A.l]/block_size < ST[B.l]/block_size) : (A.r < B.r);
    });
    vector <int> res;
    res.resize((int)Q.size());

    LCA lca;
    lca.initialize(n);

    int L = 1, R = 0;
    for(query q: Q){
        int u = q.l, v = q.r;
        if(ST[u] > ST[v])   swap(u, v); // assume that S[u] <= S[v]
        int parent = lca.get(u, v);

        if(parent == u){
            int qL = ST[u], qR = ST[v];
            update(L, R, qL, qR);
        }else{
            int qL = EN[u], qR = ST[v];
            update(L, R, qL, qR);
            if(cnt_val[a[parent]] == 0)
                res[q.pos] += 1;
        }
        
        res[q.pos] += cur_ans;
    }
    return res;
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    compress(n);
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    nodes.push_back(0); // to 1-base
    DFS(1);
    
    vector <query> Q;
    for(int i = 0; i < m; i++){
        int l, r;
        cin >> l >> r;
        Q.push_back({l, r, i});
    }

    vector <int> res = MoQueries(n, Q);
    for(int ans: res)
        cout << ans << '\n';
}