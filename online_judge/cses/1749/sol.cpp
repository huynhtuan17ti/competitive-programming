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

class FenwickTree{
private:
    vector <int> data;
    int n;
public:
    FenwickTree(int n){
        data.resize(n+1);
        this->n = n;
    }
    void update(int i, int val){
        while(i <= n){
            data[i] += val;
            i += i&(-i);
        }
    }
    int get(int i){
        int ans = 0;
        while(i >= 1){
            ans += data[i];
            i -= i&(-i);
        }
        return ans;
    }
};

int main(){
    io
    int n; cin >> n;
    FenwickTree fenw(n);
    vector <int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        fenw.update(i, 1);
    }

    auto get = [&](int pos) -> int{
        int l = 1, r = n;
        while(l <= r){
            int mid = (l+r) >> 1;
            if(fenw.get(mid) >= pos)
                r = mid - 1;
            else l = mid + 1;
        }
        return r + 1;
    };

    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        int p = get(x);
        cout << a[p] << ' ';
        fenw.update(p, -1);
    }
}