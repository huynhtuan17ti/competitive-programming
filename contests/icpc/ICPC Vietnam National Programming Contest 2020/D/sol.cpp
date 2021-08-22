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
const int MAXN = 3e5 + 5;

vii G[MAXN];

class LongestDiameter{
    public:
    int n;
    vector <ll> h;
    vector <int> trace;
    LongestDiameter(int n){
        this->n = n;
        h.resize(n+1);
        trace.resize(n+1);
    }
    void DFS(int u, int pre){
        for(ii v: G[u])
            if(v.fi != pre){
                h[v.fi] = h[u] + v.se;
                trace[v.fi] = u;
                DFS(v.fi, u);
            }
    }
    vector <int> get(ll &len){
        DFS(1, 0);
        int max_node = max_element(h.begin(), h.end()) - h.begin();
        h[max_node] = 0;
        trace[max_node] = 0;
        DFS(max_node, 0);
        max_node = max_element(h.begin(), h.end()) - h.begin();
        len = h[max_node];
        vector <int> path;
        for(int v = max_node; v > 0; v = trace[v]){
            path.push_back(v);
        }
        reverse(path.begin(), path.end());
        return path;
    }
};

class DpSubTree{
    public:
    int n;
    vector <ll> dp1, dp2;
    vector <ll> d_tree;
    DpSubTree(int n){
        this->n = n;
        dp1.resize(n+1);
        dp2.resize(n+1);
        d_tree.resize(n+1);
    }
    void reset(){
        fill(dp1.begin(), dp1.end(), 0);
        fill(dp2.begin(), dp2.end(), 0);
        fill(d_tree.begin(), d_tree.end(), 0);
    }
    void DFS(int u, int pre){
        ll firstmax = -1, secondmax = -1;
        for(ii v: G[u])
            if(v.fi != pre){
                DFS(v.fi, u);

                if(firstmax == -1)
                    firstmax = dp1[v.fi] + v.se;
                else if(dp1[v.fi] + v.se >= firstmax){
                    secondmax = firstmax;
                    firstmax = dp1[v.fi] + v.se;
                }else if(dp1[v.fi] + v.se > secondmax)
                    secondmax = dp1[v.fi] + v.se;
            }
        if(firstmax != -1)
            dp1[u] = firstmax;

        if(secondmax != -1)
            dp2[u] = firstmax + secondmax;
    }

    void update(int u, int pre){
        d_tree[u] = max(dp1[u], dp2[u]);
        for(ii v: G[u])
            if(v.fi != pre){
                update(v.fi, u);
                d_tree[u] = max(d_tree[u], d_tree[v.fi]);
            }
    }

    vector <ll> get(int start){
        reset();
        DFS(start, 0);
        update(start, 0);
        return d_tree;
    }
};

void solve(int n){
    for(int i = 1; i <= n; i++)
        G[i].clear();

    for(int i = 2; i <= n; i++){
        int x, l; cin >> x >> l;
        G[x].push_back({i, l});
        G[i].push_back({x, l});
    }
    LongestDiameter lgd(n);

    vector <bool> in_diameter(n+1);
    ll diameter;
    vector <int> lg_path = lgd.get(diameter);
    for(int u: lg_path)
        in_diameter[u] = 1;

    DpSubTree dpsubtree(n);

    vector <ll> dpL = dpsubtree.get(lg_path[0]);
    vector <ll> dpR = dpsubtree.get(lg_path[lg_path.size()-1]);

    ll res = LLONG_MAX;

    for(int u: lg_path){
        for(ii v: G[u])
            if(!in_diameter[v.fi])
                res = min(res, abs(diameter - dpL[v.fi]));
    }

    for(int i = 1; i < lg_path.size(); i++)
        res = min(res, abs(dpR[lg_path[i-1]] - dpL[lg_path[i]]));

    cout << res << '\n';
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n;
    while(cin >> n){
        if(n == 0)
            return 0;
        solve(n);
    }
}