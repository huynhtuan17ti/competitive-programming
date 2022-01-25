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
    int n; cin >> n;
    vector <int> a(n);
    for(int &x: a)
        cin >> x;
    sort(a.begin(), a.end());
    ll sum = 1;
    for(int x: a){
        if(sum < x)
            return cout << sum, 0;
        sum += x;
    }
    cout << sum << '\n';
}