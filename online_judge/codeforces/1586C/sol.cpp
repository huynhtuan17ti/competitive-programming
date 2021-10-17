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
    int n, m;
    cin >> n >> m;
    vector <vector <int>> a(n+1);
    vector <vector <int>> s(n+1);
    for(int i = 0; i <= n; i++){
        a[i].resize(m+1);
        s[i].resize(m+1);
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            char ch;
            cin >> ch;
            if(ch == 'X')
                a[i][j] = 1;
            else a[i][j] = 0;
            if(a[i-1][j] == 1 && a[i][j-1] == 1)
                s[i][j] = 1;
        }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            s[i][j] += (s[i-1][j] + s[i][j-1] - s[i-1][j-1]); 
        }
    int q; cin >> q;
    while(q--){
        int x1, x2;
        cin >> x1 >> x2;
        if(x1 == x2){
            cout << "YES" << '\n';
        }else{
            int p = s[n][x2] - s[n][x1] - s[1][x2] + s[1][x1];
            if(p > 0)
                cout << "NO" << '\n';
            else cout << "YES" << '\n';
        }
    }
}

int main(){
    io
    int t; t = 1;
    while(t--){
        solve();
    }
}