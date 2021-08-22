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

int n;
vector <int> h;
vector <int> can_h;
ll res = 0;

void calc(int pos, int cur_val, int k){
    if(pos == can_h.size() || cur_val == k){
        ll cur_ans = 0;
        vector <int> L(n+2, 0), R(n+2, 0);
        for(int i = 1; i <= n; i++)
            L[i] = max(L[i-1], h[i]);
        for(int i = n; i >= 1; i--){
            R[i] = max(R[i+1], h[i]);
            cur_ans += (min(L[i], R[i]) - h[i]);
        }
        res = max(res, cur_ans);
        return;
    }
    for(int i = cur_val; i <= k; i++){
        h[can_h[pos]] += (i - cur_val);
        calc(pos+1, i, k);
        h[can_h[pos]] -= (i - cur_val);
    }
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int k;
    cin >> n >> k;
    h.resize(n+2);
    for(int i = 1; i <= n; i++){
        cin >> h[i];
    }
    ll final_res = 0;
    for(int state = 1; state < (1<<n); state++){
        if(__builtin_popcount(state) == 3){
            can_h.clear();
            for(int i = 1; i <= n; i++){
                if((state>>(i-1))&1)
                    can_h.push_back(i);
            }
            calc(0, 0, k);
            final_res = max(final_res, res);
        }
    }
    cout << final_res << '\n';
}