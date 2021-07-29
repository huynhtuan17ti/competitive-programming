#include <bits/stdc++.h>  
 
using namespace std;
 
const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 103;
const int base1 = 307;
const int base2 = 409;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define mp make_pair
#define fi first
#define se second
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 255
char a[MAXN][MAXN];
bool not_palind[MAXN];
int Hash1[MAXN], Hash2[MAXN];
int powBase[MAXN][2];
int cnt[MAXN][30], cnt_odd[MAXN];

bool is_equal(int i, int j){
    if(i == -1 || j == -1)
        return false;
    if(not_palind[i] || not_palind[j])
        return false;
    return (Hash1[i] == Hash1[j] && Hash2[i] == Hash2[j]);
}

vector <int> prepare(vector <int> s){
    vector <int> res;
    res.push_back(-1);
    res.push_back(0);
    for(int i = 0; i < s.size(); i++){
        res.push_back(s[i]);
        res.push_back(0);
    }
    return res;
}

int manacher(vector <int> s){
    int C = 1, R = 1, n = s.size();
    vector <int> P(n+2);
    int r = 0;
    for (int i = 2; i < n; i++) {
        int i_mirror = 2 * C - i;
        P[i] = (R > i) ? min(R - i, P[i_mirror]) : 0;
        while (i + 1 + P[i] < n && is_equal(s[i - 1 - P[i]], s[i + 1 + P[i]]))
            P[i]++;
        if(!not_palind[s[i]])
            r += (P[i]+1)/2;
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }
    return r;
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    // initialize base
    powBase[0][1] = powBase[0][0] = 1;
    for(int i = 1; i <= 30; i++){
        powBase[i][0] = (1LL*powBase[i-1][0]*base1)%MOD1;
        powBase[i][1] = (1LL*powBase[i-1][1]*base2)%MOD2;
    }
    ll res = 0;
    for(int col1 = 1; col1 <= m; col1++){
        for(int row = 0; row <= n; row++){
            Hash1[row] = 0;
            Hash2[row] = 0;
            fill(cnt[row], cnt[row]+30, 0);
            cnt_odd[row] = 0;
        }
        vector <int> s;
        for(int row = 1; row <= n; row++)
            s.push_back(row);
        s = prepare(s);
        for(int col2 = col1; col2 <= m; col2++){
            for(int row = 1; row <= n; row++)
                not_palind[row] = 0;
            bool has_palind = false;
            for(int row = 1; row <= n; row++){
                int x = a[row][col2] - 'a' + 1;
                cnt[row][x]++;
                Hash1[row] = (Hash1[row] + powBase[x][0])%MOD1;
                Hash2[row] = (Hash2[row] + powBase[x][1])%MOD2;
                if(cnt[row][x]%2 == 1)
                    cnt_odd[row] += 1;
                else cnt_odd[row] = max(0, cnt_odd[row] - 1);
                if((col2 - col1 + 1)%2 == 1 && cnt_odd[row] != 1)
                    not_palind[row] = true;
                if((col2 - col1 + 1)%2 == 0 && cnt_odd[row] != 0)
                    not_palind[row] = true;
                if(!not_palind[row])
                    has_palind = true;
            }
            
            int num_palind = manacher(s);
            if(!has_palind)
                num_palind = 0;
            res += num_palind;
        }
    }
    cout << res;
}