#include <bits/stdc++.h>  
using namespace std;
 
constexpr int MOD = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define mp make_pair
#define fi first
#define se second
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};
constexpr int MAXH = 1e6 + 1;

int factor[MAXH + 1];
vector<int> primes;

void build_sieve_for_H_numbers(){
    vector<int> hs;
    for(int i = 2; i <= MAXH; i++)
        if(i % 4 == 1) factor[i] = i;
    
    for(int i = 5; i*i <= MAXH; i++)
        if(factor[i] == i)
            for(int j = i; j <= MAXH; j += i)
                if(factor[j] == j)
                    factor[j] = i;


    for(int i = 2; i <= MAXH; i++){
        if(factor[i] == i)
            primes.push_back(i);
    }
}

int main() {
    io
    build_sieve_for_H_numbers();
    vector<int> cnt(MAXH+1);
    for(int i = 0; i < primes.size(); ++i)
        for(int j = 0; j <= i; ++j)
            if(1LL * primes[i] * primes[j] <= MAXH) {
                cnt[primes[i] * primes[j]] = 1;
            }else break;
    for(int i = 2; i <= MAXH; ++i) cnt[i] += cnt[i-1];
    int h;
    while(cin >> h) {
        if(h == 0) return 0;
        cout << h << ' ' << cnt[h] << '\n';
    }
}
