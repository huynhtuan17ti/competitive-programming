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

int ask(vector <int> a){
    cout << "? ";
    for(int i = 0; i < a.size(); i++)
        cout << a[i] << " \n"[i == a.size()-1];
    cout.flush();
    int k;
    cin >> k;
    return k;
}

int findLast(int n){
    vector <int> a(n);
    // find last element
    for(int p = 2; p <= n; p++){
        for(int j = 0; j < n; j++)  a[j] = 1;
        a[n-1] = p;
        int k = ask(a);
        if(k == 0)
            return n - p + 2;
    }
    return 1;
}

ii findPair(int n, int x, int y){
    for(int k1 = 1; k1 <= n; k1++){
        int k2 = x + k1 - y;
        if(k2 <= n && 1 <= k2)
            return mp(k1, k2);
    }
}

void solve(){
    int n;
    cin >> n;
    vector <int> p(n);
    p[n-1] = findLast(n);
    
    // find the rest elements
    vector <int> a(n);
    for(int x = 1; x <= n; x++){
        if(x == p[n-1])
            continue;
        ii k = findPair(n, x, p[n-1]);
        for(int i = 0; i < n; i++)
            a[i] = k.fi;
        a[n-1] = k.se;
        int pos = ask(a) - 1;
        p[pos] = x;
    }
    cout << "! ";
    for(int i = 0; i < n; i++)
        cout << p[i] << ' ';
    cout.flush();
}

int main(){
    io
    int t; t = 1;
    while(t--){
        solve();
    }
}