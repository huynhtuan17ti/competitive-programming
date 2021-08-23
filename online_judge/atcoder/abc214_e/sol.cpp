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
const int MAXN = 2e5+5;
 
void solve(){
    vii seg;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        seg.push_back({l, r});
    }
    sort(seg.begin(), seg.end(), [](const ii &A, const ii &B){
        if(A.fi == B.fi)
            return A.se < B.se;
        return A.fi < B.fi;
    });
 
    bool res = true;
    int j = 0;
    int cur = 0;
 
    priority_queue <int, vector <int>, greater <int>> Q;
    while(1){
        if(j == n && Q.size() == 0)
            break;
        if(Q.size() == 0 && cur < seg[j].fi)
            cur = seg[j].fi;
        
        while(j < n && seg[j].fi <= cur){
            Q.push(seg[j].se);
            j++;
        }
        //cout << cur << ' ' << Q.top() << '\n';
        if(cur <= Q.top()){
            Q.pop();
            cur++;
        }else{
            res = false;
            break;
        }
    }
    if(res)
        cout << "Yes" << '\n';
    else cout << "No" << '\n';
 
}
 
int main(){
    io
    int t; cin >> t;
    while(t--){
        solve();
    }
}