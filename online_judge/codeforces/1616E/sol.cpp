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

void solve(){
    int n; cin >> n;
    string s, t;
    cin >> s >> t;
    s = ' ' + s;
    t = ' ' + t;
    
    vector <int> G[30];
    for(int i = n; i >= 1; i--)
        G[s[i] - 'a'].push_back(i);

    ll res = LLONG_MAX, cur = 0;
    FenwickTree <int> bonus(n+1);

    int j = 1;
    for(int i = 1; i <= n; i++){
        int minCh = -1;
        for(int j = 0; j < t[i] - 'a'; j++){
            if(G[j].size() == 0)
                continue;
            int index = *G[j].rbegin();
            index += bonus.get(index);
            if(minCh == -1 || minCh > index)
                minCh = index;
        }
        if(minCh >= 0)
            res = min(res, cur + minCh - i);
        
        if(G[t[i] - 'a'].size() == 0)
            break;

        int index = *G[t[i] - 'a'].rbegin();
        cur += (index + bonus.get(index) - i);
        while(j + bonus.get(j) < i)
            j++;
        bonus.update(j, 1);
        bonus.update(index+1, -1);

        G[t[i]-'a'].pop_back();
    }
    if(res == LLONG_MAX)
        cout << -1 << '\n';
    else cout << res << '\n';
}

int main(){
    io
    int t; cin >> t;
    while(t--){
        solve();
    }
}