//Tuan Kkura
#include <bits/stdc++.h>

using namespace std;
#define PROB "text"
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef pair <int, int> ii;
typedef vector <ii> vii;
 
#define MAXN 200005
int a[MAXN], b[MAXN];

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        map <int, int> aMap, bMap;
        int Min = INT_MAX;
        for(int i = 0; i < n; i++)  {
            cin >> a[i];
            aMap[a[i]]++;
            Min = min(Min, a[i]);
        }
        for(int i = 0; i < n; i++)  {
            cin >> b[i];
            bMap[b[i]]++;
            Min = min(Min, b[i]);
        }
        bool ok = true;
        vii arr;
        int arrSize = 0;
        map <int, int> :: iterator it;
        for(it = aMap.begin(); it != aMap.end(); it++){
            int num = bMap[it->fi];
            if(it->se > num){
                if((it->se - num) % 2 == 1)
                    ok = false;
                arr.push_back(mp(it->fi, it->se - num));
                arrSize += it->se - num;
            }
        }
        for(it = bMap.begin(); it != bMap.end(); it++){
            int num = aMap[it->fi];
            if(it->se > num){
                if((it->se - num) % 2 == 1)
                    ok = false;
                arr.push_back(mp(it->fi, it->se - num));
                arrSize += it->se - num;
            }
        }
        sort(arr.begin(), arr.end());
        long long res = 0;
        int cnt = 0;
        for(int i = 0; i < arr.size(); i++){
            if(cnt >= arrSize/4) break;
            res += 1LL*min(arrSize/4 - cnt, arr[i].se/2)
                    *min(Min*2, arr[i].fi);
            cnt += arr[i].se/2;
        }
        if(!ok) cout << -1 << '\n';
        else cout << res << '\n';
    }
}