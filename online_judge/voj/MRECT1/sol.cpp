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
const int MAXN = 3e5+5;

vector <int> S[2];

// utils
vector <int> compress(int t){
    S[t].push_back(INT_MIN); // to base 1
    S[t].push_back(INT_MAX);
    sort(S[t].begin(), S[t].end());
    S[t].resize(unique(S[t].begin(), S[t].end()) - S[t].begin());
    return S[t];
}

int norm(int t, int val){
    return lower_bound(S[t].begin(), S[t].end(), val) - S[t].begin();
}

vector <int> arr[2][MAXN];

void compress_arr(int len_x, int len_y){
    for(int i = 0; i < len_x; i++){
        arr[0][i].push_back(INT_MIN); // to base 1
        arr[0][i].push_back(INT_MAX);
        sort(arr[0][i].begin(), arr[0][i].end());
        arr[0][i].resize(unique(arr[0][i].begin(), arr[0][i].end()) - arr[0][i].begin());
    }
    
    for(int i = 0; i < len_y; i++){
        arr[1][i].push_back(INT_MIN); // to base 1
        arr[1][i].push_back(INT_MAX);
        sort(arr[1][i].begin(), arr[1][i].end());
        arr[1][i].resize(unique(arr[1][i].begin(), arr[1][i].end()) - arr[1][i].begin());
    }
}

int get_range(int type, int pos, int l, int r){
    int R = upper_bound(arr[type][pos].begin(), arr[type][pos].end(), r) - arr[type][pos].begin() - 1;
    int L = lower_bound(arr[type][pos].begin(), arr[type][pos].end(), l) - arr[type][pos].begin();
    return max(0, R-L+1);
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n; cin >> n;
    vii points;
    map <ii, int> M;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        S[0].push_back(x);
        S[0].push_back(x-1);
        S[1].push_back(y);
        S[1].push_back(y-1);
        points.push_back({x, y});
    }
    vector <pair <ii, ii>> recs;
    int P; cin >> P;
    while(P--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        recs.push_back({mp(x1, y1), mp(x2, y2)});
    }
    
    compress(0);
    compress(1);

    for(ii p: points){
        p.fi = norm(0, p.fi);
        p.se = norm(1, p.se);
        //cout << p.fi << ' '<< p.se << '\n';
        M[p] += 1;
        arr[0][p.fi].push_back(p.se);
        arr[1][p.se].push_back(p.fi);
    }
    compress_arr((int)S[0].size(), (int)S[1].size());
    for(pair <ii, ii> rec: recs){
        int x1, y1, x2, y2;
        x1 = rec.fi.fi;
        y1 = rec.fi.se;
        x2 = rec.se.fi;
        y2 = rec.se.se;

        x1 = norm(0, x1);
        y1 = norm(1, y1);
        x2 = norm(0, x2);
        y2 = norm(1, y2);
        //cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
        int ans =  get_range(0, x1, y1, y2) + get_range(0, x2, y1, y2)
                + get_range(1, y1, x1, x2) + get_range(1, y2, x1, x2);
        //cout << ans << '\n';
        ans -= (M[mp(x1, y1)] + M[mp(x1, y2)] + M[mp(x2, y1)] + M[mp(x2, y2)]);
        cout << ans << '\n';
    }
}