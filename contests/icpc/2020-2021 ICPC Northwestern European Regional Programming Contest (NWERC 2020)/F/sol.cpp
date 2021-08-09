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
const ld inf = LDBL_MAX;
 
// v1*d + x1 = v2*d + x2
// => d = (x2 - x1)/(v1 - v2)
ld get_d(ii line1, ii line2){
    if(line1.fi == line2.fi)
        return inf;
    ld d = (ld)(line2.se - line1.se)/(line1.fi - line2.fi);
    if(d < 0)
        return inf;
    return d;
}
 
set <int> pos;
 
int findL(int val){
    auto it = pos.lower_bound(val);
    if(it == pos.begin())
        return -1;
    it--;
    return (*it);
}
 
int findR(int val){
    auto it = pos.upper_bound(val);
    if(it == pos.end())
        return -1;
    return (*it);
}
 
int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n; cin >> n;
    vii a;
    for(int i = 0; i < n; i++){
        int x, v; cin >> x >> v;
        a.push_back({v, x});
    }
    set <pair <ld, ii>> S;
    pos.insert(0);
    for(int i = 1; i < n; i++){
        pos.insert(i);
        S.insert({get_d(a[i-1], a[i]), mp(i-1, i)});
    }
    vector <bool> is_del(n);
    fill(is_del.begin(), is_del.end(), false);
    while(!S.empty() && (*S.begin()).fi != inf){
        ii pp = (*S.begin()).se;
        pos.erase(pp.fi);
        pos.erase(pp.se);
        is_del[pp.fi] = true;
        is_del[pp.se] = true;
        S.erase(S.begin());
        int l = findL(pp.fi), r = findR(pp.se);
        if(l != -1){
            auto it = S.find({get_d(a[l], a[pp.fi]), mp(l, pp.fi)});
            S.erase(it);
        }
        if(r != -1){
            auto it = S.find({get_d(a[pp.se], a[r]), mp(pp.se, r)});
            S.erase(it);
        }
        if(l != -1 && r != -1){
            S.insert({get_d(a[l], a[r]), mp(l, r)});
        }
    }
    int res = 0;
    for(int i = 0; i < n; i++)
        if(is_del[i] == false)  res++;
    cout << res << '\n';
    for(int i = 0; i < n; i++)
        if(!is_del[i])
            cout << i+1 << " \n"[i == n-1];
}