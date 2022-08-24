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

template <typename T>
class FenwickTree{
private:
    vector <T> fenw;
    int n;
public:
    FenwickTree(int _n){
        this->n = _n;
        fenw.resize(n+1);
    }

    void update(int id, T val) {
        while (id <= n) {
            fenw[id] += val;
            id += id&(-id);
        }
    }

    T get(int id){
        T ans{};
        while(id >= 1){
            ans += fenw[id];
            id -= id&(-id); 
        }
        return ans;
    }
};

vector <int> G[MAXN];
int v[MAXN];
int order[MAXN][2], curOrder = 0;
int vertexMap[MAXN];

void DFS(int u, int pre){
    order[u][0] = ++curOrder;
    vertexMap[curOrder] = u;
    for(int v: G[u]){
        if(v != pre)
            DFS(v, u);
    }
    order[u][1] = curOrder;
}

int main(){
    io
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    FenwickTree<ll> fenw(n);
    DFS(1, 0);
    for(int i = 1; i <= n; i++){
        fenw.update(i, v[vertexMap[i]]);
    }
    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int s, x;
            cin >> s >> x;
            fenw.update(order[s][0], - v[s] + x);
            v[s] = x;
        }else{
            int s; cin >> s;
            cout << fenw.get(order[s][1]) - fenw.get(order[s][0] - 1) << '\n';
        }
    }
}