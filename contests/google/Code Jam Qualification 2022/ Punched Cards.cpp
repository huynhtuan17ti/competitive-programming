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
    int t; cin >> t;
    for(int iTest = 1; iTest <= t; iTest++){
        int r, c;
        cin >> r >> c;
        string res = "";
        for(int i = 1; i <= r*2+1; i++){
            res += ((i%2 == 1)? "+" : "|");
            for(int j = 1; j <= c; j++){
                res += ((i%2 == 0)? ".|" : "-+");
            }
            res += '\n';
        }
        res[0] = res[1] = '.';
        res[2*c + 2] = '.';
        cout << "Case #" << iTest << ":" << '\n';
        cout << res;
    }
}