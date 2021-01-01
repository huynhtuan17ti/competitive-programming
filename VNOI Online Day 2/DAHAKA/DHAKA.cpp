/* Tuan Kkura */
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define base 31
#define MOD 1e9+7
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORs(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, a, b) for(int i = a; i < b; i++)
#define __FOR(i, a, b, k) for(int i = a; i <= b; i+= k)
#define __REP(i, a, b, k) for(int i = a; i < b; i+= k)
#define pb push_back
#define _io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

typedef pair <ll, ll> ii;
typedef vector <ii> vii;
#define fi first
#define se second
#define mp make_pair
#define PROB "DHAKA"
#define MAXN 400005

int val[MAXN];
vii DSK[MAXN];
ll len[MAXN][33];

struct node{
    ll u, state;
    ll len;
};

bool operator > (const node &A, const node &B){
    return A.len > B.len;
}

void dijktra(int n, int k){
    FOR(i, 1, n)
        FOR(j, 0, (1<<k)-1)
            len[i][j] = LLONG_MAX;
    len[1][val[1]] = 0;
    priority_queue <node, vector <node>, greater <node>> Q;
    Q.push({1, val[1], 0});
    while(!Q.empty()){
        node u = Q.top();
        Q.pop();
        for(ii v: DSK[u.u]){
            int next_state = (u.state | val[v.fi]);
            if(len[v.fi][next_state] > u.len + v.se){
                len[v.fi][next_state] = u.len + v.se;
                Q.push({v.fi, next_state, len[v.fi][next_state]});
            }
        }
    }
}

int get_bit(int val, int id){
    return (val >> id)&1;
}

int main(){
    _io
    freopen(PROB".inp", "r", stdin);
    freopen(PROB".out", "w", stdout);
    int n, m, k, l; cin >> n >> m >> k >> l;
    FOR(i, 1, n){
        int s; cin >> s;
        while(s--){
            int x;
            cin >> x;
            val[i] += (1<<(x-1));
        }
    }
    while(m--){
        int u, v, c;
        cin >> u >> v >> c;
        DSK[u].pb({v, c});
        DSK[v].pb({u, c});
    }
    dijktra(n, k);
    ll res = LLONG_MAX;
    FOR(i, 0, (1<<k)-1){
        int cnt = 0;
        REP(j, 0, k)
            cnt += get_bit(i, j);
        if(cnt == l)
            res = min(res, len[n][i]);
    }
    cout << ((res == LLONG_MAX)? -1: res);
}
