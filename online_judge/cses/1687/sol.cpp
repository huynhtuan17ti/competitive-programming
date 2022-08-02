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

int R[MAXN][30];

int main(){
    io
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);
    int n, q; cin >> n >> q;
    for(int i = 2; i <= n; i++){
        cin >> R[i][0];
    }
    for(int j = 1; (1<<j) <= n; j++)
        for(int i = 1; i <= n; i++)
            R[i][j] = R[R[i][j-1]][j-1];

    auto findKthBoss = [&](int u, int k) -> int{
        int tmp = k;
        for(int i = log2(k); i >= 0; i--)
            if(tmp - (1<<i) >= 0){
                u = R[u][i];
                tmp -= (1<<i);
            }
        return u;
    };

    while(q--){
        int x, k;
        cin >> x >> k;
        int kBoss = findKthBoss(x, k);
        if(kBoss == 0)
            cout << -1 << '\n';
        else cout << kBoss << '\n';
    }
}