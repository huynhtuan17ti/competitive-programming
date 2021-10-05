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
const int MAXN  = 1005;
int par[MAXN];
vector <int> G[MAXN];
vector <int> s;

void DFS(int u, int pre){
    s.push_back(u);
    for(int v: G[u])
        if(v != pre){
            par[v] = u;
            DFS(v, u);
        }
}

int main(){
    io
    int n; cin >> n;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    DFS(1, 0);
    
    auto query = [&](int l, int r){
        set <int> S;
        for(int i = l; i <= r; i++){
            int u = s[i];
            S.insert(par[u]);
            S.insert(u);
        }
        cout << "? " << S.size() << ' ';
        for(auto it: S)
            cout << it << ' ';
        cout << '\n';
        cout.flush();
        int ans; cin >> ans;
        return ans;
    };

    int Max = query(1, n-1);
    int res = 0;
    int l = 1, r = n-1;
    while(l < r){
        int mid = (l+r) >> 1;
        if(query(l, mid) == Max){
            r = mid;
            res = s[mid];
        }else{
            l = mid + 1;
            res = s[mid+1];
        }
    }
    cout << "! " << par[res] << ' ' << res << '\n';
}