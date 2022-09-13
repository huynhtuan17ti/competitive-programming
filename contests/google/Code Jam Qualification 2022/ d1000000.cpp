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
const int MAXN = 1e6 + 5;

vector <int> a(MAXN);

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int t; cin >> t;
    for(int iTest = 1; iTest <= t; iTest++){
        int n; cin >> n;
        fill(a.begin(), a.end(), 0);
        vector <int> p;
        for(int i = 1; i <= n; i++){
            int s; cin >> s;
            p.push_back(s);
        }
        sort(p.begin(), p.end());
        int res = 0;
        int j = 0;
        for(int i = 1; i <= MAXN; i++){
            while(j < n && i > p[j])
                j++;
            if(j == n){
                res = i-1;
                break;
            }
            j++;
        }
        cout << "Case #" << iTest << ": " << res << '\n';
    }
}