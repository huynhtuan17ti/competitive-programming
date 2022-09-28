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

void solve(int iTest){
    string s; cin >> s;
    int n = s.size();
    s = ' ' + s;
    vector<vector<int>> pSum(n+1, vector<int> (30));
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 27; j++)
            pSum[i][j] = pSum[i-1][j] + (s[i]-'a' == j);
    }
    int q; cin >> q;
    int cnt = 0;

    auto calcDiff = [&](int l, int r, int mid){
        int total_diff = 0;
        for(int i = 0; i < 26; i++){
            int left = pSum[mid][i] - pSum[l-1][i];
            int right = pSum[r][i] - pSum[mid][i];
            total_diff += abs(left - right);
        }
        return total_diff;
    };

    while(q--){
        int l, r;
        cin >> l >> r;
        if((r-l+1)%2 == 0)
            continue;
        int mid = (l + r) >> 1;
        
        if(calcDiff(l, r, mid) <= 1 || calcDiff(l, r, mid-1) <= 1){
            // cout << calcDiff(l, r, mid) << ' ' << calcDiff(l, r, mid-1) << '\n';
            cnt++;
        }
    }
    cout << "Case #" << iTest << ": " << cnt << '\n';
}

int main(){
    io
    freopen("A1_test.txt", "r", stdin);
    freopen("test.out", "w", stdout);
    int t; cin >> t;
    for(int iTest = 1; iTest <= t; iTest++){
        solve(iTest);
    }
}