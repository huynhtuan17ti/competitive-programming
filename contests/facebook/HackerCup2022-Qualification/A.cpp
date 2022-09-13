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

bool solve(){
    int n, k;
    cin >> n >> k;
    vector <int> cnt(105);
    for(int i = 1; i <= n; i++){
        int s; cin >> s;
        cnt[s]++;
    }
    for(int i = 1; i <= 100; i++)
        if(cnt[i] > 2){
            //cerr << i << ' ' << cnt[i] << '\n';
            return false;
        }
    if(k*2 < n)
        return false;
    
    return true;
}

int main(){
    io
    freopen("A.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int t; cin >> t;
    for(int iTest = 1; iTest <= t; iTest++){
        if(solve())
            cout << "Case #" << iTest << ": " << "YES" << '\n';
        else  cout << "Case #" << iTest << ": " << "NO" << '\n';
    }
}