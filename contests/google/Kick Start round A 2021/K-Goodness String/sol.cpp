/* Tuan Kkura */
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define base 31
#define MOD 1e9+7
#define pb push_back
#define _io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

typedef pair <int, int> ii;
typedef vector <ii> vii;
#define fi first
#define se second
#define mp make_pair
#define PROB "text"
#define MAXN 400005

int main(){
    _io
    int T; cin >> T;
    for(int iTest = 1; iTest <= T; iTest++){
        string s;
        int k, n;
        cin >> n >> k;
        cin >> s;
        int res = 0;
        for(int i = 0; i < n/2; i++)
            if(s[i] != s[n-i-1])
                res++;
        cout << "Case #" << iTest << ": " << abs(k-res) << '\n';
    }
}
