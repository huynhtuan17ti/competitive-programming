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


int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.ans", "w", stdout);
    build_seive();
    int t;
    cin >> t;
    while(t--){
        int l, r;
        cin >> l >> r;
        int cnt = 0;
        for(int u = l; u <= r; u++){
            vector <int> digits = getDigits(u);
            int sum = 0, sqsum = 0;
            for(int d: digits){
                sum += d;
                sqsum += d*d;
            }
            if(factor[sum] == sum && factor[sqsum] == sqsum)
                cnt++;
        }
        cout << cnt << '\n';
    }
}