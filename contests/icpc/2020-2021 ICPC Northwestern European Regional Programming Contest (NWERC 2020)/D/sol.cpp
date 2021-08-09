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

random_device device;
mt19937 generator(device());
 
int myIntRand(int lo, int hi) {
    uniform_int_distribution<int> rd(lo, hi);
    return rd(generator);
}
 

int main(){
    int n; cin >> n;
    int cnt = 0;
    while(cnt < n){
        int x = myIntRand(1, 1e6-1);
        ll d[3];
        int p[] = {-1, 0};
        vector <int> x_news;
        for(int k = 0; k < 2; k++){
            int x_new = x + p[k];
            x_news.push_back(x_new);
            cout << x_new << ' ' << 0 << '\n';
            fflush(stdout);
            cin >> d[k];
        }
        ll x_pred = (x_news[0] + x_news[1] - (d[1] - d[0]))/2;
        ll y_pred = (int)sqrt(d[0] - 1LL*(x_pred - x_news[0])*(x_pred - x_news[0]));
        cout << x_pred << ' ' << y_pred << '\n';
        fflush(stdout);
        ll d_pred;
        cin >> d_pred;
        if(d_pred == 0)
            cnt++;
    }
}