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
    int h, w, k;
    cin >> h >> w >> k;
    vector <int> a(h), b(w);
    ll sumA = 0, sumB = 0;
    for(int &x: a){
        cin >> x;
        sumA += x;
    }
    for(int &x: b){
        cin >> x;
        sumB += x;
    }
    if(sumA%k != sumB%k)
        return cout << -1, 0;
    
    ll res = 0;
    ll sum = 0;
    for(int x: a){
        ll Max = 1LL*(k-1)*w;
        sum += 1LL * (Max - x)/k * k + x;
    }
    res = sum;
    sum = 0;
    for(int x: b){
        ll Max = 1LL*(k-1)*h;
        sum += 1LL * (Max - x)/k * k + x;
    }

    res = min(res, sum);
    cout << res << '\n';
}