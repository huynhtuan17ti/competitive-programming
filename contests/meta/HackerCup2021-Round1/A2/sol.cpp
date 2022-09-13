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

// F, X left
// F, O right

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int t; cin >> t;
    for(int iTest = 1; iTest <= t; iTest++){
        int n; cin >> n;
        string S;
        cin >> S;
        int pre[3];
        pre[0] = pre[1] = -1;
        ll res = 0;
        for(int i = 0; i < n; i++){
            if(S[i] == 'F') continue;
            int x = ((S[i] == 'O')? 1: 0);
            if(pre[x] < pre[1-x])
                res = (res + 1LL*(pre[1-x] + 1)*(n - i)%MOD)%MOD;
            pre[x] = i;
        }
        cout << "Case #" << iTest << ": " << res << '\n';
    }
}