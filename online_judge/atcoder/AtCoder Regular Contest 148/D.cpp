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
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n, m; cin >> n >> m;
    map <int, int> cnt;
    for(int i = 1; i <= 2*n; i++){
        int x; cin >> x;
        cnt[x]++;
        cnt[x] %= 2;
    }
    stack <int> st;
    for(auto e: cnt){
        if(e.se % 2 == 1){
            st.push(e.fi);
        }
    }
    if(m%2 == 1){
        return cout << ((st.empty())? "Bob" : "Alice") << '\n', 0;
    }
    /*
        If m is even, create all edges of [u, v = (u + m/2) mod m] if u and v exist in st (cnt[u] = 1 and cnt[v] = 1)
        if number of edges is even then Bob will win else Alice
    */
    int nEdge = 0;
    while(!st.empty()){
        int u = st.top();
        st.pop();
        if(cnt[u] == 0)
            continue;
        int v = (u + m/2)%m;
        if(cnt[v] == 0)
            return cout << "Alice", 0;
        cnt[v] = 0;
        nEdge++;
    }
    // nEdge must be even so Bob can win, 
    // Assume its odd then the sum Alice can be (x + m/2, y + m/2, z + m/2), whereas Bob is (x, y, z)
    // => Alice sum mod m = (x + y + z + m/2) % m
    cout << ((nEdge%2 == 0)? "Bob" : "Alice");
}