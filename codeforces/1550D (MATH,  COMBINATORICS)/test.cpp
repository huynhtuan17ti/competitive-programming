#include <bits/stdc++.h>

using namespace std;

int res = 0, cnt = 0;

void Try(int id, vector <int> a, int n, int l, int r){
    if(id > n){
        int ans = 0;
        for(int i = 1; i <= n; i++)
            for(int j = i+1; j <= n; j++)
                if(a[i] + a[j] == i + j)
                    ans++;
        if(ans == n/2*(n-n/2)){
            for(int i = 1; i <= n; i++)
                cout << a[i] << " \n"[i == n];
        }
        res = max(res, ans);
        return;
    }
    for(int i = l; i <= r; i++){
        if(i == id)
            continue;
        a.push_back(i);
        Try(id+1, a, n, l, r);
        a.pop_back();
    }
}

int main(){
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int l, r;
        cin >> l >> r;
        res = 0;
        vector <int> a;
        a.push_back(0);
        Try(1, a, n, l, r);
        cout << res << '\n';
    }
}