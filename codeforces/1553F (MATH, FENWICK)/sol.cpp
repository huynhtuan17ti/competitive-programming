#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define limit 300000
#define MAXN 300005

class BIT{
    private:
        ll data[MAXN];
    public:
        void init(){
            fill(data, data+1+limit, 0);
        }
        void update(int id, ll val){
            while(id <= limit){
                data[id] += val;
                id += id&(-id);
            }
        }
        void update_range(int l, int r, ll val){
            update(l, val);
            update(r+1, -val);
        }
        ll get(int id){
            ll ans = 0;
            while(id >= 1){
                ans += data[id];
                id -= id&(-id);
            }
            return ans;
        }
        ll get_range(int l, int r){
            return get(r) - get(l-1);
        }
};

int main(){
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n; cin >> n;
    vector <int> p(n+1);
    vector <ll> sum(n+1);
    for(int i = 1; i <= n; i++){
        cin >> p[i];
        sum[i] = sum[i-1] + p[i];
    }
    vector <ll> s(n+1), t(n+1);
    BIT bit_s, bit_t;
    bit_s.init();
    bit_t.init();
    // calculate s
    for(int i = 1; i <= n; i++){
        s[i] = s[i-1] + 1LL*(i-1)*p[i] - bit_s.get(p[i]);
        int d = 2;
        while(1LL*(d-1)*p[i] <= limit){
            int L = (d-1)*p[i], R = min(d*p[i]-1, limit);
            bit_s.update_range(L, R, 1LL*(d-1)*p[i]);
            d += 1;
        }
    }
    // calculate t
    for(int i = 1; i <= n; i++){
        ll val = 0;
        int d = 2;
        while(1LL*(d-1)*p[i] <= limit){
            int L = (d-1)*p[i], R = min(d*p[i]-1, limit);
            val += 1LL*bit_t.get_range(L, R)*(d-1)*p[i];
            d += 1;
        }
        t[i] = t[i-1] + sum[i-1] - val;
        bit_t.update(p[i], 1);
    }

    for(int i = 1; i <= n; i++)
        cout << s[i]+t[i] << " \n"[i == n];
}