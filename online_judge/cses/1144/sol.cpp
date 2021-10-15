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

struct query{
    int t;
    int a, b;
};

template <typename T>
class FenwickTree{
    vector <T> fenw;
    int n;
    public:
        void initialize(int _n){
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

int main(){
    io
    int n, q;
    cin >> n >> q;
    vector <int> p(n+1);
    vector <int> S;
    for(int i = 1; i <= n; i++){
        cin >> p[i];
        S.push_back(p[i]);
    }
    vector <query> queries;
    while(q--){
        char ch;
        cin >> ch;
        if(ch == '!'){
            int k, x;
            cin >> k >> x;
            S.push_back(x);
            queries.push_back({0, k, x});
        }else{
            int a, b;
            cin >> a >> b;
            S.push_back(a); S.push_back(b);
            queries.push_back({1, a, b});
        }
    }

    // compression
    sort(S.begin(), S.end());
    S.resize(unique(S.begin(), S.end()) - S.begin());
    int len = S.size();

    auto getIndex = [&](int val){
        return lower_bound(S.begin(), S.end(), val) - S.begin() + 1;
    };

    FenwickTree <int> fenw;
    fenw.initialize(len);
    for(int i = 1; i <= n; i++){
        int id = getIndex(p[i]);
        fenw.update(id, 1);        
    }

    for(query q: queries){
        if(q.t == 0){
            fenw.update(getIndex(p[q.a]), -1);
            p[q.a] = q.b;
            fenw.update(getIndex(p[q.a]), 1);
        }else{
            cout << fenw.get(getIndex(q.b)) - fenw.get(getIndex(q.a) - 1) << '\n';
        }
    }
}