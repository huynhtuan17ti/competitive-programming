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
 

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n; cin >> n;
    vector <int> t(n);
    for(int i = 0; i < n; i++)
        cin >> t[i];
    sort(t.begin(), t.end());
    int i = 0, j = n-1;
    vector <int> res;
    while(i <= j){
        res.push_back(t[j]);
        if(i != j)
            res.push_back(t[i]);
        j -= 1;
        i += 1;
    }
    reverse(res.begin(), res.end());
    for(int u: res)
        cout << u << ' ';
}