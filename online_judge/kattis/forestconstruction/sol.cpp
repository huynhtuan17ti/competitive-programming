#include <bits/stdc++.h>  
using namespace std;
 
constexpr int MOD = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define mp make_pair
#define fi first
#define se second
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};
constexpr int MAXN = 3e5 + 5;

int main() {
    io
    int V;
    cin >> V;
    vector<int> d(V+1);
    vector<int> non_leaf_nodes;
    vector<int> leaf_nodes;
    for(int i = 1; i <= V; ++i) {
        cin >> d[i];
        if(d[i] > 1)
            non_leaf_nodes.push_back(i);
        else if(d[i] == 1)
            leaf_nodes.push_back(i);
    }
    int sum_deg = accumulate(d.begin(), d.end(), 0);
    if(sum_deg % 2 > 0)
        return cout << "IMPOSSIBLE" << '\n', 0;

    int k = 0;
    for(auto u: non_leaf_nodes)
        k += d[u];
    k -= 2 * max(0, (int)non_leaf_nodes.size() - 1);

    int m = leaf_nodes.size();
    if (k > m) 
        return cout << "IMPOSSIBLE" << '\n', 0;

    if ((m - k) % 2 > 0)
        return cout << "IMPOSSIBLE" << '\n', 0;

    vii edges;
    while(m > k) {
        edges.emplace_back(leaf_nodes[m-1], leaf_nodes[m-2]);
        m -= 2;
    }
    queue<int> q;
    for(auto u: non_leaf_nodes) {
        if(q.empty()) {
            for(int i = 0; i < d[u]; ++i) q.push(u);
            continue;
        }
        int v = q.front();
        q.pop();
        edges.emplace_back(v, u); 
        for(int i = 0; i < d[u]-1; ++i) q.push(u);
    }
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        edges.emplace_back(leaf_nodes[m-1], u);
        --m;
    }

    cout << "POSSIBLE" << '\n';
    for(auto [u, v]: edges)
        cout << u << ' ' << v << '\n';
}
