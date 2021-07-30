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
 
const int MAXN = 1e6+5;
int m;

struct seg{
    int l, r, w;
};

int IT[4*MAXN], lazy[4*MAXN];

void down(int id){
    int k = lazy[id];
    if(k == 0)
        return;
    IT[2*id] += k;
    IT[2*id+1] += k;

    lazy[2*id] += k;
    lazy[2*id+1] += k;

    lazy[id] = 0;
}

void update(int id, int l, int r, int u, int v, int val){
    if(v < l || r < u)
        return;
    if(u <= l && r <= v){
        IT[id] += val;
        lazy[id] += val;
        return;
    }
    int mid = (l+r) >> 1;
    down(id);
    update(2*id, l, mid, u, v, val);
    update(2*id+1, mid+1, r, u, v, val);
    IT[id] = min(IT[2*id], IT[2*id+1]);
}

int main(){
    io
    int t; t = 1;
    while(t--){
        int n;
        cin >> n >> m;
        vector <seg> segs;
        for(int i = 0; i < n; i++){
            int l, r, w;
            cin >> l >> r >> w;
            r = min(r-1, m);
            segs.push_back({l, r, w});
        }
        sort(segs.begin(), segs.end(), [](const seg &A, const seg &B){
            return (A.w < B.w);
        });
        int j = 0;
        int res = INT_MAX;
        for(int i = 0; i < segs.size(); i++){
            update(1, 1, m-1, segs[i].l, segs[i].r, 1);
            while(j < i && IT[1] > 0){
                update(1, 1, m-1, segs[j].l, segs[j].r, -1);
                j += 1;
            }
            if(j > 0 && IT[1] == 0){
                j -= 1;
                update(1, 1, m-1, segs[j].l, segs[j].r, 1);
            }
            if(IT[1] > 0){
                res = min(res, segs[i].w - segs[j].w);
            }
        }
        cout << res << '\n';
    }
}