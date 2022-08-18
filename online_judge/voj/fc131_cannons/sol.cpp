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

void solve(){
    int n, m, S;
    cin >> n >> m >> S;
    vector <int> a(n);
    for(int &x: a)
        cin >> x;
    vii org_ranges(m);
    for(ii &range: org_ranges)
        cin >> range.fi >> range.se;
    
    sort(a.begin(), a.end());
    vector <int> f(n), g(n);

    auto check = [&](int numRounds) -> bool{
        vector <ii> ranges(org_ranges.begin(), org_ranges.begin() + numRounds);
        sort(ranges.begin(), ranges.begin() + numRounds);

        // for(auto [l, r]: ranges)
        //     cout << l << ' ' << r << '\n';
        

        int j = 0;
        for(int i = 0; i < n; i++){
            while(j < numRounds && a[i] >= ranges[j].fi)
                j++;
            if(j < numRounds && ranges[j].fi > a[i])
                f[i] = j;
            else f[i] = 1e6;
        }
        
        j = numRounds-1;
        for(int i = n-1; i >= 0; i--){
            while(j >= 0 && a[i] <= ranges[j].se)
                j--;
            if(j >= 0 && ranges[j].se < a[i])
                g[i] = j;
            else g[i] = -1e6;
        }

        // for(int i = 0; i < n; i++)
        //     cout << f[i] << " \n"[i == n-1];
        // for(int i = 0; i < n; i++)
        //     cout << g[i] << " \n"[i == n-1];

        // FIRST k points
        // match i to numRounds - k + i
        // if i lie on the left side of segment 
        // => f[i] <= numRounds - k + i
        // => k <= numRounds - f[i] + i

        // LAST (numRounds - k) points
        // if i lie on the right side of segment
        // => g[i] >= i - (n - (numRounds - k))
        // => k >= numRounds - n + i - g[i]


        vector <int> maxRight(n+1);
        for(int i = n-1; i >= 0; i--){
            maxRight[i] = max(maxRight[i+1], numRounds - n + i - g[i]);
        }

        
        if(maxRight[n-numRounds] <= numRounds)
            return true;

        int minLeft = n;
        for(int i = 0; i < numRounds; i++){
            //cout << i << ' ' << numRounds - f[i] + i << '\n';
            minLeft = min(minLeft, numRounds - f[i] + i);
            //cout << "T: " << minLeft << ' ' << n-numRounds+i << '\n';
            if(i+1 <= minLeft && maxRight[n-numRounds+i+1] <= i+1)
                return true;
        }
        return false;
    };

    // cout << check(2) << '\n';
    // return;

    int L = 1, R = m;
    while(L <= R){
        int mid = (L + R) >> 1;
        if(check(mid)){
            L = mid + 1;
        }
        else R = mid - 1;
    }
    cout << L-1 << '\n';
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int t; cin >> t;
    while(t--){
        solve();
    }
}