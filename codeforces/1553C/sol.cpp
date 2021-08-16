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

int res = INT_MAX; 

void Try(string s, int pos, int score_a, int score_b){
    if(score_a > score_b && score_a - score_b > (10 - pos + 1)/2){
        res = min(res, pos);
    }
    if(score_a < score_b && score_b - score_a > (9 - pos + 1)/2){
        res = min(res, pos);
    }
    if(pos == s.size()){
        return;
    }
    if(s[pos] == '?'){
        if(pos%2 == 0){
            Try(s, pos+1, score_a + 1, score_b);
            Try(s, pos+1, score_a, score_b);
        }else{
            Try(s, pos+1, score_a, score_b);
            Try(s, pos+1, score_a, score_b + 1);
        }
    }else{
        if(s[pos] == '1'){
            if(pos%2 == 0)
                Try(s, pos+1, score_a + 1, score_b);
            else
                Try(s, pos+1, score_a, score_b + 1);

        }else
            Try(s, pos+1, score_a, score_b);
    }
}

int main(){
    io
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        res = 10;
        Try(s, 0, 0, 0);
        cout << res << '\n';
    }
}