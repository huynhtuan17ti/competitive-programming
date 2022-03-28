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
 
int G[MAXN];
 
int main(){
    io
    int n, b;
    cin >> n >> b;
    map <string, int> decode;
    for(int i = 1; i <= n; i++){
        string s; cin >> s;
        decode[s] = i;
    }
    while(b--){
        int m;
        string s;
        cin >> m >> s;
        while(m--){
            int cost, k;
            cin >> cost >> k;
            cost /= k;
            while(k--){
                string t;
                cin >> t;
                G[decode[t]] -= cost;
                G[decode[s]] += cost;
            }
        }
    }
 
    int sum = 0;
    for(int i = 1; i <= n; i++){
        if(G[i] > 0)
            sum += G[i];
    }
 
    int minEdge = n;
    vector <int> p(n);
    for(int i = 0; i < n; i++)  p[i] = i+1;
    do{
        int cur = 0, cnt = 0;
        for(int i = 0; i < n; i++){
            cur += G[p[i]];
            cnt += (cur == 0);
        }
        minEdge = min(minEdge, n - cnt);
    }while(next_permutation(p.begin(), p.end()));
    cout << sum << ' ' << minEdge << '\n';
}