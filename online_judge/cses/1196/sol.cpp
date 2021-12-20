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

int main(){
    io
    //freopen("test.inp", "r", stdin);
    int n, m, k;
    cin >> n >> m >> k;
    while(m--){
        int u, v, c;
        cin >> u >> v >> c;
        G[u].push_back({v, c});
    }

    auto dijktra = [&](int u) -> vector <ll>{
        const ll inf = 1e15;
        vector <vector <ll>> len(n+1, vector <ll>(k, inf));
        priority_queue <pll, vector <pll>, greater <pll>> pq;
        len[u][0] = 0;
        pq.push({0, u});
        while(!pq.empty()){
            pll u = pq.top();
            pq.pop();

            if(len[u.se][k-1] < u.fi)
                continue;

            for(ii v: G[u.se])
                if(len[v.fi][k-1] > u.fi + v.se){
                    len[v.fi][k-1] = u.fi + v.se;
                    sort(len[v.fi].begin(), len[v.fi].end());

                    pq.push({u.fi + v.se, v.fi});
                }
        }
        return len[n];
    };

    vector <ll> len = dijktra(1);
    for(ll u: len)
        cout << u << ' ';
}