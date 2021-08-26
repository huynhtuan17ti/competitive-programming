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
const int MAXN = 2025;
int a[MAXN];
int pos[MAXN];

vector <int> op;

void _reverse(int l, int r){
    assert(r%2 == 1);
    if(r > 1)
        op.push_back(r);
    reverse(a+l, a+1+r);
    for(int i = l; i <= r; i++)
        pos[a[i]] = i;
}

void solve(){
    int n; cin >> n;
    bool isAns = true;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pos[a[i]] = i;
        if(a[i]%2 != i%2)
            isAns = false;
    }
    op.clear();

    if(!isAns){
        cout << -1 << '\n';
        return;
    }

    for(int val = n; val >= 3; val-=2){
        int val1 = val, val2 = val-1;
        if(pos[val2]+1 < pos[val1]){
            _reverse(1, pos[val1]);
        }
        if(pos[val1]+1 < pos[val2]){
            _reverse(1, pos[val1]);
            _reverse(1, pos[val2]-1);
        }
        if(pos[val1]+1 == pos[val2]){
            _reverse(1, pos[val2]+1);
        }
        if(pos[val1] == pos[val2]+1){
            if(pos[val1] != val){
                _reverse(1, pos[val1]);
                _reverse(1, val);
            }
        }else{
            isAns = false;
            break;
        }
    }
    if(!isAns){
        cout << -1 << '\n';
    }else{
        cout << op.size() << '\n';
        if(op.size() > 0){
            for(int u: op)
                cout << u << ' ';
            cout << '\n';
        }
    }
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int t; cin >> t;
    while(t--){
        solve();
    }
}