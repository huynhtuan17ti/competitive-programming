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
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
const int MAXN = 5e5 + 5;

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    string t;
    cin >> t;
    int n; cin >> n;
    vector <string> a(n);
    for(string &x: a)
        cin >> x;
    
    auto findSamePrefix = [&](string s) -> vector <int>{
        vector <int> possiblePrefix;
        for(int len = 1; len < (int)t.size(); len++){
            if(len > s.size())
                continue;
            bool ck = true;
            for(int i = 0; i < len; i++)
                if(s[(int)s.size() - len + i] != t[i]){
                    ck = false;
                    break;
                }
            if(ck)  possiblePrefix.push_back(len);
        }
        return possiblePrefix;
    };

    auto findSameSuffix = [&](string s) -> vector <int>{
        vector <int> possibleSuffix;
        for(int len = 1; len < (int)t.size(); len++){
            if(len > s.size())
                continue;
            bool ck = true;
            for(int i = 0; i < len; i++)
                if(s[i] != t[(int)t.size() - len + i]){
                    ck = false;
                    break;
                }
            if(ck)  possibleSuffix.push_back(len);
        }
        return possibleSuffix;
    };

    auto getNumberSubarray = [&](string s) -> int{
        int lenT = t.size();
        int cnt = 0;
        for(int i = 0; i <= (int)s.size() - lenT; i++){
            if(t == s.substr(i, lenT))
                cnt += 1;
        }
        return cnt;
    };

    map <int, int> sum;
    for(int i = 0; i < n; i++){
        vector <int> prefixLen = findSamePrefix(a[i]);
        for(int len: prefixLen)
            sum[len]++;
    }

    ll res = 0;
    for(int i = 0; i < n; i++){
        int cntSub = getNumberSubarray(a[i]);
        res += 1LL * cntSub * 2 * n;
        vector <int> suffixLen = findSameSuffix(a[i]);
        for(int len: suffixLen)
            res += sum[(int)t.size() - len];
    }
    cout << res << '\n';
}