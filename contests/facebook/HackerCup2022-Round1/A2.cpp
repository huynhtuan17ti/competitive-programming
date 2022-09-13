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

vector <int> Zfunction(vector <int> model, vector <int> pattern){
    vector <int> combine = model;
    combine.push_back(-1);
    combine.insert(combine.end(), pattern.begin(), pattern.end());
    
    int n = combine.size();
    vector <int> Z(combine.size());
    int L, R, k;
    L = R = 0;
    for (int i = 1; i < n; ++i){
        if (i > R){
            L = R = i;
            while (R<n && combine[R-L] == combine[R])
                R++;
            Z[i] = R-L;
            R--;
        }
        else{
            k = i-L;
            if (Z[k] < R-i+1)
                Z[i] = Z[k];
            else{
                L = i;
                while (R<n && combine[R-L] == combine[R])
                    R++;
                Z[i] = R-L;
                R--;
            }
        }
    }
    return Z;
}

void solve(int iTest){
    int n, k;
    cin >> n >> k;
    vector <int> a(n), b(n);
    for(int i = 0; i < n; i++)  cin >> a[i];
    for(int i = 0; i < n; i++)  cin >> b[i];
    vector <int> za = Zfunction(a, b);
    vector <int> zb = Zfunction(b, a);

    /*
        a + b = xxxxxx ooooooo
        b + a = ooooooo xxxxxx
    */
    auto isPartArray = [&]()-> bool{
        if(n%2 == 1){
            for(int i = 1; i < n; i++){
                if(a[i] != a[i-1])
                    return false;
            }
            return true;
        }
        for(int i = 0; i < n/2; i++)
            if(a[i] != a[i + n/2])
                return false;
        return true;
    };
    auto check = [&]()-> bool{
        if(za[n+1] == n){
            if(isPartArray())
                return true;
            return (n == 2)? (k%2 == 0) : (k != 1);
        }
        for(int i = n+1; i < za.size(); i++){
            int n_match = za[i];
            // cerr << i - n - 1 << ' ' << n_match << ' ' << i + n_match - 1 << '\n';
            if(i + n_match - 1 == 2*n){
                int r_match = n - n_match;
                if(zb[2*n + 1 - r_match] == r_match)
                    return (n == 2)? (k%2 == 1) : (k > 0);
            }
        }
        
        return false;
    };

    if(check())
        cout << "Case #" << iTest << ": " << "YES" << '\n';
    else cout << "Case #" << iTest << ": " << "NO" << '\n';
}

int main(){
    io
    freopen("A2_test.txt", "r", stdin);
    freopen("test.out", "w", stdout);
    int t; cin >> t;
    for(int iTest = 1; iTest <= t; iTest++){
        solve(iTest);
    }
}