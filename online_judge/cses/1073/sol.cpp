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
            fenw[id] = max(fenw[id], val);
            id += id&(-id);
        }
    }

    T get(int id){
        T ans{};
        while(id >= 1){
            ans = max(ans, fenw[id]);
            id -= id&(-id); 
        }
        return ans;
    }
};

int main(){
    io
    int n; cin >> n;
    vector <int> S;
    vector <int> a(n);
    for(int &x: a){
        cin >> x;
        S.push_back(x);
    }
    S.push_back(INT_MIN);
    sort(S.begin(), S.end());
    S.resize(unique(S.begin(), S.end()) - S.begin());
    FenwickTree <int> fenw(n+1);
    int ans = 0;
    for(int x: a){
        x = lower_bound(S.begin(), S.end(), x) - S.begin();
        int curMax = fenw.get(x) + 1;
        fenw.update(x, curMax);
        ans = max(ans, curMax);
    }
    cout << ans << '\n';
}