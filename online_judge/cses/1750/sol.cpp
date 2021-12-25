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
const int MAXD = 30;
int parent[MAXN][MAXD];

int main(){
    io
    //freopen("test.inp", "r", stdin);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        int t;
        cin >> t;
        parent[i][0] = t;
    }
    
    for(int j = 1; j < MAXD; j++)
        for(int i = 1; i <= n; i++)
            parent[i][j] = parent[parent[i][j-1]][j-1];

    auto jump =[&](int x, int k) -> int{
        for(int bit = 0; bit < MAXD; bit++)
            if((k>>bit)&1)
                x = parent[x][bit];
        return x;
    };

    while(q--){
        int x, k;
        cin >> x >> k;
        cout << jump(x, k) << '\n';
    }
}