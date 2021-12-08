#include <bits/stdc++.h>  
using namespace std;

const int MOD = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
#define mp make_pair
#define fi first
#define se second
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
const int MAXID = 7e5 + 5;
const int MAXN = 3e4 + 5;
const ll inf = 1e15;

int idNode[MAXID][2];
int treeIndex[MAXN];
vii G[MAXID];

int curId = 0;

void genGraph(int id, int l, int r){
    if(l == r){
        treeIndex[l] = id;
        idNode[id][0] = idNode[id][1] = ++curId;
        return;
    }

    idNode[id][0] = ++curId;
    idNode[id][1] = ++curId;

    int mid = (l+r) >> 1;
    genGraph(2*id, l, mid);
    genGraph(2*id+1, mid+1, r);

    G[idNode[id][0]].push_back({idNode[2*id][0], 0});
    G[idNode[id][0]].push_back({idNode[2*id+1][0], 0});

    G[idNode[2*id][1]].push_back({idNode[id][1], 0});
    G[idNode[2*id+1][1]].push_back({idNode[id][1], 0});
}

void addEdge(int id, int l, int r, int u, int v, int direct, int node, int weight){
    if(v < l || r < u)
        return;
    if(u <= l && r <= v){
        if(direct == 0)
            G[idNode[id][1]].push_back({idNode[treeIndex[node]][0], weight});
        else
            G[idNode[treeIndex[node]][1]].push_back({idNode[id][0], weight});
        return;
    }
    int mid = (l+r) >> 1;
    addEdge(2*id, l, mid, u, v, direct, node, weight);
    addEdge(2*id+1, mid+1, r, u, v, direct, node, weight);
}

tuple <vector <ll>, vector <ll>> dijktra(int maxNode, int start){
    vector <ll> len(maxNode+1, inf);
    vector <ll> ways(maxNode+1, 0);
    len[start] = 0;
    ways[start] = 1;
    priority_queue <ii, vii, greater <ii>> pq;
    pq.push({0, start});

    while(!pq.empty()){
        ii u = pq.top();
        pq.pop();

        if(len[u.se] != u.fi)
            continue;
        
        for(ii v: G[u.se]){
            assert(0 <= v.fi && v.fi <= curId);
            if(len[v.fi] == len[u.se] + v.se){
                ways[v.fi] = (ways[v.fi] + ways[u.se])%MOD;                
            }else
            if(len[v.fi] > len[u.se] + v.se){
                len[v.fi] = len[u.se] + v.se;
                ways[v.fi] = ways[u.se];
                pq.push({len[v.fi], v.fi});
            }
        }
    }

    return {len, ways};
}

ll dp[(1<<20)][21];
ll f[(1<<20)][21];

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int m, n, k;
    cin >> n >> m >> k;

    genGraph(1, 1, n);

    vector <int> a;
    for(int i = 0; i < k; i++){
        int x; cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end(), greater <int>());
    if(a[k-1] != 1){
        k++;
        a.push_back(1);
    }

    while(m--){
        int t;
        cin >> t;
        if(t == 1){
            int u, v, w;
            cin >> u >> v >> w;
            G[idNode[treeIndex[u]][0]].push_back({idNode[treeIndex[v]][0], w});
        }
        if(t == 2){
            int l, r, u, w;
            cin >> l >> r >> u >> w;
            addEdge(1, 1, n, l, r, 0, u, w);
        }
        if(t == 3){
            int u, l, r, w;
            cin >> u >> l >> r >> w;
            addEdge(1, 1, n, l, r, 1, u, w);
        }
    }

    vector <vector <ll>> len(k, vector <ll>(k));
    vector <vector <ll>> ways(k, vector <ll>(k));

    for(int i = 0; i < k; i++){
        int u = a[i];
        tuple <vector <ll>, vector <ll>> ans = dijktra(curId, idNode[treeIndex[u]][0]);
        
        vector <ll> curLen = get<0>(ans);
        vector <ll> curWays = get<1>(ans);

        for(int j = 0; j < k; j++){
            int v = a[j];
            len[i][j] = curLen[idNode[treeIndex[v]][0]];
            ways[i][j] = curWays[idNode[treeIndex[v]][0]];
        }
    }

    int node1 = k-1;
    k--;
    //assert(k < 20);
    int MAX_STATE = (1<<k)-1;

    for(int i = 0; i < k; i++){
        dp[(1<<i)][i] = len[node1][i];
        f[(1<<i)][i] = ways[node1][i];
    }

    auto getBit = [&](int val, int id) -> bool{
        return (val >> id)&1;
    };

    for(int state = 1; state <= MAX_STATE; state++){
        for(int i = 0; i < k; i++)
            if(getBit(state, i)){
                int preState = state - (1<<i);
                if(preState > 0)
                    dp[state][i] = inf;
                for(int j = 0; j < k; j++)
                    if(getBit(preState, j)){
                        if(dp[state][i] == dp[preState][j] + len[j][i]){
                            f[state][i] += f[preState][j] * ways[j][i]%MOD;
                            f[state][i] %= MOD;
                        }
                        if(dp[state][i] > dp[preState][j] + len[j][i]){
                            dp[state][i] = dp[preState][j] + len[j][i];
                            f[state][i] = f[preState][j] * ways[j][i]%MOD;
                        }
                    }
            }
    }

    ll resLen = inf, resWays = 0;
    for(int i = 0; i < k; i++){
        if(resLen == dp[MAX_STATE][i] + len[i][node1]){
            resLen = dp[MAX_STATE][i] +  len[i][node1];
            resWays += f[MAX_STATE][i] * ways[i][node1]%MOD;
            resWays %= MOD;
        }
        if(resLen > dp[MAX_STATE][i] + len[i][node1]){
            resLen = dp[MAX_STATE][i] + len[i][node1];
            resWays = f[MAX_STATE][i] * ways[i][node1]%MOD;
        }
    }
    if(resLen == inf)
        cout << -1 << '\n';
    else
        cout << resLen << ' ' << resWays << '\n';
}