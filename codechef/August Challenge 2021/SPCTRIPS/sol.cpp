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
 
int solve(int n){
    int res = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            int k = i%j;
            if(k > 0 && j % k ==0 && k <= n)
                res++;
        }
    return res;
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    for(int i = 2; i <= 30; i++)
        cout << i << ": " << solve(i) << '\n';
}