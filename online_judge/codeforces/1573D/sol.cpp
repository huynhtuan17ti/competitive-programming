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
const int MAXN  = 5e5 + 5;

int a[MAXN];

bool make_queries(vector <int> &res, int n, int pos1, int pos2){
    if((pos2 - pos1 + 1)%2 == 0){
        if(pos1 > 1 && a[pos1-1] == 0)
            pos1--;
        else if(pos2 < n && a[pos2+1] == 0)
            pos2++;
    }
    if((pos2 - pos1 + 1)%2 == 0)
        return false;
    for(int i = pos1; i < pos2; i += 2){
        res.push_back(i);
    }
    for(int i = pos2-4; i >= pos1; i -= 2){
        res.push_back(i);
    }
    for(int i = pos1; i <= pos2; i++)
        a[i] = 0;
    return true;
}

void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    vector <int> res;
    // remove adjective bit 1
    if((a[1]^a[2]^a[3]) == 0 && a[1]+a[2]+a[3] > 0){
        res.push_back(1);
        a[1] = a[2] = a[3] = 0;
    }
    if((a[n-2]^a[n-1]^a[n]) == 0 && a[n-2]+a[n-1]+a[n] > 0){
        res.push_back(n-2);
        a[n-2] = a[n-1] = a[n] = 0;
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++) cnt += (a[i] == 1);

    if(cnt%2 == 1 || cnt == n || (a[1] == 1 && a[n] == 1 && cnt == 2 && n%2 == 0)){
        cout << "NO" << '\n';
        return;
    }

    int pre = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] == 0)   continue;
        if(pre > 0){
            make_queries(res, n, pre, i);
            pre = 0;
        }else pre = i;
    }

    pre = 0;
    for(int i = n; i >= 1; i--){
        if(a[i] == 0)   continue;
        if(pre > 0){
            make_queries(res, n, i, pre);
            pre = 0;
        }else pre = i;
    }
    for(int i = 1; i <= n; i++){
        if(a[i] == 1){
            cout << "NO" << '\n';
            return;
        }
    }

    cout << "YES" << '\n';
    cout << res.size() << '\n';
    for(int u: res){
        cout << u << ' ';
    }
    if(res.size() > 0)
        cout << '\n';
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int t; cin >> t;
    while(t--){
        solve();
    }
}