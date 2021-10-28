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
const int MAXN = 3e5 + 5;
int a[MAXN], b[MAXN];
int dist[MAXN][2], trace[MAXN][2];

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n; cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        cin >> b[i];
    
    for(int i = 0; i <= n; i++){
        dist[i][0] = dist[i][1] = INT_MAX;
        trace[i][0] = trace[i][1] = n+1;
    }
    dist[n][0] = 0;
    int maxU = n;
    queue <pair <int, int>> Q;
    for(Q.push({n, 0}); !Q.empty();){
        auto [u, t] = Q.front();
        Q.pop();
        if(t == 0){
            for(; maxU >= u - a[u]; maxU--){
                if(dist[maxU][1] <= dist[u][0] + 1)
                    continue;
                dist[maxU][1] = dist[u][0] + 1;
                trace[maxU][1] = u;
                Q.push({maxU, 1});

                if(maxU == 0){
                    u = maxU;
                    vector <int> ans;
                    int p = 0;
                    for(; u <= n; u = trace[u][p]){
                        if(p == 0)
                            ans.push_back(u);
                        p = 1 - p;
                    }
                    reverse(ans.begin(), ans.end());
                    cout << ans.size() << '\n';
                    for(int u: ans)
                        cout << u << ' ';
                    return 0;
                }
            }
        }else{
            int next_u = u + b[u];
            //cerr << next_u << '\n';
            if(dist[next_u][0] > dist[u][1]){
                dist[next_u][0] = dist[u][1];
                trace[next_u][0] = u;
                Q.push({next_u, 0});
            }
        }
    }
    cout << -1;
}