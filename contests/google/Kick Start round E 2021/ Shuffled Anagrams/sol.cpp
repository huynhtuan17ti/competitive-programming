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

int cnt[30];

int main(){
    io
    int t;
    cin >> t;
    for(int iTest = 1; iTest <= t; iTest++){
        string s; cin >> s;
        fill(cnt, cnt+30, 0);
        vii bucket;
        for(int i = 0; i < s.size(); i++){
            cnt[s[i] - 'a']++;
            bucket.push_back({s[i] - 'a', i});
        }

        bool ok = true;
        for(int i = 0; i < 26; i++){
            if(cnt[i] > (int)s.size()/2)
                ok = false;
        }
        cout << "Case #" << iTest << ": ";
        if(!ok){
            cout << "IMPOSSIBLE" << '\n';
            continue;
        }

        sort(bucket.begin(), bucket.end(), [](const ii &A, const ii &B){
            return (cnt[A.fi] == cnt[B.fi])? A.fi < B.fi : cnt[A.fi] > cnt[B.fi];
        });
        
        string res;
        res.resize((int)s.size());

        vii _bucket = bucket;
        reverse(_bucket.begin(), _bucket.end());

        int j = 0;
        for(int i = 0; i < s.size(); i++)
            if(bucket[i].fi == _bucket[i].fi){
                swap(_bucket[i], _bucket[j]);
                j++;
            }

        for(int i = 0; i < s.size(); i++)
            res[bucket[i].se] = (char)(_bucket[i].fi + 'a');


        for(int i = 0; i < s.size(); i++)
            assert(s[i] != res[i]);

        cout << res << '\n';
    }
}