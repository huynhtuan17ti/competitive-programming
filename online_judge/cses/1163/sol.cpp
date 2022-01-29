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

int main(){
    io
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int x, n;
    cin >> x >> n;
    set <int> s;
    s.insert(0);
    s.insert(x);
    stack <int> st;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        st.push(x);
        s.insert(x);
    }
    int ans = 0;
    int pre = -1;
    for(auto it: s){
        if(pre != -1)
            ans = max(ans, it - pre);
        pre = (it);
    }
    stack <int> res;
    while(!st.empty()){
        int u = st.top(); st.pop();
        auto it = s.find(u);
        res.push(ans);

        // remove u and update
        int r = *(++it);
        it--; it--;
        int l = *it;
        ans = max(ans, r - l);
        it++;
        s.erase(it);
    }
    while(!res.empty()){
        int u = res.top(); res.pop();
        cout << u << ' ';
    }
}