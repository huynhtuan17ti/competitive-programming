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
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
const int MAXN = 5e5 + 5;

int main(){
    io
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    ll n; cin >> n;
    vector<int> bits;
    for(int bit = 0; bit <= 50; bit++)
        bits.push_back(((n>>bit)&1));

    while(*bits.rbegin() == 0)
        bits.pop_back();
    
    int n_bit = bits.size();
    vector<ll> F(n_bit+1);
    vector<ll> pow2(n_bit+1);
    pow2[0] = 1;
    for(int i = 1; i <= n_bit; i++) {
        F[i] = F[i-1] + pow2[i-1] + F[i-1];
        pow2[i] = pow2[i-1] * 2;
    }

    // for(int bit: bits)
    //     cout << bit;
    // cout << '\n';

    ll res = 0, curBitCnt = 0;
    for(int i = n_bit-1; i >= 0; i--) {
        int curBit = bits[i];
        if(curBit == 0)
            continue;
        // cerr << F[i] << ' ' << curBitCnt * pow2[i] << '\n';
        res += F[i] + curBitCnt * pow2[i];
        curBitCnt++;
    }
    cout << res + curBitCnt << '\n';
}