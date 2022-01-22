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
    bool ok = false;
    map <string, int> Min[4], Max[4];
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        int len = s.size();
        if(Min[len].find(s) == Min[len].end())
            Min[len][s] = i;
        Max[len][s] = i;
        if(s.size() == 1)
            ok = true;
        if(s.size() == 2 && s[0] == s[1])
            ok = true;
        if(s.size() == 3 && s[0] == s[2])
            ok = true;
    }
    if(ok){
        cout << "YES" << '\n';
        return;
    }
    for(int t = 2; t <= 3; t++){
        for(auto it: Min[t]){
            string rev = it.fi;
            reverse(rev.begin(),rev.end());
            int id = Max[t][rev];
            if(it.se < id){
                ok = true;
                break;
            }
        }
    }
    
    for(auto it: Min[3]){
        string rev = "";
        rev += it.fi[1]; rev += it.fi[0];
        int id = Max[2][rev];
        if(it.se < id){
            ok = true;
            break;
        }
    }

    for(auto it: Max[3]){
        string rev = "";
        rev += it.fi[2]; rev += it.fi[1];
        if(Min[2].find(rev) == Min[2].end())
            continue;
        int id = Min[2][rev];
        if(it.se > id){
            ok = true;
            break;
        }
    }

    if(ok)
        cout << "YES" << '\n';
    else cout << "NO" << '\n';
}

int main(){
    io
    int t; cin >> t;
    while(t--){
        solve();
    }
}