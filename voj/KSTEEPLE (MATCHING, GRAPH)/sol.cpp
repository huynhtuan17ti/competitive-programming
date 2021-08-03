/*
    http://www.usaco.org/current/data/sol_steeple.html
*/

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
const int MAXN = 255;

struct edge{
    ii p1, p2;
};

vector <edge> horiz, verti;

class MaximumMatching{
    private:
        vector <int> G[MAXN];
        int matchL[MAXN], matchR[MAXN], dist[MAXN];
        int n, m;
        bool BFS(){
            queue <int> Q;
            for(int i = 1; i <= n; i++){
                if(matchL[i] == 0){
                    dist[i] = 0;
                    Q.push(i);
                }else dist[i] = INT_MAX;
            }
            dist[0] = INT_MAX;
            while(!Q.empty()){
                int u = Q.front();
                Q.pop();
                if(u == 0)
                    continue;
                for(int v: G[u])
                    if(dist[matchR[v]] == INT_MAX){
                        dist[matchR[v]] = dist[u] + 1;
                        Q.push(matchR[v]);
                    }
            }
            return (dist[0] != INT_MAX);
        }
        bool DFS(int u){
            if(u == 0)
                return true;
            for(int v: G[u])
                if(dist[matchR[v]] == dist[u] + 1)
                    if(DFS(matchR[v])){
                        matchL[u] = v;
                        matchR[v] = u;
                        return true;
                    }
            dist[u] = INT_MAX;
            return false;
        }
    public:
        void init(int n, int m){
            this->n = n;
            this->m = m;
            fill(dist, dist+1+n, 0);
            fill(matchL, matchL+1+n, 0);
            fill(matchR, matchR+1+m, 0);
        }
        void add_edge(int u, int v){
            assert(u <= n && u >= 1);
            assert(v <= m && v >= 1);
            G[u].push_back(v);
        }
        int get(){
            int matching = 0;
            while(BFS()){
                for(int i = 1; i <= n; i++)
                    if(matchL[i] == 0 && DFS(i))
                        matching++;
            }
            return matching;
        }

};

bool is_insert(edge a, edge b){
    if(b.p1.fi <= a.p1.fi && a.p1.fi <= b.p2.fi && a.p1.se <= b.p1.se && b.p1.se <= a.p2.se)
        return true;
    return false;
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n; cin >> n;
    int tmp_n = n;
    while(n--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 > x2)
            swap(x1, x2);
        if(y1 > y2)
            swap(y1, y2);
        if(x1 == x2){
            verti.push_back({mp(x1, y1), mp(x2, y2)});
        }else
            horiz.push_back({mp(x1, y1), mp(x2, y2)});
    }
    int N = verti.size();
    int M = horiz.size();
    MaximumMatching maximumMatching;
    maximumMatching.init(N, M);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            if(is_insert(verti[i], horiz[j]))
                maximumMatching.add_edge(i+1, j+1);
    cout << tmp_n - maximumMatching.get() << '\n';
}