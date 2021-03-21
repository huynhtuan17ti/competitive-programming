/* Tuan Kkura */
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define base 31
#define MOD 1e9+7
#define pb push_back
#define _io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

typedef pair <int, int> ii;
typedef vector <ii> vii;
#define fi first
#define se second
#define mp make_pair
#define PROB "text"
#define MAXN 1005

int u[MAXN][MAXN], d[MAXN][MAXN];
int l[MAXN][MAXN], r[MAXN][MAXN];

int a[MAXN][MAXN];

int main(){
    _io
    int T; cin >> T;
    for(int iTest = 1; iTest <= T; iTest++){
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                cin >> a[i][j];
        for(int i = 0; i <= n+1; i++){
            fill(u[i], u[i]+2+m, 0);
            fill(d[i], d[i]+2+m, 0);
            fill(l[i], l[i]+2+m, 0);
            fill(r[i], r[i]+2+m, 0);
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(a[i][j] == 0){
                    l[i][j] = 0;
                    u[i][j] = 0;
                }else {
                    l[i][j] = l[i][j-1] + 1;
                    u[i][j] = u[i-1][j] + 1;
                }
            }
        }
        for(int i = n; i >= 1; i--){
            for(int j = m; j >= 1; j--){
                if(a[i][j] == 0){
                    r[i][j] = 0;
                    d[i][j] = 0;
                }else {
                    r[i][j] = r[i][j+1] + 1;
                    d[i][j] = d[i+1][j] + 1;
                }
            }
        }

        ll res = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++){
                res += max(0, min(l[i][j]-1, u[i][j]/2-1));
                res += max(0, min(l[i][j]/2-1, u[i][j]-1));

                res += max(0, min(l[i][j]-1, d[i][j]/2-1));
                res += max(0, min(l[i][j]/2-1, d[i][j]-1));

                res += max(0, min(r[i][j]-1, u[i][j]/2-1));
                res += max(0, min(r[i][j]/2-1, u[i][j]-1));

                res += max(0, min(r[i][j]-1, d[i][j]/2-1));
                res += max(0, min(r[i][j]/2-1, d[i][j]-1));
            }
        cout << "Case #" << iTest << ": " << res << '\n';
    }
}
