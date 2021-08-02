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

int cnt[5][5];

int findBoundary(ii a, ii b){
    if(a.fi == b.fi && a.se == b.se)
        return 0;
    return 2;
}

ll nCk(int n, int k){
    if(k == 1)
        return n;
    if(k == 2)
        return 1LL*n*(n-1)/2;
    if(k == 3)
        return 1LL*n*(n-1)*(n-2)/6;
}

ll numWay(ii a, ii b, ii c){
    vii tmp;
    tmp.push_back(a);
    tmp.push_back(b);
    tmp.push_back(c);
    sort(tmp.begin(), tmp.end());
    int num = 0;
    ll ans = 1;
    for(int i = 0; i < tmp.size(); i++){
        num++;
        int _num = cnt[tmp[i].fi][tmp[i].se];
        if((i < tmp.size()-1 && tmp[i] != tmp[i+1]) || i == tmp.size()-1){
            ans *= nCk(_num, num);
            num = 0;
        }
    }
    return ans;
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        x = x%4;
        y = y%4;
        cnt[x][y]++;
    }
    /* Pick Theorem
        I = S - (B/2) + 1
        number of integer points on an edge: gcd(|ax - bx|, |ay - by|) - 1
    */
    vii f;
    f.push_back(mp(0, 0));
    f.push_back(mp(0, 2));
    f.push_back(mp(2, 0));
    f.push_back(mp(2, 2));
    ll res = 0;
    for(int i = 0; i < f.size(); i++)
        for(int j = i; j < f.size(); j++)
            for(int k = j; k < f.size(); k++){
                ii p1 = f[i]; ii p2 = f[j]; ii p3 = f[k]; 
                int b1 = findBoundary(p1, p2);
                int b2 = findBoundary(p2, p3);
                int b3 = findBoundary(p1, p3);
                int total_b = (b1 + b2 + b3)%4;
                if(total_b > 0)
                    break;
                res += numWay(p1, p2, p3);
            }
    cout << res << '\n';
}