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
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int t;
    cin >> t;
    for(int iTest = 1; iTest <= t; iTest++){
        int C = 1e6, M = 1e6, Y = 1e6, K = 1e6;
        for(int i = 1; i <= 3; i++){
            int c, m, y, k;
            cin >> c >> m >> y >> k;
            C = min(C, c);
            M = min(M, m);
            Y = min(Y, y);
            K = min(K, k);
        }
        cout << "Case #" << iTest << ": ";
        int p = C + M + Y + K - 1e6;
        if(p < 0){
            cout << "IMPOSSIBLE" << '\n';
            continue;
        }
        int s = min(C, p);
        C -= s; p -= s;
        s = min(M, p);
        M -= s; p -= s;
        s = min(Y, p);
        Y -= s; p -= s;
        s = min(K, p);
        K -= s; p -= s; 
        
        cout << C << ' ' << M << ' ' << Y << ' ' << K << '\n';
    }
}