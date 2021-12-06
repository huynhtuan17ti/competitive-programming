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

int main(){
    io
    int n, m; cin >> n >> m;
    vector <vector <int>> sum(n+1, vector <int> (n+1));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            char x; cin >> x;
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + (x == '*');
        }
    auto get = [&](int x, int y, int u, int v) -> int{
        return sum[u][v] - sum[x-1][v] - sum[u][y-1] + sum[x-1][y-1];
    };

    while(m--){
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        cout << get(x, y, u, v) << '\n';
    }
}