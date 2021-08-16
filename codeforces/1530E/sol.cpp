#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
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
 

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        vector <int> G(30);
        for(int i = 0; i < s.size(); i++){
            G[s[i] - 'a'] += 1;
        }
        vector <int> valid;
        for(int i = 0; i < 30; i++)
            if(G[i])
                valid.push_back(i);
        if(valid.size() == 1){
            cout << s << '\n';
            continue;
        }
        int special = -1;
        for(int u: valid)
            if(G[u] == 1){
                special = u;
                break;
            }
        if(special != -1){
            string res = "";
            res += (char)(special + 'a');
            G[special]--;
            for(int i = 0; i < valid.size(); i++){
                while(G[valid[i]] > 0){
                    res += (char)(valid[i] + 'a');
                    G[valid[i]]--;
                }
            }
            cout << res << '\n';
            continue;
        }
        if(G[valid[0]] - 2 <= (int)s.size() - G[valid[0]]){
            string res = "";
            int cnt_valid_0 = G[valid[0]];
            for(int cnt = 0; cnt < min(2, cnt_valid_0); cnt++){
                res += (char)(valid[0] + 'a');
                G[valid[0]]--;
            }
            for(int i = 1; i < valid.size(); i++){
                while(G[valid[i]] > 0){
                    res += (char)(valid[i] + 'a');
                    G[valid[i]]--;
                    if(G[valid[0]] > 0){
                        res += (char)(valid[0] + 'a');
                        G[valid[0]]--;
                    }
                }
            }
            cout << res << '\n';
            continue;
        }else{
            if(valid.size() > 2){
                string res = "";
                res += (char)(valid[0] + 'a');
                res += (char)(valid[1] + 'a');
                G[valid[0]]--; G[valid[1]]--;
                while(G[valid[0]] > 0){
                    res += (char)(valid[0] + 'a');
                    G[valid[0]]--;
                }
                res += (char)(valid[2] + 'a');
                G[valid[2]]--;
                for(int i = 1; i < valid.size(); i++){
                    while(G[valid[i]] > 0){
                        res += (char)(valid[i] + 'a');
                        G[valid[i]]--;
                    }
                }
                cout << res << '\n';
                continue;
            }else{
                string res = "";
                res += (char)(valid[0] + 'a');
                G[valid[0]]--;
                while(G[valid[1]] > 0){
                    res += (char)(valid[1] + 'a');
                    G[valid[1]]--;
                }
                while(G[valid[0]] > 0){
                    res += (char)(valid[0] + 'a');
                    G[valid[0]]--;
                }
                cout << res << '\n';
                continue;
            }
        }
    }
}