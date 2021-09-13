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

void solve(int iTest){
    int n, m, A, B;
    cin >> n >> m >> A >> B;
    if(A < n+m-1 || B < n+m-1){
        cout << "Case #" << iTest << ": " << "Impossible" << '\n';
        return;
    }
    vector <vector <int>> a(n);
    for(int i = 0; i < n; i++)
        a[i].resize(m);
    cout << "Case #" << iTest << ": " << "Possible" << '\n';
    for(int i = 1; i < n-1; i++)
        for(int j = 0; j < m-1; j++)
            a[i][j] = 1000;
    for(int j = 1; j < m; j++){
        a[0][j] = 1;
        a[n-1][j] = 1;
    }
    for(int i = 0; i < n; i++)
        a[i][m-1] = 1;
    a[0][0] = A - (n+m-2);
    a[n-1][0] = B - (n+m-2);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    int t; cin >> t;
    for(int iTest = 1; iTest <= t; iTest++){
        solve(iTest);
    }
}