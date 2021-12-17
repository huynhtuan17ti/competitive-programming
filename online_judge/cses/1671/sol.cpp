#include <bits/stdc++.h>  
using namespace std;

const int MOD = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
#define mp make_pair
#define fi first
#define se second
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
const int MAXN = 5e5 + 5;
const ll inf = 1e14;
vii G[MAXN];

int main(){
    io
    int n, m;
    cin >> n >> m;
    while(m--){
        int u, v, c;
        cin >> u >> v >> c;
        G[u].push_back({v, c});
    }
    auto dijktra = [&](int u){
        vector <ll> len(n+1, inf);
        priority_queue <pll, vector <pll>, greater <pll>> pq;
        len[u] = 0;
        pq.push(mp(0, u));
        while(!pq.empty()){
            pll u = pq.top();
            pq.pop();
            if(len[u.se] != u.fi)
                continue;
            for(ii v: G[u.se]){
                if(len[v.fi] > len[u.se] + v.se){
                    len[v.fi] = len[u.se] + v.se;
                    pq.push(mp(len[v.fi], v.fi));
                }
            }
        }
        return len;
    };
    vector <ll> len = dijktra(1);
    for(int i = 1; i <= n; i++)
        cout << len[i] << ' ';
}