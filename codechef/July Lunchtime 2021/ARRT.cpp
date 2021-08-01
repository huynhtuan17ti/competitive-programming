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

bool compare (vector <int> a, vector <int> b){
    for(int i = 0; i < a.size(); i++){
        if(a[i] < b[i])
            return true;
        if(a[i] > b[i])
            return false;
    }
    return true;
}

int main(){
    io
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector <int> a(n), b(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];
        vector <vector <int>> G(n);
        for(int i = 0; i < n; i++){
            cin >> b[i];
            b[i] %= n;
            G[b[i]].push_back(i);
        }
        if(n == 1){
            cout << (a[0] + b[0])%n << '\n';
            continue;
        }
        // find min
        int Min = INT_MAX, val;
        for(int i = 0; i < n; i++){
            if((a[0] + b[i])%n < Min){
                Min = (a[0] + b[i])%n;
                val = b[i];
            }
        }
        vector <vector <int>> res;
        for(int u: G[val]){
            vector <int> ans;
            int pos_a = 0;
            ans.push_back((a[pos_a] + b[u])%n);
            int pos = (u+1)%n;
            while(pos != u){
                pos_a += 1;
                ans.push_back((a[pos_a] + b[pos])%n);
                pos = (pos + 1)%n;
            }
            res.push_back(ans);
        }
        if(res.size() == 1){
            for(int u: res[0])
                cout << u << ' ';
            cout << '\n';
        }else{
            if(compare(res[0], res[1])){
                for(int u: res[0])
                    cout << u << ' ';
                cout << '\n';
            }else{
                for(int u: res[1])
                    cout << u << ' ';
                cout << '\n';
            }
        }
    }
}