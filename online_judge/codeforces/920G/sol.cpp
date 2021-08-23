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
const int MAXN = 1e6;

int get_bit(int val, int id){
    return (val >> id)&1;
}

int mark[MAXN + 5];

void build_seive(){
    for(int i = 2; i <= MAXN; i++)
        mark[i] = i;
    for(int i = 4; i <= MAXN; i += 2)
        mark[i] = 2;
    for(int i = 3; i*i <= MAXN; i++)
        if(mark[i] == i)
            for(int j = i*i; j <= MAXN; j+=i)
                if(mark[j] == j)
                    mark[j] = i;
}

vector <int> extract_primes(int p){
    vector <int> primes;
    int pre = -1;
    while(mark[p] > 0){
        if(mark[p] != pre)
            primes.push_back(mark[p]);
        pre = mark[p];
        p /= mark[p];
    }
    return primes;
}

int get(int val, vector <int> primes){
    int maxState = (1<<((int)primes.size()));
    int res = 0;
    for(int state = 1; state < maxState; state++){
        int num = 1, cnt = 0;
        for(int i = 0; i < primes.size(); i++)
            if(get_bit(state, i)){
                num *= primes[i];
                cnt += 1;
            }
        if(cnt%2 == 1)
            res += val/num;
        else res -= val/num;
    }
    return res;
}

void solve(){
    int x, p, k;
    cin >> x >> p >> k;
    vector <int> primes = extract_primes(p);
    int l = x+1, r = 1e8;
    while(l <= r){
        int mid = (l+r) >> 1;
        int num = (mid - x) - (get(mid, primes) - get(x, primes));
        if(num >= k)
            r = mid - 1;
        else l = mid + 1;
    }
    cout << r+1 << '\n';
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    build_seive();
    int t; cin >> t;
    while(t--){
        solve();
    }
}