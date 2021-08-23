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

char arr[8][8];

void _fill(int k){
    
    for(int i = 0; i < 8; i++)  fill(arr[i], arr[i]+8, 'X');
    int cnt = 0;
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++){
            cnt++;
            arr[i][j] = '.';
            if(cnt == k)  return;
        }
    
}

int main(){
    int t; cin >> t;
    while(t--){
        int k; cin >> k;
        _fill(k);
        arr[0][0] = 'O';
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++)
                cout << arr[i][j];
            cout << '\n';
        }
        cout << '\n';
    }
}