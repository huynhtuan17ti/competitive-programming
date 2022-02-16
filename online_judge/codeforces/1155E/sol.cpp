#include <bits/stdc++.h>  
using namespace std;

const int MOD = 1e6 + 3;
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
const int inf = 1e9;
const double eps = 1e-6;

int powMod(int a, int b){
    if(b == 0)
        return 1;
    if(b == 1)
        return a%MOD;
    int t = powMod(a, b/2);
    t = 1LL*t*t%MOD;
    if(b%2 == 1)
        t = (1LL*t*a)%MOD;
    return t;
}

int gauss(vector <vector<int>> a, vector <int> &ans){
    int n = (int)a.size();
    int m = (int)a[0].size() - 1;
    
    vector <int> where(m, -1);
    
    for(int col = 0, row = 0; col < m && row < n; col++){
        int pivot = row;
        for(int i = row; i < n; i++)
            if(abs(a[i][col]) > abs(a[pivot][col]))
                pivot = i;

        for(int i = col; i <= m; i++)
            swap(a[pivot][i], a[row][i]);
        where[col] = row;

        for(int i = 0; i < n; i++)
            if(i != row){
                int c = 1LL*a[i][col] * powMod(a[row][col], MOD - 2)%MOD;
                for(int j = col; j <= m; j++)
                    a[i][j] = (a[i][j] - 1LL*a[row][j] * c % MOD + MOD)%MOD;
            }
        row++;
    }
    
    ans.assign(m, 0);
    for(int i = 0; i < m; i++)
        if(where[i] != -1)
            ans[i] = 1LL * a[where[i]][m] * powMod(a[where[i]][i], MOD - 2) % MOD;

    return 1;
}

int main(){
    io
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int K = 11;
    
    auto ask = [&](int x){
        cout << "? " << x << '\n';
        cout.flush();
        
        int f; cin >> f;
        return f;
    };

    vector <vector <int>> a(K, vector <int>(K+1, 0));

    for(int iAsk = 0; iAsk < K; iAsk++){
        int x = iAsk;
        int f = ask(x);
        int cur = 1;
        for(int j = 0; j < K; j++){
            a[iAsk][j] = cur;
            cur = 1LL*cur*x%MOD;
        }
        a[iAsk][K] = f;
    }

    vector <int> ans;
    int p = gauss(a, ans);
    if(p == 0){
        cout << "! " << -1 << '\n';
        cout.flush();
        return 0;
    }
    for(int x = 0; x < MOD; x++){
        int cur = 1, sum = 0;
        for(int coeff: ans){
            sum = (sum + 1LL*cur*coeff%MOD)%MOD;
            cur = 1LL*cur*x%MOD;
        }
        if(sum == 0){
            cout << "! " << x << '\n';
            cout.flush();
            return 0;
        }
    }
    cout << "! " << -1 << '\n';
    cout.flush();
    return 0;
}