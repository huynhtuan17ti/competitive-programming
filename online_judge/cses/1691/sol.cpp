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

vii G[MAXN];

int main(){
    io
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back({v, i});
        G[v].push_back({u, i});
    }
    for(int i = 1; i <= n; i++)
        if(G[i].size() & 1)
            return cout << "IMPOSSIBLE" << '\n', 0;
    vector <int> vi(m+1);
    stack <int> st;
    st.push(1);
    vector <int> path;
    while(!st.empty()){
        int u = st.top();
        bool f = 0;
        while(!G[u].empty()){
            auto [v, i] = G[u].back();
            G[u].pop_back();
            if(!vi[i]){
                st.push(v);
                vi[i] = 1;
                f = 1;
                break;
            }
        }
        if(!f){
            path.push_back(u);
            st.pop();
        }
    }
    if(path.size() != m+1)
        return cout << "IMPOSSIBLE" << '\n', 0;
    for(int v: path)
        cout << v << ' ';
}