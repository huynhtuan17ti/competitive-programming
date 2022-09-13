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

// F, X left
// F, O right

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.ans", "w", stdout);
    int t; cin >> t;
    for(int iTest = 1; iTest <= t; iTest++){
        int k; cin >> k;
        string U;
        cin >> U;

        string S = "";
        for(char ch: U){
            if(ch == '.'){
                S = S + S;
            }else S = S + ch;
        }
        int n = S.size();

        int pre[3];
        pre[0] = pre[1] = -1;
        ll res = 0;

        ll sum_pre = 0, sum_cur = 0, sum_cur_pre = 0, cnt = 0;

        for(int i = 0; i < n; i++){

            if(S[i] == 'O' && pre[1] < pre[0]){
                cnt++;
                sum_pre = (sum_pre + pre[0])%MOD;
                sum_cur = (sum_cur + i)%MOD;
                sum_cur_pre = (sum_cur_pre + 1LL*pre[0]*i%MOD)%MOD;
                res = (res + 1LL*(pre[0] + 1)*(n - i)%MOD)%MOD;
            }
            if(S[i] == 'X' && pre[0] < pre[1]){
                cnt++;
                sum_pre = (sum_pre + pre[1])%MOD;
                sum_cur = (sum_cur + i)%MOD;
                sum_cur_pre = (sum_cur_pre + 1LL*pre[1]*i%MOD)%MOD;
                res = (res + 1LL*(pre[1] + 1)*(n - i)%MOD)%MOD;
            }

            if(S[i] == 'X')
                pre[0] = i;
            if(S[i] == 'O')
                pre[1] = i;
        }
        //cout << n << ' ' << cnt << '\n';
        //cout << sum_pre << ' ' << sum_cur << ' ' << sum_cur_pre << '\n';
        ll ans = (sum_pre*n%MOD + n*cnt%MOD - sum_cur - sum_cur_pre + MOD + MOD)%MOD;
        //cout << ans << '\n';
        cout << "Case #" << iTest << ": " << res << '\n';
    }
}