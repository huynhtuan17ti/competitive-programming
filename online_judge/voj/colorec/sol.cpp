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
const int MAXN = 400 + 5;

int C[MAXN][MAXN];

int main(){
    io
    int n; cin >> n;
    for(int i = 0; i <= 400; i++)
        fill(C[i], C[i]+401, -1);
    for(int i = 1; i <= n; i++){
        int x, y, c;
        cin >> x >> y >> c;
        c--;
        C[x + 200][y + 200] = c;
    }
    ll ans = 0;
    for(int u = 0; u <= 400; u++)
        for(int v = u+1; v <= 400; v++){
            vector <int> s(1<<5);
            for(int col = 0; col <= 400; col++){
                if(C[u][col] == -1 || C[v][col] == -1)
                    continue;
                int state = (1<<C[u][col]) + (1<<C[v][col]);
                ans += s[(1<<4)-1-state];
                s[state]++;
            }
        }
    cout << ans << '\n';
}