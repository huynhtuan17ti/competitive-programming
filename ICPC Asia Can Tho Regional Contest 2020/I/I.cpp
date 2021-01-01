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
#define PROB "text"
#define MAXN 500005

vii DSK[MAXN];

void dijktra(int n, ll Len[], ll Num[], int s){
    FOR(i, 1, n)
        Len[i] = LLONG_MAX;
    Len[s] = 0;
    priority_queue < ii, vii, greater <ii> > Q;
    Q.push({0, s});
    while(!Q.empty()){
        ii u = Q.top();
        Q.pop();
        if(Len[u.se] != u.fi)   continue;
        for(ii v : DSK[u.se]){
            if(Len[u.se] + v.se == Len[v.fi])
                Num[v.fi] += Num[u.se];
            else if(Len[u.se] + v.se < Len[v.fi]){
                Num[v.fi] = Num[u.se];
                Len[v.fi] = Len[u.se] + v.se;
                Q.push({Len[v.fi], v.fi});
            }
        }
    }
}

ll Len[2][2][MAXN];
ll Num[2][2][MAXN];

bool check_vertex(int u, int type, int t){
    if(Len[type][0][u] + Len[type][1][u] == Len[type][0][t])
        return true;
    return false;
}

bool needSwap(int u, int v, int d, int type, int t){
    if(Len[type][0][u] + d + Len[type][1][v] >
                 Len[type][0][v] + d + Len[type][1][u])
        return true;
    return false;
}

bool check_edge(int u, int v, int d, int type, int t){
    ll val = min(Len[type][0][u] + d + Len[type][1][v],
                 Len[type][0][v] + d + Len[type][1][u]);
    return (Len[type][0][t] == val);
}

bool check(ll LaS, ll LaT, ll LbS, ll LbT){
    if(LaT <= LbS || LbT <= LaS)
        return false;
    return true;
}

struct edge{
    int u, v, c;
};


int main(){
    _io
    int n, m;
    while(cin >> n >> m){
        if(n == 0 && m == 0)
            break;
        int hc, sc, hj, sj;
        cin >> hc >> sc >> hj >> sj;
        FOR(i, 1, n)
            DSK[i].clear();
        vector <edge> edges;
        while(m--){
            int u, v, l;
            cin >> u >> v >> l;
            DSK[u].pb({v, l});
            DSK[v].pb({u, l});
            edges.pb({u, v, l});
        }
        dijktra(n, Len[0][0], Num[0][0], hc);
        dijktra(n, Len[0][1], Num[0][1], sc);
        dijktra(n, Len[1][0], Num[1][0], hj);
        dijktra(n, Len[1][1], Num[1][1], sj);
        int res = 0;
        FOR(i, 1, n){
            if(check_vertex(i, 0, sc) && check_vertex(i, 1, sj) &&
               Len[0][0][i] == Len[1][0][i])
                res++;
        }
        bool Inf = false;
        for(edge e: edges){
            if(check_edge(e.u, e.v, e.c, 0, sc) && check_edge(e.u, e.v, e.c, 1, sj)){
                int Au = e.u, Av = e.v;
                int Bu = e.u, Bv = e.v;
                bool isSwap = needSwap(e.u, e.v, e.c, 0, sc);
                if(isSwap)  swap(Au, Av);
                isSwap = needSwap(e.u, e.v, e.c, 1, sj);
                if(isSwap)  swap(Bu, Bv);

                if(Au == Bu && Len[0][0][Au] == Len[1][0][Bu])
                    Inf = true;
                if(Av == Bu &&
                   check(Len[0][0][Au], Len[0][0][Av], Len[1][0][Bu], Len[1][0][Bv])){
                   res++;
                }
            }
        }
        if(check_vertex(sc, 1, sj) && Len[0][0][sc] < Len[1][0][sc])
            res++;
        if(check_vertex(sj, 0, sc) && Len[1][0][sj] < Len[0][0][sj])
            res++;
        if(Inf)
            cout << -1 << '\n';
        else cout << res << '\n';
    }
}