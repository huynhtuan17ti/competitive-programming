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
 
void solve(){
    string a, b;
    int n;
    cin >> n;
    cin >> a >> b;
    int cnt1[2], cnt2[2];
    cnt1[0] = cnt1[1] = 0;
    cnt2[0] = cnt2[1] = 0;
    for(int i = 0; i < n; i++)
        if(a[i] == b[i])
            cnt1[a[i] - '0']++;
        else cnt2[a[i] - '0']++;
    
    int res = INT_MAX;
    if(cnt1[1] == cnt1[0] + 1)
        res = min(res, cnt1[0] + cnt1[1]);
    if(cnt2[1] == cnt2[0])
        res = min(res, cnt2[1] + cnt2[0]);
    if(res == INT_MAX)
        cout << -1 << '\n';
    else cout << res << '\n';
}
 
int main(){
    io
    int t; cin >> t;
    while(t--){
        solve();
    }
}