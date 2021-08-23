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
int arr[MAXN];

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        long long res = 0;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            if(i > 0)   res += abs(arr[i] - arr[i-1]) - 1;
        }
        cout << res << '\n';
    }
}