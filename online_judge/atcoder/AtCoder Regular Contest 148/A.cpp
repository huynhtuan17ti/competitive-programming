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
    int n; cin >> n;
    vector <int> a(n);
    for(int &u: a){
        cin >> u;
    }
    sort(a.begin(), a.end());
    int G = 0;
    for(int i = 1; i < n; i++)
        G = __gcd(G, a[i] - a[i-1]);
    if(G > 1 || G == 0){
        cout << 1 << '\n';
    }else cout << 2 << '\n';
}