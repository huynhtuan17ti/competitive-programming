#include <bits/stdc++.h>

using namespace std;
const int MOD = 5000000;
const int MAXK = 50 + 5;
const int MAXVAL = 1e5;

/*
    Call dp[i][p] is number of p-length increasing sequence at position i
    dp[0][0] = 1
    dp[i][p] += dp[j][p-1] if a[j] < a[i] for p in [1, k]
*/

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
                fenw[id] %= MOD;
                id += id&(-id);
            }
        }

        T get(int id){
            T ans{};
            while(id >= 1){
                ans += fenw[id];
                ans %= MOD;
                id -= id&(-id); 
            }
            return ans;
        }
};

void compress(vector <int> &S){
    S.push_back(INT_MIN); //avoid 0-base
    sort(S.begin(), S.end());
    S.resize(unique(S.begin(), S.end()) - S.begin());
}

FenwickTree<int> fenw[MAXK];

int main(){
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    vector <int> S;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        S.push_back(a[i]);
    }
    compress(S);
    for(int i = 0; i <= k; i++)
        fenw[i].initialize(MAXVAL);
    
    // initialize dp level 0
    fenw[0].update(1, 1);

    int res = 0;
    for(int i = 0; i < n; i++){
        int val = lower_bound(S.begin(), S.end(), a[i]) - S.begin();
        for(int j = k; j >= 1; j--){
            int ans = fenw[j-1].get(val);
            if(ans > 0)
                fenw[j].update(val+1, ans);

            if(j == k){
                res = (res + ans)%MOD;
            }
        }
    }
    cout << res << '\n';
}