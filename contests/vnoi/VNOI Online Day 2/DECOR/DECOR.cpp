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

typedef pair <int, int> ii;
typedef vector <ii> vii;
#define fi first
#define se second
#define mp make_pair
#define PROB "DECOR"
#define MAXN 500005

string s;
int vi[MAXN];
int cnt_comp = 0;
int comp[MAXN], val[MAXN];
vector <int> G[MAXN];
vector <int> DSK[MAXN];
int pos_i[MAXN], pos_j[MAXN];

void DFS(int u){
    comp[u] = cnt_comp;
    val[cnt_comp] += (s[u] == '1');
    vi[u] = 1;
    for(int v: DSK[u])
        if(!vi[v])
            DFS(v);
}

bool check(int n, int k, int len, ii &res){
    fill(pos_i+1, pos_i+1+cnt_comp, -1);
    fill(pos_j+1, pos_j+1+cnt_comp, -1);
    int num_valid = 0;
    FOR(i, 1, n){
        int num = comp[i];
        num_valid -= min(val[num], pos_i[num] - pos_j[num]);
        if(pos_i[num]+1 < G[num].size() && G[num][pos_i[num]+1] <= i)
            pos_i[num]++;
        num_valid += min(val[num], pos_i[num] - pos_j[num]);
        //cout << num_valid << '\n';
        if(i >= len){
            int j = i - len;
            num = comp[j];
            if(j > 0){
                num_valid -= min(val[num], pos_i[num] - pos_j[num]);
                if(pos_j[num]+1 < G[num].size() && G[num][pos_j[num]+1] <= j)
                    pos_j[num]++;
                num_valid += min(val[num], pos_i[num] - pos_j[num]);
            }
            if(num_valid + k >= len){
                res = {j+1, i};
                return true;
            }
        }
    }
    return false;
}

int main(){
    _io
    freopen(PROB".inp", "r", stdin);
    freopen(PROB".out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    cin >> s;
    s = " " + s;
    while(m--){
        int u, v;
        cin >> u >> v;
        DSK[u].pb(v);
        DSK[v].pb(u);
    }
    FOR(i, 1, n)
        if(!vi[i]){
            cnt_comp ++;
            DFS(i);
        }
    FOR(i, 1, n){
        G[comp[i]].pb(i);
    }
    ii res;
    int l = 1, r = n;
    while(l <= r){
        int mid = (l+r) >> 1;
        if(check(n, k, mid, res)){
            l = mid+1;
        }else r = mid-1;
    }
    if(l-1 == 0)
        cout << -1;
    else{
        res = {0, 0};
        check(n, k, l-1, res);
        cout << res.fi << ' ' << res.se << '\n';
    }
}
