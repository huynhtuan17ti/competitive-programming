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
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int n;
    cin >> n;
    vector <int> a(n);
    for(int &x: a){
        cin >> x;
    }
    map <int, int> M;
    ll sum = 0;
    ll ans = 0;
    M[sum]++;
    for(int x: a){
        sum = (sum + x%n + n)%n;
        ans += M[sum];
        M[sum]++;
    }
    cout << ans << '\n';
}