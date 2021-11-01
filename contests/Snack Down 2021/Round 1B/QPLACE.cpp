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
    int n; cin >> n;
    vector <vector <char>> a(n);
    for(int i = 0; i < n; i++)
        a[i].resize(n, '.');
    for(int i = 1; i < n-1; i++)
        a[i][i] = 'Q';
    if(n%2 == 0){
        a[0][0] = 'Q';
        a[1][1] = '.';
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << a[i][j];
        cout << '\n';
    }
}

int main(){
    io
    int t; cin >> t;
    while(t--){
        solve();
    }
}