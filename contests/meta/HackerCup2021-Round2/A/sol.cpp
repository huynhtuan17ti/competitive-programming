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
const int MAXN = 5e5 + 5;

struct bucket{
    int val, change;
};

bool operator > (const bucket &A, const bucket &B){
    if(A.val == B.val)
        return A.change < B.change;
    return A.val > B.val;
} 

void solve(int iTest){
    int n, m;
    cin >> n >> m;
    vector <int> s(m+1);
    vector <int> S;
    for(int i = 1; i <= m; i++){
        cin >> s[i];
        S.push_back(s[i]);
    }
    vector <vector <int>> p(n+1);
    for(int i = 0; i <= n; i++)
        p[i].resize(m+1);
    for(int i = 1; i <= m; i++){
        p[0][i] = s[i];
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> p[i][j];
            S.push_back(p[i][j]);
        }
    }

    sort(S.begin(), S.end());
    S.resize(unique(S.begin(), S.end()) - S.begin());
    for(int i = 1; i <= m; i++)
        s[i] = lower_bound(S.begin(), S.end(), s[i]) - S.begin();
    
    for(int i = 0; i <= n; i++)
        for(int j = 1; j <= m; j++)
            p[i][j] = lower_bound(S.begin(), S.end(), p[i][j]) - S.begin();



    vector <vector <int>> M(S.size()+1);
    for(int i = 1; i <= m; i++){
        M[s[i]].push_back(1);
    }
    int res = 0;
    for(int i = 1; i <= n; i++){
        vector <int> a;
        vii b;
        for(int j = 1; j <= m; j++){
            int val = p[i][j];
            if(M[val].size() > 0){
                b.push_back({val, M[val].back()});
                M[val].pop_back();
            }else a.push_back(val);
        }

        int cnt = 0;
        for(int j = 1; j <= m; j++){
            int val = p[i-1][j];
            while(M[val].size() > 0){
                cnt += M[val].back();
                M[val].pop_back();
            }
        }

        for(int j = 1; j <= m; j++){
            int val = p[i-1][j];
            M[val].clear();
        }

        sort(b.begin(), b.end(), [](const ii &A, const ii &B){
            return A.se > B.se;
        });

        for(ii u: b)
            M[u.fi].push_back(u.se);

        for(int u: a){
            res++;
            M[u].push_back(0);
        }
        res -= cnt;
    }
    cout << "Case #" << iTest << ": " << res << '\n';
}

int main(){
    io
    freopen("runway_input.txt", "r", stdin);
    //freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int t; cin >> t;
    for(int iTest = 1; iTest <= t; iTest++){
        solve(iTest);
    }
}