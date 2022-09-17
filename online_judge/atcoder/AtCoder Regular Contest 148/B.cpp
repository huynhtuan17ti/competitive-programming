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
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n; cin >> n;
    string s; cin >> s;

    auto rotate = [&](string t, int l, int r){
        for(int i = l; i <= r; i++){
            t[i] = (s[r - (i - l)] == 'd')? 'p' : 'd';
        }
        return t;
    };

    int start_id;
    for(start_id = 0; s[start_id] == 'd'; start_id++);

    string res = s;
    for(int id = start_id; id < n; id++){
        string t = rotate(s, start_id, id);
        res = min(res, t);
    }

    cout << res << '\n';
}