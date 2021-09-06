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
const int MAXN = 5e5 + 5;
 
void print(multiset <int> Q){
    for(int u: Q)
        cout << u << ' ';
    cout << '\n';
}
 
int get(int x){
    int ans = 1;
    while(x > 10){
        ans *= 10;
        x /= 10;
    }
    return ans;
}
 
void solve(){
    int s;
    int n;
    cin >> s >> n;
    multiset <int> res;
    if(n == 1){
        cout << s << '\n';
        return;
    }
    int pow10 = 1;
    while(s > 0){
        int p = s%10;
        s /= 10;
        while(p > 0){
            p--;
            res.insert(pow10);
            if(res.size() == n-1 && s*pow10*10 + p*pow10 > 0){
                res.insert(s*pow10*10 + p*pow10);
                print(res);
                return;
            }
        }
        pow10 *= 10;
    }
    int cnt = 0;
    while(res.size() + cnt < n){
        int p = *(res.begin());
        if(p > 1){
            res.erase(res.begin());
            int cof = get(p);
            while(p >= cof){
                if(res.size() + cnt == n-1 && p > 0){
                    res.insert(p);
                    while(cnt--){
                        res.insert(1);
                    }
                    print(res);
                    return;
                }
                res.insert(cof);
                p -= cof;
            }
        }else{
            cnt++;
            res.erase(res.begin());
        }
    }
    
}
 
int main(){
    io
 
    int t; cin >> t;
    while(t--){
        solve();
    }
}