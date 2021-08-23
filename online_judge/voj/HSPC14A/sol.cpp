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

int step = 0;
int F(int x, int y){
    if(y != 0)
        step += x/y - (y == 1);
    if(y == 0)
        return x;
    return F(y, x%y);
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int t; cin >> t;
    while(t--){
        int N; cin >> N;
        int res = INT_MAX;
        for(int i = 1; i <= N; i++){
            if(__gcd(N, i) == 1){
                step = 0;
                F(N, i);
                res = min(res, step);
            }
        }
        cout << res << '\n';
    }
}