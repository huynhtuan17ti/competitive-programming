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

string s;

class SegmentTree{
private:
    struct Node{
        int a, b, c, ab, bc, abc;
        Node(char ch){
            a = b = c = ab = bc = abc = 0;
            if(ch == 'a')
                a = 1;
            if(ch == 'b')
                b = 1;
            if(ch == 'c')
                c = 1;
        }
        Node(){
            a = b = c = ab = bc = abc = 0;
        }
        Node operator + (const Node& other) const{
            Node ans;
            ans.a = a + other.a;
            ans.b = b + other.b;
            ans.c = c + other.c;

            ans.ab = min({ab + other.b, a + other.ab});
            ans.bc = min({b + other.bc, bc + other.c});

            ans.abc = min({a + other.abc, a + other.bc, ab + other.bc, ab + other.c, abc + other.c});
            return ans;
        }
    };
    
    vector <Node> data;

public:
    SegmentTree(int n){
        data.resize(4*n + 5);
    }
    void update(int id, int l, int r, int i){
        if(i < l || r < i)
            return;
        if(l == r && l == i){
            data[id] = Node(s[i]);
            //cerr << i << ' ' << s[i] << ' ' << data[id].a << '\n';
            return;
        }
        int mid = (l+r) >> 1;
        update(2*id, l, mid, i);
        update(2*id+1, mid+1,r, i);
        data[id] = data[2*id] + data[2*id+1];
    }
    Node get(int id, int l, int r, int u, int v){
        if(v < l || r < u)
            return Node();
        if(u <= l && r <= v)
            return data[id];
        int mid = (l+r) >> 1;
        Node L = get(2*id, l, mid, u, v); 
        Node R = get(2*id+1, mid+1, r, u, v);
        return L + R;
    }
};

void solve(){
    int n, q;
    cin >> n >> q;
    cin >> s;
    s = ' ' + s;
    SegmentTree seg(n);
    for(int i = 1; i <= n; i++)
        seg.update(1, 1, n, i);
    while(q--){
        int pos;
        char ch;
        cin >> pos >> ch;
        s[pos] = ch;
        seg.update(1, 1, n, pos);
        cout << seg.get(1, 1, n, 1, n).abc << '\n';
    }
}

int main(){
    io
    int t = 1;
    while(t--){
        solve();
    }
}