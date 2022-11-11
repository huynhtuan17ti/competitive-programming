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
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
const int MAXN = 2e5 + 5;

template <typename T>
class FenwickTree{
private:
    vector <T> bit;
    int n;
public:
    FenwickTree(int _n): n(_n){
        bit.resize(n+1);
    }

    void update(int id, T val) {
        assert(id > 0);
        while (id <= n) {
            bit[id] += val;
            id += id&(-id);
        }
    }

    T get(int id){
        T ans{};
        while(id >= 1){
            ans += bit[id];
            id -= id&(-id); 
        }
        return ans;
    }
};

FenwickTree<int> fenw(MAXN);

vector<int> G[MAXN];
int subtree[MAXN];
bool processed[MAXN];

int get_subtree_size(int u, int pa = 0) {
    int &res = subtree[u];
    res = 1;
    for(int v: G[u])
        if(!processed[v] && v != pa)
            res += get_subtree_size(v, u);
    return res;        
}

ll ans = 0;
int k1, k2;
int mx_depth = 0;
int cnt[MAXN];

int get_centroid(int desired, int u, int pa = 0) {
    for(int v: G[u])
        if(!processed[v] && v != pa && subtree[v] >= desired)
            return get_centroid(desired, v, u);
    return u;
}

void calc_cnt(int u, int pa, bool fill, int depth = 1) {
    if(depth > k2) return;
    mx_depth = max(mx_depth, depth);
    if(fill) {
        cnt[depth]++;
        fenw.update(depth+1, 1);
    }
    else {
        ans += fenw.get(k2 - depth + 1);
        if(k1 - 1 - depth >= 0)
            ans -= fenw.get(k1 - 1 - depth + 1);
    }
    for(int v: G[u])
        if(!processed[v] && v != pa) {
            calc_cnt(v, u, fill, depth + 1);
        }
}

void centroid_decomp(int u) {
    int centroid = get_centroid(get_subtree_size(u) >> 1, u);
    processed[centroid] = true;
    mx_depth = 0;
    for(int v: G[centroid])
        if(!processed[v]) {
            calc_cnt(v, centroid, false);            
            calc_cnt(v, centroid, true);
        }
    // reset
    for(int depth = 1; depth <= mx_depth; depth++)
        fenw.update(depth+1, -cnt[depth]);
    fill(cnt+1, cnt+1+mx_depth, 0);
    for(int v: G[centroid])
        if(!processed[v])
            centroid_decomp(v);
}

int main(){
    io
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int n;
    cin >> n >> k1 >> k2;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cnt[0] = 1;
    fenw.update(0 + 1, cnt[0]);
    centroid_decomp(1);
    cout << ans << '\n';
}