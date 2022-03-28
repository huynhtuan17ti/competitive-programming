#include <bits/stdc++.h>  
using namespace std;
 
const int MOD = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
#define mp make_pair
#define fi first
#define se second
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
const int MAXN = 5e5 + 5;
 
int main(){
    io
    int n; cin >> n;
    vii a;
    map <int, vector <int>> M;
    int cur = 0;
    for(int i = 1; i <= n; i++){
        int u, v;
        cin >> u >> v;
        a.push_back({u, v});
        M[u].push_back(v);
        cur = max(cur, u);
    }
    for(int i = 1; i <= cur; i++)
        sort(M[i].begin(), M[i].end(), greater <int>());
    ll ans = 0;
    priority_queue <int> pq;
    for(int i = cur; i >= 1; i--){
        for(int v: M[i])
            pq.push(v);
        if(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans << '\n';
}