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

void solve(){
    int n;
    cin >> n;
    vector <int> a;
    for(int i = 0; i < (1<<n); i++){
        int x; cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    if(a.size() == 1){
        cout << "YES" << '\n';
        return;
    }
    if(a.size() == 2){
        if(a[1] - a[0] == 1)
            cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }else{
        cout << "NO" << '\n';
    }
}

int main(){
    io
    int t; cin >> t;
    while(t--){
        solve();
    }
}