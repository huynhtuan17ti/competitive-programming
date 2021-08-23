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
const int MAXN = 1e5;
int block_size;

int a[MAXN+5];
int cnt[MAXN+5];
int exist[MAXN+5];

struct query{
    int l, r, pos;
};

void del(int pos){
    if(pos == 0)
        return;
    exist[cnt[a[pos]]]--;
    cnt[a[pos]]--;
}

void add(int pos){
    if(pos == 0)
        return;
    cnt[a[pos]]++;
    exist[cnt[a[pos]]]++;
}

int calc(int l, int r){
    while(l <= r){
        int mid = (l+r) >> 1;
        if(exist[mid] > 0)
            l = mid + 1;
        else r = mid - 1;
    }
    return l - 1;
}

vector <int> MoQueries(int n, vector <query> Q){

    block_size = sqrt(n);
    sort(Q.begin(), Q.end(), [](const query &A, const query &B){
        return (A.l/block_size != B.l/block_size)? (A.l/block_size < B.l/block_size) : (A.r < B.r);
    });
    vector <int> res;
    res.resize((int)Q.size());

    int L = 1, R = 0;
    for(query q: Q){
        while (L > q.l) add(--L);
        while (R < q.r) add(++R);

        while (L < q.l) del(L++);
        while (R > q.r) del(R--);
        
        res[q.pos] = calc(1, R-L+1);
    }
    return res;
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector <query> Q;
    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        l++; r++;
        Q.push_back({l, r, i});
    }
    vector <int> res = MoQueries(n, Q);
    for(int ans: res)
        cout << ans << '\n';
}