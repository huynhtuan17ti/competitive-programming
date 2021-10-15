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
    int n, k;
    cin >> n >> k;
    vector <int> a(n+1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    
    ll res = 0;
    map <int, int> M;
    int cnt = 0;
    int j = 1;
    for(int i = 1; i <= n; i++){
        M[a[i]]++;
        cnt += (M[a[i]] == 1);
        while(j < i && cnt > k){
            M[a[j]]--;
            cnt -= (M[a[j]] == 0);
            j++;
        }
        res += (i - j + 1);
    }
    cout << res << '\n';
}