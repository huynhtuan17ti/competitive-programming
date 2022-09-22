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
const int MAXN = 25000;
const int MAXV = 1e7;

int block_size;
int ST[MAXN+5], EN[MAXN+5];
vector<int> nodes;

int c[MAXN+5];
vector<int> primeFactors[MAXN + 5];
vector<int> G[MAXN];

int factor[MAXV + 5];

inline void buildSieve(){
    for(int i = 2; i <= MAXV; i++)
        factor[i] = i;
    for(int i = 4; i <= MAXV; i+=2)
        factor[i] = 2;
    for(int i = 3; i*i <= MAXV; i++)
        if(factor[i] == i)
            for(int j = i*i; j <= MAXV; j+=i)
                if(factor[j] == j)
                    factor[j] = i;
}

vector<int> getPrimes(int val){
    vector<int> primes;
    while(val > 1){
        int p = factor[val];
        primes.push_back(p);
        while(val % p == 0)
            val /= p;
    }
    return primes;
}

/* ============== LCA section =============== */

void DFS(int u){
    nodes.push_back(u);
    ST[u] = nodes.size()-1;
    for(int v: G[u])
        if(!ST[v])
            DFS(v);
    nodes.push_back(u);
    EN[u] = nodes.size()-1;
}

int R[MAXN][50];
int h[MAXN];

class LCA{
public:
    LCA(int n){
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

/* ================= Mo's section ================== */

struct Query{
    int l, r, pos;
};

int curAns = 0, cntNodes = 0;
int cnt_id[MAXN + 5];
int cnt[MAXV + 5];

inline void singleUpdate(int coeff, vector<int> primes){
    for(int val: primes){
        if(val > 0){
            curAns += coeff * (cnt[val] - (coeff < 0));
            cnt[val] += coeff;
        }else{
            val = -val;
            curAns -= coeff * (cnt[val] - (coeff < 0));
            cnt[val] += coeff;
        }
    }
}

inline void del(int pos){
    if(pos == 0)
        return;

    pos = nodes[pos];
    cnt_id[pos]--;
    if(cnt_id[pos] == 1){
        cntNodes++;
        singleUpdate(1, primeFactors[pos]);
    }
    else{
        cntNodes--;
        singleUpdate(-1, primeFactors[pos]);
    }
}

inline void add(int pos){
    if(pos == 0)
        return;

    pos = nodes[pos];
    cnt_id[pos]++;
    if(cnt_id[pos] == 1){
        cntNodes++;
        singleUpdate(1, primeFactors[pos]);
    }
    else{
        cntNodes--;
        singleUpdate(-1, primeFactors[pos]);
    }
}

inline void update(int &L, int &R, int qL, int qR){
    while (L > qL) add(--L);
    while (R < qR) add(++R);

    while (L < qL) del(L++);
    while (R > qR) del(R--);
}


int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    buildSieve();
    
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> c[i];
        vector<int> curPrimes = getPrimes(c[i]);
        int n = curPrimes.size();
        for(int state = 1; state < (1<<n); state++){
            int cntBit = 0, curVal = 1;
            for(int i = 0; i < n; i++)
                if((state>>i)&1){
                    cntBit++;
                    curVal *= curPrimes[i];
                }
            if(cntBit % 2 == 1)
                primeFactors[i].push_back(curVal);
            else
                primeFactors[i].push_back(-curVal);
        }
    }

    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    nodes.push_back(0); // to 1-base
    DFS(1);
    vector<Query> Q;

    for(int i = 0; i < q; i++){
        int u, v;
        cin >> u >> v;
        Q.push_back({u, v, i});
    }

    block_size = 1000;
    sort(Q.begin(), Q.end(), [](const Query &A, const Query &B){
        return (ST[A.l]/block_size != ST[B.l]/block_size)? (ST[A.l]/block_size < ST[B.l]/block_size) : (ST[A.r] < ST[B.r]);
    });
    vector<ll> res;
    res.resize((int)Q.size());

    LCA lca(n);

    int L = 1, R = 0;
    for(Query q: Q){
        int u = q.l, v = q.r;
        if(ST[u] > ST[v])   swap(u, v); // assume that S[u] <= S[v]
        int parent = lca.get(u, v);

        bool specialCase = 0;
        if(parent == u){
            int qL = ST[u], qR = ST[v];
            update(L, R, qL, qR);
        }else{
            int qL = EN[u], qR = ST[v];
            update(L, R, qL, qR);
            singleUpdate(1, primeFactors[parent]);
            cntNodes++;
            specialCase = 1;
        }
        res[q.pos] = 1LL*cntNodes*(cntNodes-1)/2 - curAns;
        
        if(specialCase){
            singleUpdate(-1, primeFactors[parent]);
            cntNodes--;
            specialCase = 0;
        }
    }
    for(int u: res)
        cout << u << '\n';
}