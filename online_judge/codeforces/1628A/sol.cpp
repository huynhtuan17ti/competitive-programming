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

void solve(){
    int n; cin >> n;
    vector <int> a(n+1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    vector <int> LMex(n+1), RMex(n+1);
    vector <int> cnt(n+1);
    int curMex = 0;
    for(int i = n; i >= 1; i--){
        cnt[a[i]] = 1;
        while(cnt[curMex] == 1)
            curMex++;
        RMex[i] = curMex;
    }

    vector <int> b;
    int id = 1;
    while(id <= n){
        int MEX = RMex[id];
        int curMex = 0;
        map <int, bool> M;
        do{
            M[a[id]] = 1;
            while(M[curMex])
                curMex++;
            id++;
        }while(id <= n && curMex < MEX);
        b.push_back(MEX);
    }
    cout << b.size() << '\n';
    for(int u: b)
        cout << u << ' ';
    cout << '\n';
}

int main(){
    io
    int t; cin >> t;
    while(t--){
        solve();
    }
}