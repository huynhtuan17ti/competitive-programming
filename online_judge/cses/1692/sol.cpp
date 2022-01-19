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

vii G[MAXN];

int main(){
    io
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int n; cin >> n;
    n--;
    int maxVal = (1<<n)-1;
    
    auto getBit = [&](int x, int i)->int{
        return (x >> i)&1;
    };

    auto rmBit = [&](int x) -> int{
        return x - (1<<(n-1)) * getBit(x, n-1);
    };

    auto toString = [&](int val) -> string{
        string ans = "";
        for(int i = n-1; i >= 0; i--)
            ans += to_string(getBit(val, i));
        return ans;
    };

    for(int i = 0; i <= maxVal; i++){
        int next = (rmBit(i)<<1);
        G[i].push_back({next, 0});
        G[i].push_back({next + 1, 1});
    }

    string path = "";
    typedef pair <int, char> pack;
    stack <pack> st;
    st.push({0, '#'});
    while(!st.empty()){
        auto [u, c] = st.top();
        if(G[u].size() == 0){
            if(c != '#')
                path += c;
            st.pop();
        }else{
            auto [v, w] = G[u].back(); G[u].pop_back();
            st.push({v, (char)(w + '0')});
        }
    }
    path += toString(0);
    cout << path << '\n';
}