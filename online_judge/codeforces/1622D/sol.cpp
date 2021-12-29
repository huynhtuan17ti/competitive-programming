#include <bits/stdc++.h>  
using namespace std;

const int MOD = 998244353;
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

int main(){
    io
    int n, k;
    cin >> n >> k;

    string s; cin >> s;
    s = ' ' + s;
    vector <int> cnt(n+1);
    for(int i = 1; i <= n; i++)
        cnt[i] = cnt[i-1] + (s[i] - '0');
    
    vector<vector<int>> C(n + 1);
    for(int i = 0; i <= n; i++){
        C[i].resize(i + 1);
        C[i][0] = C[i][i] = 1;
        for(int j = 1; j < i; j++)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1])%MOD;
    }

    auto nCk = [&](int n, int k) -> int{
        if(n < k || n < 0 || k < 0)
            return 0;
        return C[n][k];
    };

    if(cnt[n] < k)
        return cout << 1, 0;

    ll res = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(cnt[j] - cnt[i-1] > k)
                break;
            int len = j - i + 1 - 2;
            int cnt1 = cnt[j] - cnt[i-1];
            cnt1 -= (s[i] == '0');
            cnt1 -= (s[j] == '0');

            res += nCk(len, cnt1);
            if(res >= MOD)
                res -= MOD;
        }
    }
    cout << res << '\n';
}