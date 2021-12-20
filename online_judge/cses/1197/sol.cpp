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
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
const int MAXN = 5e5 + 5;
const ll inf = 1e15;

int main(){
    io
    //freopen("test.inp", "r", stdin);
    int n, m;
    cin >> n >> m;
    typedef pair <ii, int> edge;
    vector <edge> edges;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({mp(a, b), c});
    }
    auto bellmanFord = [&](int start){
        vector <ll> len(n+1, inf);
        vector <int> parent(n+1);
        len[start] = 0;
        int last = 0;
        for(int i = 0; i < n; i++){
            last = 0;
            for(edge e: edges){
                int u = e.fi.fi, v = e.fi.se;
                int c = e.se;
                if(len[v] > len[u] + c){
                    len[v] = len[u] + c;
                    parent[v] = u;
                    last = v;
                }
            }
        }
        if(last == 0) // not find cycle
            cout << "NO" << '\n';
        else{
            for(int i = 1; i <= n; i++)
                last = parent[last];
            cout << "YES" << '\n';
            vector <int> cycle; 
            for(int u = last;; u = parent[u]){
                cycle.push_back(u);
                //cerr << u << '\n';
                if(u == last && cycle.size() > 1)
                    break;
            }
            reverse(cycle.begin(), cycle.end());
            for(int u: cycle)
                cout << u << ' ';
        }
    };
    bellmanFord(1);
}