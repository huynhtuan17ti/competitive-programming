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
const int MAXN = 2e5;
const int sqrt_size = 450;
int block_size;
int a[MAXN+5];
int ST[MAXN+5], EN[MAXN+5];
vector <int> nodes;
int cur = 1;
vii G[MAXN+5];
vector <int> S;

void compress(int n){
    for(int i = 1; i <= n; i++){
        S.push_back(a[i]+1);
        S.push_back(a[i]);
    }
    S.push_back(0);
    
    sort(S.begin(), S.end());
    S.resize(unique(S.begin(), S.end()) - S.begin());

    for(int i = 1; i <= n; i++)
        a[i] = lower_bound(S.begin(), S.end(), a[i]) - S.begin();
}

void DFS(int u){
    nodes.push_back(u);
    ST[u] = nodes.size()-1;
    for(ii v: G[u])
        if(!ST[v.fi]){
            a[v.fi] = v.se;
            DFS(v.fi);
        }
    nodes.push_back(u);
    EN[u] = nodes.size()-1;
}

int R[MAXN+5][50];
int h[MAXN+5];

class LCA{
    public:
        void initialize(int n){
            DFS_level(1, 0);
            for(int j = 1; j <= log2(n); j++)
                for(int i = 1; i <= n; i++)
                    R[i][j] = R[R[i][j-1]][j-1];
        }
        void DFS_level(int u, int pre){
            for(ii v: G[u])
                if(v.fi != pre){
                    h[v.fi] = h[u] + 1;
                    R[v.fi][0] = u;
                    DFS_level(v.fi, u);
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

int block[sqrt_size][sqrt_size];
int uniq_value[sqrt_size];

void update(int val, int occur){
    int cur_block = val/sqrt_size;
    int cur_pos = val%sqrt_size;

    if(!block[cur_block][cur_pos])
        uniq_value[cur_block]++;
    block[cur_block][cur_pos] += occur;
    if(!block[cur_block][cur_pos])
        uniq_value[cur_block]--;
}

int cnt_id[MAXN+5], cnt_num[MAXN+5];

// remove a[pos]
void del(int pos){
    if(pos == 0)
        return;

    pos = nodes[pos];
    if(pos == 1)
        return;
    int val = a[pos];

    cnt_id[pos]--;
    
    if(cnt_id[pos] == 1){
    	if(cnt_num[val] == 0)
            update(val, 1);
    	cnt_num[val]++;
    }
    else{
    	cnt_num[val]--;
    	if(cnt_num[val] == 0)
	        update(val, -1);
    }
    
}

// add a[pos]
void add(int pos){
    if(pos == 0)
        return;

    pos = nodes[pos];
    if(pos == 1)
        return;
    int val = a[pos];

    cnt_id[pos]++;
    
    if(cnt_id[pos] == 1){
    	if(cnt_num[val] == 0)
        	update(val, 1);
    	cnt_num[val]++;
    }
    else{
    	cnt_num[val]--;
    	if(cnt_num[val] == 0)
	        update(val, -1);
    }
}

int calc(int top_node){
    if(top_node > 1){
        cnt_num[a[top_node]]--;
        if(cnt_num[a[top_node]] == 0)
            update(a[top_node], -1);
    }
    int cur_block = 0;
    while(uniq_value[cur_block] == sqrt_size)
        cur_block++;

    int pos_inside_block = 0;
    while(block[cur_block][pos_inside_block])
        pos_inside_block++;

    if(top_node > 1){
        if(cnt_num[a[top_node]] == 0)
            update(a[top_node], 1);
        cnt_num[a[top_node]]++;
    }

    return cur_block*sqrt_size + pos_inside_block;
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
        return (ST[A.l]/block_size != ST[B.l]/block_size)? (ST[A.l]/block_size < ST[B.l]/block_size) : (ST[A.r] < ST[B.r]);
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
        int top_node = -1;
        if(parent == u){
            int qL = ST[u], qR = ST[v];
            top_node = nodes[ST[u]];
            update(L, R, qL, qR);
        }else{
            int qL = EN[u], qR = ST[v];
            update(L, R, qL, qR);
        }
        res[q.pos] = calc(top_node);
    }
    return res;
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i < n; i++){
        int u, v, c;
        cin >> u >> v >> c;
        G[u].push_back({v, c});
        G[v].push_back({u, c});
    }
    
    nodes.push_back(0); // to 1-base
    DFS(1);
    
    compress(n);
    
    vector <query> Q;
    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        Q.push_back({l, r, i});
    }

    vector <int> res = MoQueries(n, Q);
    for(int ans: res)
        cout << ans << '\n';
}