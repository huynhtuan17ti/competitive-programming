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
const int MAXN = 3e5 + 5;

vector <int> owner[MAXN];
stack <int> bucket[MAXN];

struct query{
    int l, r, val;
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

        void reset(){
            fill(fenw.begin(), fenw.end(), 0);
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

        void apply(query q){
            if(q.l <= q.r){
                update(q.l, q.val);
                update(q.r+1, -q.val);
            }else{
                update(1, q.val);
                update(q.r+1, -q.val);
                update(q.l, q.val);
            }
        }
};

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x;
        cin >> x;
        owner[x].push_back(i);
    }
    vector <ll> Max(n+1);
    for(int i = 1; i <= n; i++){
        cin >> Max[i];
    }

    int q;
    cin >> q;
    vector <query> Q(q+1);
    for(int i = 1; i <= q; i++){
        int l, r, val;
        cin >> l >> r >> val;
        Q[i] = {l, r, val};
    }

    // parallel binary search
    FenwickTree <ll> fenw;
    fenw.initialize(m);
    vector <int> L(n+1, 1);
    vector <int> R(n+1, q);
    bool isLoop = true;
    while(isLoop){
        fenw.reset();

        isLoop = false;
        for(int i = 1; i <= n; i++){
            if(L[i] > R[i])
                continue;
            int mid = (L[i] + R[i])>>1;
            //cerr << i << ' ' << L[i] << ' ' << R[i] << ' ' << mid << '\n';
            bucket[mid].push(i);
        }
        for(int i = 1; i <= q; i++){
            
            fenw.apply(Q[i]);

            while(!bucket[i].empty()){
                isLoop = true;
                int u = bucket[i].top();
                bucket[i].pop();

                ll total = 0;
                for(int sector: owner[u]){
                    total += fenw.get(sector);
                    if(total >= Max[u])
                        break;
                }
                if(total >= Max[u])
                    R[u] = i-1;
                else
                    L[u] = i+1;
                
            }
        }
    }

    for(int i = 1; i <= n; i++){
        if(R[i]+1 <= q)
            cout << R[i]+1 << '\n';
        else cout << "NIE" << '\n';
    }
}