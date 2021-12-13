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
const int MAXN = 5e5 + 5;

ll res = 0;
ll maxState[1<<18];

void calc(int bit, int k, int mask1, int mask2, int mask3){
    if(bit == k){
        res = max(res, maxState[mask1] + maxState[mask2] + maxState[mask3]);
        return;
    }
    calc(bit+1, k, mask1 + (1<<bit), mask2, mask3); 
    calc(bit+1, k, mask1, mask2 + (1<<bit), mask3);
    calc(bit+1, k, mask1, mask2, mask3 + (1<<bit));
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector <vector <int>> p(n, vector <int> (k));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++)
            cin >> p[i][j];
    }

    // inititialize
    vector <ll> sum(1<<k);
    for(int i = 0; i < n; i++){
        fill(sum.begin(), sum.end(), 0);
        for(int state = 1; state < (1<<k); state++){
            int lastBit = __builtin_ctz(state);
            sum[state] = sum[state - (1<<lastBit)] + p[i][lastBit];
            maxState[state] = max(maxState[state], sum[state]);
        }
    }
    calc(0, k, 0, 0, 0);
    cout << res << '\n';
}