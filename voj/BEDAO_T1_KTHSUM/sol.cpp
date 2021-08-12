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
const int MAXN = 1e5 + 5;
ll sum[MAXN];

template <typename T>
class FenwickTree{
    vector <T> fenw;
    int n;
    public:
        void initialize(int _n){
            this->n = _n;
            fenw.resize(n+1);
        }

        void update(int id, T val) {
            while (id >= 1) {
                fenw[id] += val;
                id -= id&(-id);
            }
        }

        T get(int id){
            T ans{};
            while(id <= n){
                ans += fenw[id];
                id += id&(-id); 
            }
            return ans;
        }
};

vector <ll> S;

int findIdx(ll x){
    return lower_bound(S.begin(), S.end(), x) - S.begin();
}

bool isUpper(ll val, ll k, int n){
    FenwickTree <int> fenw;
    fenw.initialize((int)S.size());
    
    fenw.update(findIdx(0), 1);
    ll res = 0;
    for(int i = 1; i <= n; i++){
        int x = findIdx(sum[i]);
        int x_bound = findIdx(sum[i] - val);
        res += fenw.get(x_bound);
        fenw.update(x, 1);
    }
    return (res >= k);
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n;
    ll k;
    cin >> n >> k;
    S.push_back(0);
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        sum[i] = sum[i-1] + x;
        S.push_back(sum[i]);
    }
    S.push_back(LLONG_MIN);
    sort(S.begin(), S.end());
    S.resize(unique(S.begin(), S.end()) - S.begin());

    ll l = -1e14, r = 1e14;
    while(l <= r){
        ll mid = (l+r) >> 1;
        if(isUpper(mid, 1LL*n*(n+1)/2 - k + 1, n))
            r = mid - 1;
        else l = mid + 1;
    }
    cout << r+1 << '\n';
}