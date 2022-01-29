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

int main(){
    io
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int n, t;
    cin >> n >> t;
    vector <int> a(n);
    for(int &x: a)
        cin >>  x;

    auto check = [&](ll val)-> bool{
        ll total = 0;
        for(int x: a){
            total += (val/x);
            if(total >= t)
                return true;
        }
        return (total >= t);
    };

    ll l = 1, r = 1e18;
    while(l <= r){
        ll mid = (l+r) >> 1;
        if(check(mid))
            r = mid - 1;
        else l = mid + 1;
    }
    cout << r + 1 << '\n';
}