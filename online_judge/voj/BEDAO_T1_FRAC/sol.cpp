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
const int MAXN = 1e7;

int mark[MAXN + 5];

void build_seive(){
    for(int i = 2; i <= MAXN; i++)
        mark[i] = i;
    for(int i = 4; i <= MAXN; i+=2)
        mark[i] = 2;
    for(int i = 3; i*i <= MAXN; i++){
        if(mark[i] == i)
            for(int j = i*i; j <= MAXN; j+=i)
                if(mark[j] == j)
                    mark[j] = i;
    }
}

vii extract(int val){
    vii ans;
    int pre = -1, cnt = 0;
    while(val > 1){
        if(pre != -1 && mark[val] != pre){
            ans.push_back({pre, cnt});
            cnt = 0;
        }
        cnt++;
        pre = mark[val];
        val /= mark[val];
    }
    if(pre > 1)
        ans.push_back({pre, cnt});
    return ans;
}

int sum[MAXN+5], max_val[MAXN+5];

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    build_seive();
    int n; cin >> n;
    vector <int> a(n);
    bool is_zero = false;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x > 0){
            vii p = extract(x);
            for(ii v: p){
                sum[v.fi] += v.se;
                max_val[v.fi] = max(max_val[v.fi], v.se);
            }
        }
        else
            is_zero = true;
    }
    if(is_zero)
        cout << "impossible" << '\n';
    else{
        ll res = 1;
        for(int i = 2; i <= MAXN; i++){
            int cnt = sum[i] - max_val[i];
            while(cnt--)
                res = res*i;
        }
        cout << res << '\n';
    }
}