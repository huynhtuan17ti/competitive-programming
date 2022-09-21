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
const int MAXN = 2005;

int dp[MAXN][MAXN];

template <typename T>
class FenwickTree{
private:
    vector <T> fenw;
    int n;
public:
    FenwickTree(int _n){
        this->n = _n;
        fenw.resize(n+1);
    }

    void update(int id, T val) {
        while (id <= n) {
            fenw[id] += val;
            if(fenw[id] > MOD)
                fenw[id] -= MOD;
            id += id&(-id);
        }
    }

    T get(int id){
        T ans{};
        while(id >= 1){
            ans += fenw[id];
            if(ans > MOD)
                ans -= MOD;
            id -= id&(-id); 
        }
        return ans;
    }
};

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n; cin >> n;
    vii p(n+1);
    p[0].fi = INT_MAX;
    for(int i = 1; i <= n; i++)
        cin >> p[i].fi;
    vector <int> s;
    s.push_back(INT_MIN);
    for(int i = 1; i <= n; i++){
        cin >> p[i].se;
        s.push_back(p[i].se);
    }
    sort(s.begin(), s.end());
    sort(p.begin(), p.end(), greater<ii>());
    
    for(auto &[u, v]: p){
        v = lower_bound(s.begin(), s.end(), v) - s.begin();
    }
    
    vector <FenwickTree<int>*> fenws(n+1);
    for(int i = 0; i <= n; i++)
        fenws[i] = new FenwickTree<int>(n);

    // dp[i][x] += dp[j][x-1];
    dp[0][0] = 1;
    fenws[0]->update(1, 1);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] += fenws[j-1]->get(p[i].se);
            if(dp[i][j] > MOD)
                dp[i][j] -= MOD;
            fenws[j]->update(p[i].se+1, dp[i][j]);
        }
    }
    for(int k = 1; k <= n; k++){
        int ans = 0;
        for(int i = 1; i <= n; i++){
            ans += dp[i][k];
            if(ans > MOD)   ans -= MOD;
        }
        cout << ans << " \n"[k == n];
    }
}