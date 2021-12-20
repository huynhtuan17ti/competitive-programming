#include <bits/stdc++.h>  
using namespace std;

const int MOD = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
#define mp make_pair
#define fi first
#define se second
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
const int MAXN = 5e5 + 5;
vii G[MAXN];

struct Path{
    int node, t;
    ll len;
    bool operator > (const Path &other) const{
        return len > other.len;
    };
};

int main(){
    io
    int n, m;
    cin >> n >> m;
    while(m--){
        int u, v, c;
        cin >> u >> v >> c;
        G[u].push_back({v, c});
    }
    auto dijktra = [&](int u) -> ll{
        const ll inf = 1e15;
        vector <vector <ll>> len(n+1, vector <ll>(2, inf));
        priority_queue <Path, vector <Path>, greater <Path>> pq;
        len[u][0] = 0;
        pq.push({u, 0, len[u][0]});

        while(!pq.empty()){
            Path u = pq.top();
            pq.pop();

            if(u.len != len[u.node][u.t])
                continue;

            for(ii v: G[u.node])
                if(u.t == 0){
                    if(len[v.fi][0] > len[u.node][u.t] + v.se){
                        len[v.fi][0] = len[u.node][u.t] + v.se;
                        pq.push({v.fi, 0, len[v.fi][0]});
                    }
                    if(len[v.fi][1] > len[u.node][u.t] + v.se/2){
                        len[v.fi][1] = len[u.node][u.t] + v.se/2;
                        pq.push({v.fi, 1, len[v.fi][1]});
                    }
                }else{
                    if(len[v.fi][1] > len[u.node][u.t] + v.se){
                        len[v.fi][1] = len[u.node][u.t] + v.se;
                        pq.push({v.fi, 1, len[v.fi][1]});
                    }
                }
        }
        return len[n][1];
    };
    cout << dijktra(1) << '\n';
}