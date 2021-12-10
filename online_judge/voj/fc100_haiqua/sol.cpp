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
const int MAXN = (1<<20)+1;

int w[MAXN];
int sum[4*MAXN];

void build(int id, int l, int r){
    if(l == r){
        sum[id] = w[l];
        return;
    }
    int mid = (l+r) >> 1;
    build(2*id, l, mid);
    build(2*id+1, mid+1, r);
    sum[id] = sum[2*id] + sum[2*id+1];
}

void get(int id, int l, int r){
    if(l == r){
        cout << l << ' ';
        sum[id] = 0;
        return;
    }
    int mid = (l+r) >> 1;
    if(sum[2*id] < sum[2*id+1])
        get(2*id+1, mid+1, r);
    else get(2*id, l, mid);
    sum[id] = sum[2*id] + sum[2*id+1];
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int k; cin >> k;
    int n = (1<<k);
    vector <int> cnt(3);
    for(int i = 1; i <= n; i++){
        cin >> w[i];
        if(w[i] == 1 || w[i] == 2)
            cnt[w[i]]++;
    }
    if(cnt[1] + cnt[2] < n || cnt[2] > 1)
        return cout << 0, 0;
    build(1, 1, n);
    cout << n << '\n';
    for(int i = 1; i <= n; i++){
        get(1, 1, n);
    }   
}