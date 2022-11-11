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
const int MAXN = 5e5 + 5;

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
int k;
int mx_depth = 0;
// fill cnt with 1
int cnt[200001]{1};

int get_centroid(int desired, int u, int pa = 0) {
    for(int v: G[u])
        if(!processed[v] && v != pa && subtree[v] >= desired)
            return get_centroid(desired, v, u);
    return u;
}

void calc_cnt(int u, int pa, bool fill, int depth = 1) {
    if(depth > k) return;
    mx_depth = max(mx_depth, depth);
    if(fill)
        cnt[depth]++;
    else {
        ans += cnt[k - depth];
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
    fill(cnt + 1, cnt + 1 + mx_depth, 0);
    for(int v: G[centroid])
        if(!processed[v])
            centroid_decomp(v);
}

int main(){
    io
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int n;
    cin >> n >> k;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    centroid_decomp(1);
    cout << ans << '\n';
}