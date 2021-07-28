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

const int esp = 1e-8;
const ld pi = 4.0*atan(1.0);
const ld e = 2.71828182845904523536;

ll F(ll n){
    return (ll) floor(1. + log10(pi*n*2)/2 + log10((ld)n/e)*n);
}

void solve(int N){
    double sum = 0;
    vector <int> res;
    for(int i = 1; ceil(sum) <= N; i++){
        sum += log10(i);
        if(abs(ceil(sum) - N) <= esp){
            res.push_back(i);
        }
    }
    if(res.size() == 0)
        cout << "NO" << '\n';
    else{
        cout << res.size() << '\n';
        for(int u: res)
            cout << u << " ";
    }
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int N; cin >> N;
    if(N <= 500){
        solve(N);
        return 0;
    }
    ll l = 0, r = 1e9;
    while(l <= r){
        ll mid = (l+r) >> 1;
        if(F(mid) <= N){
            l = mid + 1;
        }else r = mid - 1;
    }
    int ans = l - 1;
    //cout << fixed << setprecision(5) << F(5505207) << '\n';
    //cout << fixed << setprecision(5) << F(ans) << '\n';
    if(F(ans) == N)
        cout << 1 << '\n' << ans << '\n';
    else{
        cout << "NO" << '\n';
    }
}