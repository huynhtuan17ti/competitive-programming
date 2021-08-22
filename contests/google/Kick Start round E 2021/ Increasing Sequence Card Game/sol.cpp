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
const int MAXN  = 1e7;
const double GAP = 0.57721566990018758;
ld ans[MAXN+5];

int main(){
    io
    int t; cin >> t;
    for(int i = 1; i <= MAXN; i++)
        ans[i] = ans[i-1] + (ld)1/i;
    for(int iTest = 1; iTest <= t; iTest++){
        ll N;
        cin >> N;
        ld res;
        if(N <= MAXN)
            res = ans[N];
        else
            res = log(N) + GAP;
        cout << "Case #" << iTest << ": ";
        cout << fixed << setprecision(10) << res << '\n';
    }
}