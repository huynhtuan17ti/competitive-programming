#include <bits/stdc++.h>  
 
using namespace std;
 
const int MOD = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
#define mp make_pair
#define fi first
#define se second
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int MAXN = 4e5 + 5;
const ll INF = 1e15;

int n, m, d;
vii out[MAXN];
int weight[MAXN];
vii G[MAXN];
ll dist[MAXN];

int get_dir(ii edge, int x){
    if(x == edge.fi)
        return 0;
    return 1;
}

int get_idx(int id_edge, int dir){
    return id_edge + m*dir;
}

int other(int u, int v, int x){
    return (u^v^x);
}

void build_new_graph(vector <ii> edges){
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i].fi;
        int v = edges[i].se;
        int c = weight[i];
        int tmp[] = {u, v};
        for(int dir = 0; dir <= 1; dir++){
            int cur_id = get_idx(i, dir);
            int other_node = other(u, v, tmp[dir]);
            int nxt = lower_bound(out[other_node].begin(), out[other_node].end(), mp((ll)c + d, (ll)-1)) - out[other_node].begin();
            if(nxt >= 0 && nxt < out[other_node].size()){
                int id_edge = out[other_node][nxt].se;
                ii edge = edges[id_edge];
                int nxt_id = get_idx(id_edge, get_dir(edge, other_node));
                G[cur_id].push_back({nxt_id, weight[id_edge]});
            }
        }
    }

    for(int u = 1; u <= n; u++){
        int pre = -1;
        int pre_weight = 0;
        for(ii v: out[u]){
            int cur_id = get_idx(v.se, get_dir(edges[v.se], u));
            if(pre >= 0){
                G[pre].push_back({cur_id, weight[v.se] - pre_weight});
            }
            pre = cur_id;
            pre_weight = weight[v.se];
        }
    }
}

void djiktra(vector <ii> edges){
    for(int i = 0; i <= 2*m; i++)
        dist[i] = INF;
    priority_queue <ii, vii, greater<ii>> Q;
    for(int i = 0; i < m; i++){
        if(edges[i].fi == 1){
            int cur_id = get_idx(i, 0);
            dist[cur_id] = weight[i];
            Q.push({weight[i], cur_id});
        }
        if(edges[i].se == 1){
            int cur_id = get_idx(i, 1);
            dist[cur_id] = weight[i];
            Q.push({weight[i], cur_id});
        }
    }

    while(!Q.empty()){
        ii u = Q.top();
        Q.pop();
        if(dist[u.se] != u.fi)
            continue;
        for(ii v: G[u.se]){
            if(dist[v.fi] > dist[u.se] + v.se){
                dist[v.fi] = dist[u.se] + v.se;
                Q.push({dist[v.fi], v.fi});
            }
        }
    }
    ll result = INF;
    for(int i = 0; i < m; i++){
        if(edges[i].se == n){
            int cur_id = get_idx(i, 0);
            result = min(result, dist[cur_id]);
        }
        if(edges[i].fi == n){
            int cur_id = get_idx(i, 1);
            result = min(result, dist[cur_id]);
        }
    }
    if(result == INF)
        cout << -1 << '\n';
    else cout << result << '\n';
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    cin >> n >> m >> d;
    vii edges;
    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        out[u].push_back({c, i});
        out[v].push_back({c, i});
        weight[i] = c;
        edges.push_back({u, v});
    }
    for(int i = 1; i <= n; i++)
        sort(out[i].begin(), out[i].end());

    build_new_graph(edges);
    djiktra(edges);
}