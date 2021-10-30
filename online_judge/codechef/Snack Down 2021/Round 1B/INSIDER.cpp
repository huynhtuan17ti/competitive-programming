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

/*
    Take a deep look of 2 conditions given:
    - s[i-1] < x < s[i]
    - s[i-1] > x > s[i]

    It's not hard to see that we only care the first and last value of an inscreased/descreased continuous subsequence.
    Indeed, we can compression the array. For example:
    [5, 1, 1, 2, 3, 1, 4, 5, 7, 2, 6] -> [5, 1, 3, 1, 7, 2, 6]

    Further more, if we visualize the array in a histogram:
                  7
                 / \       6
    5           /   \     /
     \         /     \   /
      \   3   /       \ /
       \ / \ /         2
        1   1

    If we consider a number x, the number of lines it cuts through + 1 would be the maximum length of subsequence we can produce.
    Now the problem becomes easy, we can calculate the minimum/maximum x in a linear complexity with above observation.
*/

void solve(){
    int n; cin >> n;
    vector <int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    vector <int> s;
    s.push_back(a[0]);
    int pre = a[0];
    for(int i = 1; i < n-1; i++){
        if(a[i] == a[i+1])
            continue;
        if(1LL*(a[i] - pre)*(a[i+1] - a[i]) < 0)
            s.push_back(a[i]);
        pre = a[i];
    }
    s.push_back(a[n-1]);

    vector <int> S;
    for(int u: s){
        S.push_back(u);
        S.push_back(u-1);
        S.push_back(u+1);
    }
    // compression
    sort(S.begin(), S.end());
    S.resize(unique(S.begin(), S.end()) - S.begin());
    int len = S.size();
    vector <int> fill(len);

    auto getId = [&](int val){
        return lower_bound(S.begin(), S.end(), val) - S.begin();
    };

    for(int i = 1; i < s.size(); i++){
        int u = s[i-1], v = s[i];
        if(u > v)   swap(u, v);
        int l = getId(u+1);
        int r = getId(v-1);
        fill[l]++;
        fill[r+1]--;
    }

    for(int i = 1; i <= len; i++)
        fill[i] += fill[i-1];
    
    vector <int> Min(n+1, -1), Max(n+1, -1);
    
    int maxLen = 2;
    for(int i = 0; i < len; i++){
        int eLen = fill[i]+1;
        while(maxLen <= eLen){
            Min[maxLen] = S[i];
            maxLen++;
        }
    }

    maxLen = 2;
    for(int i = len-1; i >= 0; i--){
        int eLen = fill[i]+1;
        while(maxLen <= eLen){
            Max[maxLen] = S[i];
            maxLen++;
        }
    }
    for(int i = 2; i <= n; i++)
        cout << Min[i] << " \n"[i == n];
    for(int i = 2; i <= n; i++)
        cout << Max[i] << " \n"[i == n];
}

int main(){
    io
    int t; cin >> t;
    while(t--){
        solve();
    }
}