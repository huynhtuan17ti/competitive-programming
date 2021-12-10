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
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

const int MAXN = 9*9*18;
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
                if(factor[j] == j)
                    factor[j] = i;
    factor[0] = -1;
    for(int i = 2; i <= MAXN; i++)
        if(factor[i] == i)
            primes.push_back(i);
}

vector <int> getDigits(ll val){
    vector <int> digits;
    while(val > 0){
        digits.push_back(val%10);
        val /= 10;
    }
    reverse(digits.begin(), digits.end());
    return digits;
}

ll F[20][9*18 + 1][9*9*18 + 1];
ll D[20][9*18 + 1][9*9*18 + 1];

void initialize(){
    F[0][0][0] = 1;
    for(int digit = 0; digit <= 9; digit++){
        F[1][digit][digit*digit] = 1;
    }
    for(int i = 2; i <= 18; i++){
        for(int sum = 0; sum <= 9*(i-1); sum++)
            for(int sqsum = 0; sqsum <= 9*9*(i-1); sqsum++){
                for(int digit = 0; digit <= 9; digit++)
                    F[i][sum + digit][sqsum + digit*digit] += F[i-1][sum][sqsum];
            }
    }

    for(int i = 0; i <= 18; i++){
        for(int sum = 0; sum <= 9*i; sum++)
            for(int sqsum = 0; sqsum <= 9*9*i; sqsum++){
                if(F[i][sum][sqsum] == 0)
                    continue;
                for(int p: primes)
                    if(p >= sqsum)
                        D[i][sum][p - sqsum] += F[i][sum][sqsum];
            }
    }
}

ll calc(ll x){
    vector <int> digits = getDigits(x);
    int n = digits.size();
    int sum = 0, sqsum = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(int digit = 0; digit < digits[i]; digit++){
            int _sum = sum + digit;
            int _sqsum = sqsum + digit*digit;
            for(int p: primes){
                if(p > 9*18)
                    break;
                if(p >= _sum){
                    assert(D[n-i-1][p - _sum][_sqsum] >= 0);
                    ans += D[n-i-1][p - _sum][_sqsum];
                }
            }
        }
        sum += digits[i];
        sqsum += digits[i]*digits[i];
        //cout << ans << '\n';
    }
    if(factor[sum] == sum && factor[sqsum] == sqsum)
        ans++;
    return ans;
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    build_seive();
    initialize();
    int t; cin >> t;
    while(t--){
        ll l, r;
        cin >> l >> r;
        cout << calc(r) - calc(l-1) << '\n';
    }
}