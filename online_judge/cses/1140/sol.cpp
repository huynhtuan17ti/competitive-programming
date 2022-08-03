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
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);
    int n; cin >> n;
    vector <int> s;
    vector <tuple<int, int, int>> projects;
    for(int i = 1; i <= n; i++){
        int a, b, p;
        cin >> a >> b >> p;
        s.push_back(a);
        s.push_back(b);
        projects.push_back({a, b, p});
    }
    s.push_back(INT_MIN);
    sort(s.begin(), s.end());
    s.resize(unique(s.begin(), s.end()) - s.begin());
    for(auto &[a, b, p]: projects){
        a = lower_bound(s.begin(), s.end(), a) - s.begin();
        b = lower_bound(s.begin(), s.end(), b) - s.begin();
        //cerr << a << ' ' << b << '\n';
    }
    sort(projects.begin(), projects.end());
    vector <ll> dp(s.size());
    int i  = 1;
    for(auto [a, b, p]: projects){
        while(i < a){
            dp[i] = max(dp[i], dp[i-1]);
            i++;
        }
        dp[b] = max(dp[b], dp[a-1] + p);
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
}