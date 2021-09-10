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
int dim = 53; // 1 -> 52

struct matrix{
    vector <vector<ll>> a;
    matrix(){
        a.resize(dim);
        for(int i = 1; i < dim; i++)
            a[i].resize(dim, 0);
    }
};

matrix Identity(){
    matrix A;
    for(int i = 1; i < dim; i++)
        A.a[i][i] = 1;
    return A;
}

matrix operator* (const matrix &A, const matrix &B){
    matrix mul;
    for(int k = 1; k < dim; k++)
        for(int i = 1; i < dim; i++)
            for(int j = 1; j < dim; j++)
                mul.a[i][j] = (mul.a[i][j] + A.a[i][k]*B.a[k][j]%MOD)%MOD;
    return mul;
}

matrix fastPow(matrix A, ll b){
    if(b == 0)
        return Identity();
    if(b == 1)
        return A;
    matrix t = fastPow(A, b/2);
    t = t*t;
    if(b%2 == 1)
        t = t*A;
    return t;
}

int get_code(char ch){
    if('a' <= ch && ch <= 'z')
        return (int)(ch - 'a' + 1); // 1 -> 26
    if('A' <= ch && ch <= 'Z')
        return (int)(ch - 'A' + 27); // 27 -> 52
    return -1;
}

int main(){
    io
    ll n;
    int m, k;
    cin >> n >> m >> k;
    dim = m+1;
    matrix A;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= m; j++)
            A.a[i][j] = 1;
    for(int i = 1; i <= k; i++){
        char a, b;
        cin >> a >> b;
        int u = get_code(a), v = get_code(b);
        A.a[u][v] = 0;
    }
    
    A = fastPow(A, n-1);
    ll res = 0;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j < dim; j++)
            res = (res + A.a[i][j])%MOD;
    }
    cout << res;
}