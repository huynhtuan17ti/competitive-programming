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
const int MAXN = 1e7;

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

    
    for(int i = 2; i <= MAXN; i++){
        if(factor[i] == i)
            primes.push_back(i);
    }
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    build_seive();
    
    map <string, int> cnt;

    for(int prime: primes){
        vector <int> digits;
        while(prime > 0){
            digits.push_back(prime%10);
            prime /= 10;
        }
        sort(digits.begin(), digits.end());
        string s = "";
        for(int u: digits)
            s += (char)(u + '0');
        cnt[s]++;
    }

    auto getBit = [&](int val, int id) -> bool{
        return (val >> id)&1;
    };
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        vector <int> a;
        for(char ch: s)
            a.push_back(ch - '0');
        sort(a.begin(), a.end());
        int n = a.size();
        int ans = 0;
        map <string, bool> vi;
        for(int state = 1; state < (1<<n); state++){
            string cur = "";
            for(int i = 0; i < a.size(); i++)
                if(getBit(state, i))
                    cur += (char)(a[i] + '0');
            if(vi[cur] == true){
                continue;
            }
            vi[cur] = true;
            ans += cnt[cur];
        }
        cout << ans << '\n';
    }
}