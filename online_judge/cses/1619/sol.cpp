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
const int MAXN = 500005;

int main(){
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    io
    int n;
    cin >> n;
    vii ranges;
    vector <int> S;
    for(int i = 1; i <= n; i++){
        int l, r;
        cin >> l >> r;
        ranges.push_back({l, r});
        S.push_back(l);
        S.push_back(r);
        S.push_back(r+1);
    }
    sort(S.begin(), S.end());
    S.resize(unique(S.begin(), S.end()) - S.begin());
    int len = S.size();
    vector <int> cnt(len);
    for(auto [l, r]: ranges){
        l = lower_bound(S.begin(), S.end(), l) - S.begin();
        r = lower_bound(S.begin(), S.end(), r+1) - S.begin();
        cnt[l]++;
        cnt[r]--;
    }
    int ans = 0;
    for(int i = 1; i < len; i++){
        cnt[i] += cnt[i-1];
        ans = max(ans, cnt[i]);
    }
    cout << ans << '\n';
}