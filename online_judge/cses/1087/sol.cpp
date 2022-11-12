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
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
const int MAXN = 5e5 + 5;
int main(){
    io
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    string s; cin >> s;
    set<char> st;
    string res = "";
    for(char ch: s) {
        st.insert(ch);
        if(st.size() == 4) {
            res += ch;
            st.clear();
        }
    }
    for(char ch: "ACTG")
        if(!st.count(ch)) {
            res += ch;
            break;
        }
    cout << res << '\n';
}