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
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
const int MAXN = 5e5 + 5;

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector <int> A(n); 
    vector <int> B(m);
    for(auto &x: A)
        cin >> x;
    for(auto &x: B)
        cin >> x;
    
    int sumA = 0, sumB = 0;
    for(int x: A)
        sumA ^= x;
    for(int x: B)
        sumB ^= x;
    
    if(sumA != sumB){
        cout << "NO";
        return 0;
    }

    vector <vector <int>> ans(n, vector <int>(m));
    for(int i = 0; i < n; i++)
        ans[i][m-1] = A[i];
    
    for(int i = 0; i < m; i++)
        ans[n-1][i] = B[i];

    ans[n-1][m-1] = sumA ^ A[n-1] ^ B[m-1];

    cout << "YES" << '\n';  
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cout << ans[i][j] << " \n"[j == m-1];
    }
    //cout <<  << '\n';
}