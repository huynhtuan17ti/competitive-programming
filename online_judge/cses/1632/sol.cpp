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

int main(){
    io
    int n, k;
    cin >> n >> k;
    vii times;
    for(int i = 1; i <= n; i++){
        int a, b;
        cin >> a >> b;
        times.push_back({b, a});
    }
    sort(times.begin(), times.end());
    int ans = 0;
    multiset <int> s;
    for(int i = 0; i < k; i++)
        s.insert(0);
    for(int i = 0; i < n; i++){
        auto it = s.upper_bound(times[i].se);
        if(it == s.begin())
            continue;
        ans++;
        s.erase(--it);
        s.insert(times[i].fi); // insert ending time.
    }
    cout << ans << '\n';
}