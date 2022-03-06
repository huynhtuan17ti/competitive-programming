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
const int MAXN = 1e6;
int factor[MAXN + 5];

void build_seive(){
    for(int i = 2; i <= MAXN; i++)
        factor[i] = i;
    for(int i = 4; i <= MAXN; i+=2)
        factor[i] = 2;
    for(int i = 3; i*i <= MAXN; i++)
        if(factor[i] == i)
            for(int j = i*i; j <= MAXN; j+=i)
                if(factor[j] == j)
                    factor[j] = i;
}

vector <int> M[MAXN];

ii F(int val){
    int pre = -1, cnt = 0;
    int G = 0;
    int tmp = val;
    map <int, int> p;
    while(val > 1){
        if(factor[val] != pre){
            if(pre != -1)
                p[pre] = cnt;
            G = __gcd(G, cnt);
            cnt = 0;
        }
        cnt += 1;
        pre = factor[val];
        val /= factor[val];
    }
    if(cnt > 0)
        p[pre] = cnt;
    G = __gcd(G, cnt);
    int mul = 1;
    for(auto it: p){
        int x = it.se/G;
        while(x--)
            mul *= it.fi;
    }
    return {mul, G};
}

void solve(){
    build_seive();
    int n, m;
    cin >> n >> m;
    for(int i = 2; i <= n; i++){
        auto [mul, g] = F(i);
        M[mul].push_back(g);
    }

    auto getBit = [&](int val, int id){
        return (val >> id)&1;
    };

    ll res = 0;

    for(int val = 2; val <= n; val++){
        if(M[val].size() == 0)
            continue;

        int N = M[val].size();
        int maxState = (1<<N);

        int total = 0;

        for(int state = 0; state < maxState; state++){
            int g = 0, minVal = n, cnt = 0;
            for(int i = 0; i < N; i++)
                if(getBit(state, i)){
                    cnt += 1;
                    minVal = min(minVal, M[val][i]);
                    if(g == 0)
                        g = M[val][i];
                    else 
                        g = M[val][i]/__gcd(g, M[val][i]) * g;
                }
            int limit = minVal * m;
            
            if(cnt == 0)
                continue;

            if(cnt % 2 == 1)
                total += limit/g;
            else total -= limit/g;
        }

        res += total;
    }
    cout << res + 1 << '\n';
}

int main(){
    io
    int t = 1;
    while(t--){
        solve();
    }
}