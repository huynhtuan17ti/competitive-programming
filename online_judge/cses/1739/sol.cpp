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

class FenwickTree2D{
private:
    vector <vector <int>> data;
    int n;
public:
    FenwickTree2D(int n){
        data.resize(n+1);
        for(int i = 0; i <= n; i++)
            data[i].resize(n+1);
        this->n = n;
    }
    void update(int u, int v, int val){
        for(int i = u; i <= n; i += i&(-i))
            for(int j = v; j <= n; j += j&(-j))
                data[i][j] += val;
    }
    int get(int u, int v){
        int ans = 0;
        for(int i = u; i >= 1; i -= i&(-i))
            for(int j = v; j >= 1; j -= j&(-j))
                ans += data[i][j];
        return ans;
    }
public:
    int query(int x, int y, int u, int v){
        return get(u, v) - get(u, y-1) - get(x-1, v) + get(x-1, y-1);
    }
};

int main(){
    io
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    FenwickTree2D fenw(n);
    vector <vector <int>> a(n+1);
    for(int i = 0; i <= n; i++)
        a[i].resize(n+1);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            char ch; cin >> ch;
            a[i][j] = (ch == '*');
            if(ch == '*')
                fenw.update(i, j, 1);
        }
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int u, v;
            cin >> u >> v;
            a[u][v] = 1 - a[u][v];
            if(a[u][v] == 1)
                fenw.update(u, v, 1);
            else fenw.update(u, v, -1);
        }else{
            int x, y, u, v;
            cin >> x >> y >> u >> v;
            cout << fenw.query(x, y, u, v) << '\n';
        }
    }
}