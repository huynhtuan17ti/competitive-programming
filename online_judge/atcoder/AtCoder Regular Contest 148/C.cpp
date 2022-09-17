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
int order = 0;
int uOrder[MAXN];

void DFS(int u){
    uOrder[u] = order++;
    for(int v: G[u])
        DFS(v);
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    vector <int> p(n+1);
    for(int i = 2; i <= n; i++){
        cin >> p[i];
        G[p[i]].push_back(i);
    }
    vector <int> state(n+1);
    while(q--){
        int m; cin >> m;
        vector <int> s(m);
        for(int &u: s){
            cin >> u;
            state[u] = 1;
        }
        sort(s.begin(), s.end(), [](const int &A, const int &B){
            return uOrder[A] < uOrder[B];
        });
        int ans = n-1;
        for(int u: s){
            ans -= (int)G[u].size();
            if(state[p[u]] == 0)
                ans -= 1;
            else ans += 1;
        }
        cout << (n-1) - ans << '\n';
        for(int u: s)
            state[u] = 0;
    }
}