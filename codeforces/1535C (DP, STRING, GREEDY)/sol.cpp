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

const int MAXN = 200005;

int idx[MAXN][2][2];

int main(){
    io
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int n = (int)s.size();
        s = " " + s;
        for(int i = 0; i <= n; i++){
            idx[i][0][0] = 0; idx[i][0][1] = 0;
            idx[i][1][0] = 0; idx[i][1][1] = 0;
        }
        for(int i = 1; i <= n; i++){
            if(s[i] != '?')
                idx[i][s[i] - '0'][i%2] = i;
            for(int val = 0; val <= 1; val++)
                for(int type = 0; type <= 1; type++)
                    idx[i][val][type] = max(idx[i][val][type], idx[i-1][val][type]);
        }
        ll res = 0;
        for(int i = 1; i <= n; i++){
            int len1 = i - max(idx[i][0][0], idx[i][1][1]);
            res += len1;
            int len2 = i - max(idx[i][0][1], idx[i][1][0]);
            res += len2;
            res -= min(len1, len2);
        }
        cout << res << '\n';
    }
}