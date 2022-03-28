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
    int n; cin >> n;
    auto getbit = [&](int val, int id){
        return (val >> id)&1;
    };
    auto check = [&](int val){
        for(int bit = 0; bit <= 20; bit++)
            if(val == (1<<bit)-1)
                return true;
        return false;
    };
    if(n%2 == 0)
        cout << 0 << '\n';
    else{
        if(check(n))
            cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}