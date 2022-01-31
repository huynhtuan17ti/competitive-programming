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
const int MAXN = 500005;

int main(){
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    io
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    int maxValue = 0;
    for(int &x: a){
        cin >> x;
        maxValue = max(maxValue, x);
    }

    auto check = [&](ll val)->bool{
        ll cur = 0;
        int cnt = 1;
        for(int i = 0; i < n; i++){
            cur += a[i];
            if(cur > val){
                cnt++;
                cur = a[i];
            }
        }
        return (cnt <= k);
    };

    ll L = maxValue, R = 1e15;
    while(L <= R){
        ll mid = (L+R) >> 1;
        if(check(mid))
            R = mid - 1;
        else L = mid + 1;
    }

    cout << R+1 << '\n';
}