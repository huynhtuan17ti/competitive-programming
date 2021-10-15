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
 

int main(){
    io
    int n, x;
    cin >> n >> x;
    map <ll, int> M;
    ll sum = 0;
    M[sum]++;
    ll res = 0;
    for(int i = 1; i <= n; i++){
        int v; cin >> v;
        sum += v;
        // S[i] - S[j] = x => S[i] - x = S[j]
        res += M[sum - x];
        M[sum]++;
    }
    cout << res << '\n';
}