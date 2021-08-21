#include <bits/stdc++.h>  
 
using namespace std;
 
const int MOD = 1e9 + 7;
typedef unsigned long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define mp make_pair
#define fi first
#define se second
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
const int MAXN = 1e5;
int factor[MAXN + 5];
 
vector <int> primes;
 
void build_seive(){
    for(int i = 2; i <= MAXN; i++)
        factor[i] = i;
    for(int i = 4; i <= MAXN; i+=2)
        factor[i] = 2;
    for(int i = 3; i*i <= MAXN; i++)
        if(factor[i] == i)
            for(int j = i*i; j <= MAXN; j+=i)
                factor[j] = i;
 
    
    for(int i = 2; i <= MAXN; i++){
        if(factor[i] == i)
            primes.push_back(i);
    }
}
 
int vi[MAXN+5];
 
void F(int val){
    while(val > 1){
        int p = factor[val];
        vi[p] = 1;
        while(val%p == 0)
            val /= p;
    }
}
 
 
int main(){
    io
    build_seive();
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        F(x);
    }
    for(int i = 2; i <= MAXN; i++){
        if(vi[i]){
            for(int j = i; j <= MAXN; j+=i)
                vi[j] = 1;
        }
    }
    vector <int> res;
    for(int i = 1; i <= m; i++)
        if(vi[i] == 0)
            res.push_back(i);
    cout << res.size() << '\n';
    for(int u: res)
        cout << u << '\n';
}