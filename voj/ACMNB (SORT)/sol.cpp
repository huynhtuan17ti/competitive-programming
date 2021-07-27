#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n; cin >> n;
    vector <int> arr;
    int sum = 0;
    for(int i = 1; i <= 2*n; i++){
        int a, b;
        cin >> a >> b;
        arr.push_back(b-a);
        sum += a;
    }
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n; i++)
        sum += arr[i];    
    cout << sum << '\n';
}