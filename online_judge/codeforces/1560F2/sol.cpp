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

int get_bit(int val, int id){
    return (val >> id)&1;
}

int k;
int ans = 0;

void Try(int pos, string n, int cur_val, int state, bool is_upper){
    if(ans != 0)
        return;
    if(__builtin_popcount(state) > k)
        return;
    if(pos == n.size()){
        //cout << state << ' ' << __builtin_popcount(state) << '\n';
        ans = cur_val;
        return;
    }
    if(is_upper){
        for(int digit = 0; digit < 10; digit++){
            Try(pos+1, n, cur_val*10 + digit, (state|(1<<digit)), is_upper);
        }
    }
    else{
        int cur_digit = n[pos] - '0';
        for(int digit = cur_digit; digit < 10; digit++){
                Try(pos+1, n, cur_val*10 + digit, (state|(1<<digit)), (digit > cur_digit));
        }
    }
}

void solve(){
    string n;
    cin >> n >> k;
    ans = 0;
    Try(0, n, 0, 0, false);
    cout << ans << '\n';
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