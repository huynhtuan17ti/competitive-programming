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

vector <int> a;

struct Node{
    ll val;
    Node *left, *right;
    Node(){
        left = right = NULL;
        val = 0;
    }
    Node(Node* l, Node *r, int v){
        left = l;
        right = r;
        val = v;
    }
};

void build(Node* &cur, int l, int r){
    if(l == r){
        cur->val = a[l];
        return;
    }
    int mid = (l+r) >> 1;
    cur->left = new Node();
    cur->right = new Node();
    build(cur->left, l, mid);
    build(cur->right, mid+1, r);
    cur->val = cur->left->val + cur->right->val;
}

void update(Node* prev, Node* &cur, int l, int r, int i, int val){
    if(i < l || r < i)
        return;
    if(l == r && l == i){
        cur->val = val;
        return;
    }
    int mid = (l+r) >> 1;
    if(i <= mid){
        cur->right = prev->right;
        cur->left = new Node();
        update(prev->left, cur->left, l, mid, i, val);
    }else{
        cur->left = prev->left;
        cur->right = new Node();
        update(prev->right, cur->right, mid+1, r, i, val);
    }
    cur->val = cur->left->val + cur->right->val;
}

ll get(Node* cur, int l, int r, int u, int v){
    if(v < l || r < u)
        return 0;
    if(u <= l && r <= v){
        return cur->val;
    }
    int mid = (l+r) >> 1;
    ll L = get(cur->left, l, mid, u, v);
    ll R = get(cur->right, mid+1, r, u, v);
    return L + R;
}

Node* ver[MAXN];

int main(){
    io
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    a.resize(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    ver[1] = new Node();
    build(ver[1], 1, n);
    vector <int> latest_ver(m+1);
    latest_ver[1] = 1;
    int cnt_ver = 2, cnt_array = 1;
    while(m--){
        int t;
        cin >> t;
        if(t == 1){
            int k, a, x;
            cin >> k >> a >> x;
            ver[cnt_ver] = new Node();
            update(ver[latest_ver[k]], ver[cnt_ver], 1, n, a, x);
            latest_ver[k] = cnt_ver;
            cnt_ver++;
        }
        if(t == 2){
            int k, a, b;
            cin >> k >> a >> b;
            cout << get(ver[latest_ver[k]], 1, n, a, b) << '\n';
        }
        if(t == 3){
            int k;
            cin >> k;
            cnt_array++;
            latest_ver[cnt_array] = latest_ver[k];
        }
    }
}