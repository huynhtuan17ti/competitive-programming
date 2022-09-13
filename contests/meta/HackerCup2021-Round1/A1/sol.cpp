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

bool check(int id_hand, char ch){
    if(ch == 'X' && id_hand == 1)
        return false;
    if(ch == 'O' && id_hand == 0)
        return false;
    return true;
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int t; cin >> t;
    for(int iTest = 1; iTest <= t; iTest++){
        int n; cin >> n;
        string W;
        cin >> W;
        // F, X left
        // F, O right
        int res = INT_MAX;
        for(int start = 0; start <= 1; start++){
            int cnt = 0;
            int cur = start;
            for(char ch: W){
                if(!check(cur, ch)){
                    cnt++;
                    cur = 1 - cur;
                }
            }
            res = min(res, cnt);
        }
        cout << "Case #" << iTest << ": " << res << '\n';
    }
}