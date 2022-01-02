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

vector <int> G[MAXN]; // graph storing
int cntDFS = 0; // DFS order
int st[MAXN], en[MAXN]; // the number of start and end in DFS order of a node.
int color[MAXN]; // input color
int pColor[MAXN]; // processed color (saving in DFS order)

void DFS(int u){
    st[u] = ++cntDFS;
    pColor[cntDFS] = color[u];
    for(int v: G[u])
        DFS(v);
    en[u] = cntDFS;
}

int block_size;

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    block_size = sqrt(n);
    for(int i = 2; i <= n; i++){
        int p; cin >> p;
        G[p].push_back(i);
    }
    for(int i = 1; i <= n; i++)
        cin >> color[i];

    DFS(1);

    vii queries; // [ans, index]
    int q; cin >> q;
    for(int i = 0; i < q; i++){
        int u; cin >> u;
        queries.push_back({u, i});
    }

    // mo algorithm
    sort(queries.begin(), queries.end(), [](const ii &A, const ii &B){
        return (st[A.fi]/block_size != st[B.fi]/block_size)? st[A.fi]/block_size < st[B.fi]/block_size : en[A.fi] < en[B.fi];
    });

    vector <int> cnt(m+1); // color counting
    int curAns = 0;

    auto del = [&](int pos){
        if(cnt[pColor[pos]] == 1)
            curAns--;
        if(cnt[pColor[pos]] == k+1)
            curAns++;
        cnt[pColor[pos]]--;
    };

    auto add = [&](int pos){
        if(cnt[pColor[pos]] == k)
            curAns--;
        if(cnt[pColor[pos]] == 0)
            curAns++;
        cnt[pColor[pos]]++;
    };

    vector <int> ans(q);
    int l = 1, r = 0;
    for(auto [u, id]: queries){
        int L = st[u], R = en[u];

        while (l > L) add(--l);
        while (r < R) add(++r);

        while (l < L) del(l++);
        while (r > R) del(r--);

        ans[id] = curAns;
    }

    for(auto u: ans)
        cout << u << '\n';
}