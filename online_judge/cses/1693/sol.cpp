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

vector <int> G[MAXN];

int main(){
    io
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int n, m; cin >> n >> m;
    vector <int> inDeg(n+1), outDeg(n+1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        inDeg[v]++;
        outDeg[u]++;
    }

    if(outDeg[1] != inDeg[1] + 1 || inDeg[n] != outDeg[n] + 1)
        return cout << "IMPOSSIBLE", 0;
    
    for(int i = 2; i < n; i++)
        if(inDeg[i] != outDeg[i])
            return cout << "IMPOSSIBLE", 0;
    
    vector <int> ans;
    stack <int> st;
    st.push(1);
    while(!st.empty()){
        int u = st.top();
        if(G[u].empty()){
            ans.push_back(u);
            st.pop();
        }else{
            int v = G[u].back(); G[u].pop_back();
            st.push(v);
        }
    }

    if(ans.size() != m+1)
        return cout << "IMPOSSIBLE", 0;
    
    reverse(ans.begin(), ans.end());
    for(int u: ans)
        cout << u << ' ';
}