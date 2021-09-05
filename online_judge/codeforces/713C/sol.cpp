#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

/*
    dp[i][x] = dp[i-1][y] + abs(x - a[i]) with y <= x
*/

int main(){
    int n; cin >> n;
    vector <int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i] -= i; // stricly increasing -> increasing
    }

    priority_queue <int> pq;
    pq.push(a[0]);
    ll res = 0;
    for(int i = 1; i < n; i++){
        int top = pq.top();
        pq.push(a[i]);
        if(a[i] < top){
            res += (top - a[i]);
            pq.pop();
            pq.push(a[i]);
        }   
    }
    cout << res << '\n';
}