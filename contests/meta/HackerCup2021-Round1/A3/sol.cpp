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

/*
    (pre + 1) * (n - cur)
    = pre * n - pre * cur + n - cur
    = Sum(pre) * n - G + n * cnt(pre, cur) - Sum(cur)

    G = Sum(pre * cur)
    as pre = pre' + len, cur = cur' + len
    => G = Sum(pre' * cur') + Sum(cur') * len + Sum(pre')*len + len**2 ==> implement recursion

    F[pre, cur] = F[pre', cur'] + Sum(cur') * len + Sum(pre')*len + len**2

    Must hold:
    - Sum(cur)
    - Sum(pre)
    - Sum(pre*cur)
    - cnt(pre, cnt)
*/

ll get_len(string u){
    ll len = 0;
    for(char ch: u)
        if(ch == '.')
            len = (len*2)%MOD;
        else len = (len+1)%MOD;
    return len;
}

void solve(int iTest){
    int k; cin >> k;
    string u; cin >> u;

    ll n = get_len(u);
    ll sum_pre = 0;
    ll sum_cur = 0;
    ll sum_pre_cur = 0;
    ll cnt = 0;

    ll cur = 0;


    ll pos[3];
    pos[0] = pos[1] = -1;
    int __pos = 0;

    ll pre[3];
    pre[0] = pre[1] = -1; // X is 0, O is 1
    ll first = -1, index = -1; // store first O, X letter

    for(int i = 0; i < k; i++){
        if(u[i] == '.'){
            // update duplication
            sum_pre_cur = (sum_pre_cur*2%MOD +  (sum_cur*cur%MOD + sum_pre*cur%MOD + cur*cur%MOD*cnt%MOD)%MOD)%MOD;
            sum_pre = (sum_pre*2%MOD + cnt*cur%MOD)%MOD;
            sum_cur = (sum_cur*2%MOD + cnt*cur%MOD)%MOD;

            cnt = (cnt*2)%MOD;

            // special case
            if(first >= 0 && pos[first] < pos[1-first]){
                ll cur_index = (index + cur)%MOD;
                cnt = (cnt + 1)%MOD;
                sum_pre = (sum_pre + pre[1 - first])%MOD;
                sum_cur = (sum_cur + cur_index)%MOD;
                sum_pre_cur = (sum_pre_cur + pre[1 - first]*cur_index%MOD)%MOD;
            }

            if(pre[0] != -1)
                pre[0] = (pre[0] + cur)%MOD;
            if(pre[1] != -1)
                pre[1] = (pre[1] + cur)%MOD;

            cur = (cur*2)%MOD;
        }else{
            if(u[i] == 'F'){
                cur = (cur+1)%MOD;
                continue;
            }
            int x = ((u[i] == 'O')? 1: 0);
            if(pre[x] < pre[1-x]){
                cnt = (cnt + 1)%MOD;
                sum_pre = (sum_pre + pre[1-x])%MOD;
                sum_cur = (sum_cur + cur)%MOD;
                sum_pre_cur = (sum_pre_cur + pre[1-x]*cur%MOD)%MOD;
            }
            
            if(first == -1){
                first = x;
                index = cur;
            }

            pre[x] = cur;
            cur = (cur+1)%MOD;
            
            pos[x] = __pos;
            __pos++;
        }
    }
    ll res = (sum_pre*n%MOD + n*cnt%MOD - sum_cur - sum_pre_cur + MOD + MOD)%MOD;
    cout << "Case #" << iTest << ": " << res << '\n';
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int t; cin >> t;
    for(int iTest = 1; iTest <= t; iTest++){
        solve(iTest);
    }
}