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
 
void solve(){
    int n, q;
    cin >> n >> q;
    vector <int> L(n+2), R(n+2);
    string s; cin >> s;
    s = " " + s;
    for(int i = 1; i <= n; i++){
        char ch = s[i];
        L[i] = L[i-1] + ((i%2 == 1)?1 : -1) * ((ch == '+')? 1: -1);
    }
    for(int i = n; i >= 1; i--){
        char ch = s[i];
        R[i] = R[i+1] + ((i%2 == 1)?1 : -1) * ((ch == '+')? 1: -1);
    }

    map <int, vector <int>> M;
    for(int i = 0; i < n; i++){
        int val = L[i] - R[i+2];
        M[val].push_back(i);
    }

    while(q--){
        int l, r;  cin >> l >> r;
        int val = L[r] - L[l-1];
        if(l%2 == 0)
            val = -val;
        if(val == 0){
            cout << 0 << '\n';
            continue;
        }

        if((r-l+1)%2 == 1){
            /*
                sum[l -> i-1] = sum[i+1 -> r]
                => L[i-1] - L[l-1] = R[i+1] - R[r+1]
                => L[i-1] - R[i+1] = L[l-1] - R[r+1]
            */
            int x = L[l-1] - R[r+1];
            int idx = lower_bound(M[x].begin(), M[x].end(), l-1) - M[x].begin();
            cout << 1 << '\n';
            cout << M[x][idx]+1 << '\n';
        }else{
            /*
                Remove last position to reproduce the above algorithm
            */
            int x = L[l-1] - R[r];
            int idx = lower_bound(M[x].begin(), M[x].end(), l-1) - M[x].begin();
            cout << 2 << '\n';
            cout << M[x][idx]+1 << ' ' << r << '\n';
        }
    }

}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int t; cin >> t;
    while(t--){
        solve();
    }
}