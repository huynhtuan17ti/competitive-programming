#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int A, B, C;
        cin >> A >> B >> C;
        if(A == 7 || B == 7 || C == 7)
            cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}