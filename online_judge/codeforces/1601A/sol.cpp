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
#define MAXBIT 30

int get_bit(int val, int id){
    return (val >> id)&1;
}

void solve(){
    int n; cin >> n;
    vector <int> cnt(MAXBIT);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        for(int bit = 0; bit < MAXBIT; bit++)
            cnt[bit] += get_bit(x, bit);
    }
    vector <int> res;
    for(int i = 1; i <= n; i++){
        bool isDiv = true;
        for(int bit = 0; bit < MAXBIT; bit++)
            if(cnt[bit]%i > 0){
                isDiv = false;
                break;
            }
        if(isDiv)
            res.push_back(i);
    }
    for(int u: res)
        cout << u << ' ';
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