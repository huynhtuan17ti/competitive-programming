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
const int MAXN = 5005;

unordered_map <int, int> M[MAXN];

int main(){
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    io
    int n, x; cin >> n >> x;
    vii a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort(a.begin(), a.end());
    for(int i = 2; i < n; i++){
        int neededSum = x - a[i].fi;
        int l = 0, r = i-1;
        while(l != r){
            if(a[l].fi + a[r].fi + a[i].fi == x)
                return cout << a[l].se+1 << ' ' << a[r].se+1 << ' ' << a[i].se+1, 0;
            if(a[l].fi + a[r].fi < neededSum)
                l++;
            else r--;
        }
    }
    cout << "IMPOSSIBLE";
}