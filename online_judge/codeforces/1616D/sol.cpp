#include <bits/stdc++.h>  
using namespace std;

const int MOD = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
#define mp make_pair
#define fi first
#define se second
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
const int MAXN = 5e5 + 5;
const ll inf = -1e15;

void solve(){
    int n, x; cin >> n;
    vector <int> a(n+1);
    vector <ll> s(n+1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> x;
    for(int i = 1; i <= n; i++){
        a[i] -= x;
        s[i] = s[i-1] + a[i];
    }

    int res = 0;
    int j = 1;
    ll sum = 0;
    for(int i = 1; i <= n; i++){
        if(i == j){
            res++;
            sum = a[i];
        }else if(sum + a[i] < 0){
            sum = 0;
            j = i + 1;
        }else{
            // sum + a[i] >= 0
            res++;
            if(sum >= 0){
                sum = a[i];
            }else{
                sum += a[i];
            }
        }
    }
    cout << res << '\n';
}

int main(){
    io
    int t; cin >> t;
    cerr << t << '\n';
    while(t--){
        solve();
    }
}