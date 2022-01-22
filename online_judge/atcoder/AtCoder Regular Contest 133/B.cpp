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
vector <int> G[MAXN];

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
        T ans = 0;
        while(id >= 1){
            ans = max(ans, fenw[id]);
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
    vector <int> P(n+1), Q(n+1);
    vector <int> id(n+1);
    for(int i = 1; i <= n; i++){
        cin >> P[i];
        id[P[i]] = i;
    }
    for(int i = 1; i <= n; i++){
        cin >> Q[i];
        int val = Q[i];
        for(int j = 1; j*j <= val; j++)
            if(val%j == 0){
                G[i].push_back(id[j]);
                if(j*j != val)
                    G[i].push_back(id[val/j]);
            }
        sort(G[i].begin(), G[i].end(), greater <int>());
    }
    int res = 0;
    FenwickTree <int> fenw(n);
    for(int i = 1; i <= n; i++){
        for(int v: G[i]){
            int preBest = fenw.get(v);
            int curBest = preBest + 1;
            //cout << i << ' ' << v << ' ' << curBest << '\n';
            res = max(res, curBest);
            fenw.update(v+1, curBest);
        }
    }

    cout << res << '\n';
}