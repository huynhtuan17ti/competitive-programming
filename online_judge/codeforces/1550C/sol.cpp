#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool check(vector <int> s){
    for(int i = 0; i < s.size(); i++)
        for(int j = i + 1; j < s.size(); j++)
            for(int k = j + 1; k < s.size(); k++)
                if((s[i] <= s[j] && s[j] <= s[k]) || s[i] >= s[j] && s[j] >= s[k])
                    return false;
    return true;
}

int main(){
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        vector <int> a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];
        ll res = 2*n-1;
        for(int len = 3; len <= 4; len++)
            for(int i = len-1; i < n; i++){
                vector <int> s;
                for(int p = i - len + 1; p <= i; p++)
                    s.push_back(a[p]);
                if(check(s))
                    res++;
            }
        cout << res << '\n';
    }
}