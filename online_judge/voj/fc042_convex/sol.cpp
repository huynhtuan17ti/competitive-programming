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
const double pi = 3.1415926535;
const int MAXN = 5e5 + 5;

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n; cin >> n;
    string s; cin >> s;

    const double sin60 = 0.8660254038;
    const double sin15 = 0.25881904;
    double dist_T_S = sin15 * 2;
    double dist_T_C = 1.00914177;
    double half_perimeter = pi / 2.0;

    if(s[0] != 'T' && s[n-1] != 'T'){
        double ans = n * 2 + 2;
        if(s[0] == 'C')
            ans = ans - 2 + half_perimeter;
        if(s[n-1] == 'C')
            ans = ans - 2 + half_perimeter;
        return cout << fixed << setprecision(4) << ans << '\n', 0;
    }

    double ans = n;

    int begin_id = 0, end_id = n-1;
    for(; begin_id < n && s[begin_id] == 'T'; begin_id++);
    for(; end_id >= 0 && s[end_id] == 'T'; end_id--);

    if(begin_id > end_id){
        ans += 1.0 * (n - 1) + 2;
        return cout << fixed << setprecision(4) << ans << '\n', 0;
    }

    ans += (end_id - begin_id + 1);
    ans += max(0, begin_id - 1);
    ans += max(0, n - end_id - 2);
    
    if(begin_id > 0 && s[begin_id] == 'S')  ans += dist_T_S;
    if(begin_id > 0 && s[begin_id] == 'C')  ans = ans - 0.5 + dist_T_C;

    if(end_id < n-1 && s[end_id] == 'S')  ans += dist_T_S;
    if(end_id < n-1 && s[end_id] == 'C')  ans = ans - 0.5 +  dist_T_C;

    if(begin_id == 0){
        if(s[0] == 'S')
            ans = ans + 1;
        if(s[0] == 'C')
            ans = ans - 1 + half_perimeter;
    }else ans += 1;
    if(end_id == n-1){
        if(s[n-1] == 'S')
            ans = ans + 1;
        if(s[n-1] == 'C')
            ans = ans - 1 + half_perimeter;
    }else ans += 1;

    cout << fixed << setprecision(4) << ans << '\n';
}