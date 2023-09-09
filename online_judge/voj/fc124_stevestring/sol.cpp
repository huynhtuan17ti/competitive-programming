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
const int inf = 1e9;

string s;

int calcDp(int l, int r, int u, int v){
    if(l == r){
        return (u == v && v == s[l])? 1 : inf;
    }
    if(l > r)
        return 0;
    int ans = inf;
    for(int k = l; k < r; k++){
        for(int v1 = 0; v1 <= 2; v1++)
            for(int v2 = 0; v2 <= 2; v2++){
                if(v1 == v2) continue;
                ans = min(ans, calcDp(l, k, u, v1) + calcDp(k+1, r, v2, v));
            }
    }
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int t; cin >> t;
    while(t--){
        cin >> s;
        s = ' ' + s;
    }
}