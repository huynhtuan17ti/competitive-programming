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
    int n, x;
    cin >> n >> x;
    map <int, ii> M;
    vector <int> a(n);
    for(auto &x: a)
        cin >> x;
    
    for(int i = 1; i < n; i++){
        for(int j = i+1; j < n; j++){
            int cur = a[i] + a[j];
            if(M.find(x - cur) != M.end())
                return cout << M[x-cur].fi+1 << ' ' << M[x-cur].se+1 << ' ' << i+1 << ' ' << j+1, 0;
        }
        for(int j = 0; j < i; j++)
            M[a[i] + a[j]] = mp(j, i);
    }
    cout << "IMPOSSIBLE";
}