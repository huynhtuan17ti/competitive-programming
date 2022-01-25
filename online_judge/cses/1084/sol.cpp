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
    int n, m, k;
    cin >> n >> m >> k;
    vector <int> a(n), b(m);
    for(int &x: a)
        cin >> x;
    for(int &x: b)
        cin >> x;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int j = 0, ans = 0;
    for(int i = 0; i < m; i++){
        int l = b[i] - k, r = b[i] + k;
        while(j < n && a[j] < l)
            j++;
        if(j < n && l <= a[j] && a[j] <= r){
            ans++;
            j++;
        }
    }
    cout << ans << '\n';
}