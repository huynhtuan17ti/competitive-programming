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
int a[MAXN];

int main(){
    int t; cin >> t;
    while(t--){
        int n; long long x; cin >> n >> x;
        for(int i = 0; i < n; i++)  cin >> a[i];
        sort(a, a+n);
        int p = n;
        for(int i = 0; i < n; i++)
            if(a[i]*2 >= x){
                p = i;
                break;
            }
        //cout << p << '\n';
        long long res = 0;
        for(int i = p; i < n; i++){
            if(x >= a[i]){
                x = a[i]*2;
                res ++;
                //cout << i << ' ' << x << ' ' << 1 << '\n';
            }else{
                int num = ceil((double)log2((double)a[i]/x));
                //cout << i << ' ' << x << ' ' << num << '\n';
                x = a[i]*2;
                res += num + 1;
            }
        }
        //cout << res << '\n';
        cout << res + p << '\n';
    }
}