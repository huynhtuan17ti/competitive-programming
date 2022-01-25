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
    int n, m;
    cin >> n >> m;
    vector <int> h(n);
    multiset <int> s;
    for(int &x: h){
        cin >> x;
        s.insert(x);
    }
    while(m--){
        int x; cin >> x;
        auto it = s.upper_bound(x);
        if(it == s.begin())
            cout << -1 << '\n';
        else{
            it--;
            cout << (*it) << '\n';
            s.erase(it);
        }
    }
}