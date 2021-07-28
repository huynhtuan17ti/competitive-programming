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
#define MAXN 200005
int b[MAXN], _vi[MAXN];
vector <int> re;
vector <int> idx;

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector <int> a(n+1);
        fill(b, b+n+1, 0);
        fill(_vi, _vi+1+n, 0);
        vector <bool> vi(n+1, false);
        re.clear(); idx.clear();
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            if(!vi[a[i]]){
                vi[a[i]] = true;
                b[i] = a[i];
            }else idx.push_back(i);
        }
        for(int i = 1; i <= n; i++)
            if(!vi[i])
                re.push_back(i);
        
        if(re.size() == 1 && re[0] == idx[0]){
            for(int i = 1; i <= n; i++)
                if(b[i] == a[idx[0]]){
                    b[idx[0]] = a[idx[0]];
                    b[i] = 0;
                    idx[0] = i;
                    break;
                }
        }
        
        bool is_res = false;
        while(!is_res){
            random_shuffle(re.begin(), re.end());
            is_res = true;
            for(int i = 0; i < re.size(); i++){
                if(re[i] == idx[i]){
                    is_res = false;
                    break;
                }
            }
        }
        for(int i = 0; i < re.size(); i++)
            b[idx[i]] = re[i];

        cout << n - re.size() << '\n';
        for(int i = 1; i <= n; i++)
            cout << b[i] << " \n"[i == n];     
    }
}