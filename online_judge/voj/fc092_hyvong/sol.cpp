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
const int MAXN = 500;
const ll inf = 1e15;

struct Edge{
    int node;
    int len;
    int type;
};

vector <Edge> G[MAXN];

struct State{
    int cur;
    ll len;
    int num1, num2;
};

bool operator > (const State &A, const State &B){
    return A.len > B.len;
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n, m, k1, k2;
    cin >> n >> m >> k1 >> k2;
    for(int i = 0; i < m; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        G[a].push_back({b, c, d});
        G[b].push_back({a, c, d});
    }
    int s, t;
    cin >> s >> t;

    vector <vector <vector <ll>>> len(n+1, vector <vector <ll>> (k1+1, vector <ll> (k2+1, inf)));
    
    priority_queue <State, vector <State>, greater <State>> pq;
    len[s][0][0] = 0;
    pq.push({s, 0, 0, 0});

    while(!pq.empty()){
        State u = pq.top();
        pq.pop();

        if(u.len != len[u.cur][u.num1][u.num2])
            continue;

        for(Edge v: G[u.cur]){
            int typeD = v.type;
            if(typeD == 0){
                if(len[v.node][u.num1][u.num2] > len[u.cur][u.num1][u.num2] + v.len){
                    len[v.node][u.num1][u.num2] = len[u.cur][u.num1][u.num2] + v.len;
                    pq.push({v.node, len[v.node][u.num1][u.num2], u.num1, u.num2});
                }
            }
            if(typeD == 1 && u.num1+1 <= k1){
                if(len[v.node][u.num1+1][u.num2] > len[u.cur][u.num1][u.num2] + v.len){
                    len[v.node][u.num1+1][u.num2] = len[u.cur][u.num1][u.num2] + v.len;
                    pq.push({v.node, len[v.node][u.num1+1][u.num2], u.num1+1, u.num2});
                }
            }
            if(typeD == 2 && u.num2+1 <= k2){
                if(len[v.node][u.num1][u.num2+1] > len[u.cur][u.num1][u.num2] + v.len){
                    len[v.node][u.num1][u.num2+1] = len[u.cur][u.num1][u.num2] + v.len;
                    pq.push({v.node, len[v.node][u.num1][u.num2+1], u.num1, u.num2+1});
                }
            }
        }
    }

    if(len[t][k1][k2] == inf)
        cout << -1 << '\n';
    else
        cout << len[t][k1][k2] << '\n';
}