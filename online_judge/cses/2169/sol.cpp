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
const int MAXN = 500005;

template <typename T>
class FenwickTreeLeft{
private:
    vector <T> fenw;
    int n;
public:
    FenwickTreeLeft(int _n){
        this->n = _n;
        fenw.resize(n+1, 0);
    }

    void update(int id, T val) {
        while (id <= n) {
            fenw[id] += val;
            id += id&(-id);
        }
    }

    T get(int id){
        T ans{};
        while(id >= 1){
            ans += fenw[id];
            id -= id&(-id); 
        }
        return ans;
    }
};


template <typename T>
class FenwickTreeRight{
private:
    vector <T> fenw;
    int n;
public:
    FenwickTreeRight(int _n){
        this->n = _n;
        fenw.resize(n+1, 0);
    }

    void update(int id, T val) {
        while (id >= 1) {
            fenw[id] += val;
            id -= id&(-id);
        }
    }

    T get(int id){
        T ans{};
        while(id <= n){
            ans += fenw[id];
            id += id&(-id); 
        }
        return ans;
    }
};

struct range{
    int l, r, id;
};

int main(){
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    io
    int n; cin >> n;
    vector <range> ranges(n);
    vector <int> S;
    for(int i = 0; i < n; i++){
        cin >> ranges[i].l >> ranges[i].r;
        ranges[i].id = i;
        S.push_back(ranges[i].l);
        S.push_back(ranges[i].r);
    }

    S.push_back(INT_MIN);
    sort(S.begin(), S.end());
    S.resize(unique(S.begin(), S.end()) - S.begin());

    for(auto& [u, v, id]: ranges){
        u = lower_bound(S.begin(), S.end(), u) - S.begin();
        v = lower_bound(S.begin(), S.end(), v) - S.begin();
        //cout << u << ' ' << v << '\n';
    }

    sort(ranges.begin(), ranges.end(), [](const range &A, const range &B){
        return (A.r - A.l) < (B.r - B.l);
    });

    FenwickTreeLeft <int>* fenwL = new FenwickTreeLeft<int>(S.size() + 1);
    FenwickTreeRight <int>* fenwR = new FenwickTreeRight<int>(S.size() + 1);

    vector <vector <int>> ans(2, vector <int> (n));

    int curLen = 0;
    for(auto& [u, v, id]: ranges){
        //cout << u << ' ' << v << ' ' << id << '\n';
        int cnt = curLen - fenwL->get(u-1) - fenwR->get(v+1);
        ans[0][id] = cnt;
        fenwL->update(u, 1);
        fenwR->update(v, 1);
        curLen++;
    }

    fenwL = new FenwickTreeLeft<int>(S.size() + 1);
    fenwR = new FenwickTreeRight<int>(S.size() + 1);

    sort(ranges.begin(), ranges.end(), [](const range &A, const range &B){
        return (A.r - A.l) > (B.r - B.l);
    });

    curLen = 0;
    for(auto& [u, v, id]: ranges){
        int cnt = curLen - fenwR->get(u+1) - fenwL->get(v-1);
        ans[1][id] = cnt;
        fenwR->update(u, 1);
        fenwL->update(v, 1);
        curLen++;
    }

    for(int t = 0; t <= 1; t++)
        for(int i = 0; i < n; i++)
            cout << ans[t][i] << " \n"[i == n-1];
}