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
const int MAXN = 2e5 + 5;

struct Node{
    int lnode, rnode;
    int sum;
    Node(){
        lnode = rnode = sum = 0;
    }
}ver[MAXN * 120];
int sz = 0;

int build_new_node(int l, int r){
    int next = ++sz;
    if(l != r){
        int mid = (l+r) >> 1;
        ver[next].lnode = build_new_node(l, mid);
        ver[next].rnode = build_new_node(mid+1, r);
    }
    return next;
}

int update(int cur, int l, int r, int pos, int val){
    int next = ++sz;
    ver[next] = ver[cur];
    if(l == r){
        ver[next].sum = val;
        return next;
    }
    else{
        int mid = (l+r) >> 1;
        if(pos <= mid)
            ver[next].lnode = update(ver[cur].lnode, l, mid, pos, val);
        else
            ver[next].rnode = update(ver[cur].rnode , mid+1, r, pos, val);
    }
    ver[next].sum = ver[ver[next].lnode].sum + ver[ver[next].rnode].sum;
    //cout << l << ' ' << r << ' ' << ver[next].sum << '\n';
    return next;
}

int get(int cur, int l, int r, int u, int v){
    if(r < u ||v < l)
        return 0;
    if(u <= l && r <= v){
        return ver[cur].sum;
    }
    int mid = (l+r) >> 1;
    return get(ver[cur].lnode, l, mid, u, v) + 
           get(ver[cur].rnode, mid+1, r, u, v);
}

int main(){
    io
    //freopen("test.inp", "r", stdin);
    int n, q;
    cin >> n >> q;
    vector <int> a(n+1);
    vector <int> root_ver(n+1);

    root_ver[0] = build_new_node(1, n);

    map <int, int> last;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        root_ver[i] = root_ver[i-1];
        if(last[a[i]] > 0)
            root_ver[i] = update(root_ver[i], 1, n, last[a[i]], 0);
        root_ver[i] = update(root_ver[i], 1, n, i, 1);
        last[a[i]] = i;
    }

    while(q--){
        int u, v;
        cin >> u >> v;
        cout << get(root_ver[v], 1, n, u, v) << '\n';
    }
}