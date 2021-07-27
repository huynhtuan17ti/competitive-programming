#include <bits/stdc++.h>

using namespace std;
#define MAXN 200005
#define MAXK 17

int maxLen[MAXN][MAXK];
int nxt[MAXN][MAXK];
int start[MAXK];
int dp[MAXN];

void init(string s, int k){
    vector <int> cur(k);
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '?')
            for(int j = 0; j < k; j++)
                cur[j] += 1;
        else{
            int ch = s[i] - 'a';
            for(int j = 0; j < k; j++)
                if(j != ch)
                    cur[j] = 0;
                else cur[j] += 1;
        }
        for(int j = 0; j < k; j++)
            maxLen[i][j] = cur[j];
    }
}

void prepare(int len, int k, string s){
    for(int i = 0; i <= s.size(); i++)
        for(int j = 0; j < k; j++)
            nxt[i][j] = INT_MAX;

    for(int j = 0; j < k; j++)
        start[j] = INT_MAX;
    
    for(int i = s.size()-1; i >= 0; i--){
        for(int j = 0; j < k; j++){
            nxt[i][j] = min(nxt[i][j], nxt[i+1][j]);
            if(maxLen[i][j] >= len){
                if(i >= len)
                    nxt[i - len][j] = min(nxt[i - len][j], i);
                start[j] = min(start[j], i);
            }
        }
    }
}

int get_bit(int val, int id){
    return (val >> id)&1;
}

bool check(int n, int k, string s, int len){
    prepare(len, k, s);
    int maxState = (1<<k);
    for(int state = 0; state < maxState; state++)
        dp[state] = INT_MAX;
    dp[0] = -1;
    for(int state = 1; state < maxState; state++){
        for(int i = 0; i < k; i++){
            if(get_bit(state, i)){
                int prestate = state - (1<<i);
                int next_pos = INT_MAX;
                if(prestate == 0)
                    next_pos = start[i];
                else if(dp[prestate] < INT_MAX)
                    next_pos = nxt[dp[prestate]][i];
                dp[state] = min(dp[state], next_pos);
            }
        }
    }
    return (dp[maxState-1] != INT_MAX);
}

int main(){
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    string s; cin >> s;
    init(s, k);
    int l = 0, r = n/k;
    while(l <= r){
        int mid = (l+r) >> 1;
        if(check(n, k, s, mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    cout << l - 1 << '\n';
}