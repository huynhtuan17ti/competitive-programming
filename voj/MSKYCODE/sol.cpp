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
const int MAXN = 1e4;
int cnt[MAXN+5];
int factor[MAXN + 5];
ll res = 0;

int get_bit(int val, int id){
    return (val>>id)&1;
}

vector <int> primes;

void build_seive(){
    for(int i = 2; i <= MAXN; i++)
        factor[i] = i;
    for(int i = 4; i <= MAXN; i+=2)
        factor[i] = 2;
    for(int i = 3; i*i <= MAXN; i++)
        if(factor[i] == i)
            for(int j = i*i; j <= MAXN; j+=i)
                if(factor[j] == j)
                    factor[j] = i;

    
    for(int i = 2; i <= MAXN; i++){
        if(factor[i] == i)
            primes.push_back(i);
    }
}

vector <int> get(int val){
    vector <int> ans;
    while(val > 1){
        int p = factor[val];
        ans.push_back(p);
        while(val%p == 0)
            val /= p;
    }
    return ans;
}

ll nC4(int n){
    return 1LL*n*(n-1)*(n-2)*(n-3)/24;
}

void solve(int pos, int num, int val){
    if(pos == primes.size())
        return;

    if(num % 2 == 1){
        res += nC4(cnt[val]);
        cnt[val] = 0;
    }
    else res -= nC4(cnt[val]);

    for(int i = pos; i < primes.size(); i++)
        if(val*primes[i] <= MAXN)
            solve(i+1, num+1, val*primes[i]);
        else break;
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n; 
    build_seive();
    while(cin >> n){
        res = 0;
        fill(cnt, cnt+1+MAXN, 0);
        vector <int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            vector <int> p = get(a[i]);
            int len = (int)p.size();
            int maxState = (1<<len);
            for(int state = 1; state < maxState; state++){
                int cur = 1;
                for(int i = 0; i < len; i++)
                    if(get_bit(state, i))
                        cur *= p[i];
                cnt[cur]++;
            }
        }
        solve(0, 0, 1);
        cout << nC4(n) - res << '\n'; 
    }
}