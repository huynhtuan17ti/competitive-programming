#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int q; cin >> q;
    while(q--){
        string s, t;
        cin >> s >> t;
        if(t.size() > s.size()){
            cout << "NO" << '\n';
            continue;
        }
        priority_queue <int> S[30];
        for(int i = 0; i < s.size(); i++){
            int x = (int)(s[i] - 'a');
            S[x].push(i);
        }
        int cur = s.size();
        int type = cur%2;
        bool res = true;
        for(int i = t.size()-1; i >= 0; i--){
            int x = (int)(t[i] - 'a');
            bool is_ans = false;
            while(!S[x].empty()){
                int v = S[x].top();
                S[x].pop();
                if(v < cur && v%2 != type){
                    cur = v;
                    type = cur%2;
                    is_ans = true;
                    break;
                }
            }
            if(!is_ans){
                res = false;
                break;
            }
        }
        cout << ((res)? "YES": "NO") << '\n';
    }
}