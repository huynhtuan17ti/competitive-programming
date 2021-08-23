//Tuan Kkura
#include <bits/stdc++.h>

using namespace std;
#define PROB "text"
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef pair <int, int> ii;
typedef vector <ii> vii;
 
#define MAXN 200005

int arr_x[4*MAXN], arr_y[4*MAXN];

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i = 0; i < 4*n-1; i++){
            int x, y; cin >> x >> y;
            arr_x[i] = x;
            arr_y[i] = y;
        }
        sort(arr_x, arr_x+4*n-1);
        sort(arr_y, arr_y+4*n-1);
        ii res;
        int pre_x = arr_x[0], pre_y = arr_y[0];
        int cnt_x = 1, cnt_y = 1;
        for(int i = 1; i < 4*n-1; i++){
            if(arr_x[i] != arr_x[i-1]){
                if(cnt_x % 2 == 1)
                    res.fi = arr_x[i-1];
                cnt_x = 0;
            }
            if(arr_y[i] != arr_y[i-1]){
                if(cnt_y % 2 == 1)
                    res.se = arr_y[i-1];
                cnt_y = 0;
            }
            cnt_x ++;
            cnt_y ++;
        }
        if(cnt_x % 2 == 1)  res.fi = arr_x[4*n-2];
        if(cnt_y % 2 == 1)  res.se = arr_y[4*n-2];
        cout << res.fi << ' ' << res.se << '\n';
    }
}