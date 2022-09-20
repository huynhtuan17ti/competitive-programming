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
const int inf = 1e9;

/*
    Let's define pre[i] is the previous index of the number equals to a[i]
    Call F(l, r) is the answer of the query is (l, r)
    Apparently, F(l, r) =  max(i - max(pre[1..i]))
    There is a case that max(pre[1..i]) < l => the given answer could be wrong
    => F(l, r) = max(min(i - max(pre[1..i]), i - l)) = max(i - max(pre[1..i], l))
    Easy to see that pre[] is non-decreasing => using 2 pointers
*/

template <typename T>
class SegmentTree{
private:
    void update(int id, int l, int r, int u, T val){
        if(u < l || r < u)
            return;
        if(l == r && l == u){
            IT[id] = min(IT[id], val);
            return;
        }
        int mid = (l+r) >> 1;
        update(2*id, l, mid, u, val);
        update(2*id+1, mid+1, r, u, val);
        IT[id] = max(IT[2*id], IT[2*id+1]);
    }

    T get(int id, int l, int r, int u, int v){
        if(v < l || r < u)
            return -inf;
        if(u <= l && r <= v)
            return IT[id];
        int mid = (l+r) >> 1;
        T L = get(2*id, l, mid, u, v);
        T R = get(2*id+1, mid+1, r, u, v);
        return max(L, R);
    }
public:
    int nVertex;
    vector <T> IT;
public:
    SegmentTree(int n){
        IT.resize(4*n+5, inf);
        nVertex = n;
    }
    void update(int u, T val){
        update(1, 1, nVertex, u, val);
    }
    T get(int u, int v){
        return get(1, 1, nVertex, u, v);
    }
};

struct Query{
    int l, r, id;
};

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    unordered_map <int, int> preMap;
    vector <int> pre(n+1);
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        pre[i] = preMap[x];
        preMap[x] = i;
    }

    SegmentTree<int> segTree(n);
    int maxPre = 0;
    vector<int> maxPreValues;
    for(int i = 1; i <= n; i++){
        maxPre = max(maxPre, pre[i]);
        maxPreValues.push_back(maxPre);
        segTree.update(i, i - maxPre);
    }

    vector <Query> queries;

    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        l++; r++;
        queries.push_back({l, r, i});
    }
    
    sort(queries.begin(), queries.end(), [](const Query &A, const Query &B){
        return A.l < B.l;
    });

    vector <int> ans(q);

    int curValue = 0;
    int j = 0;
    for(auto [l, r, id]: queries){
        curValue = l - 1;
        while(j < n && maxPreValues[j] < l){
            j++;
        }
        if(max(j+1, l) > r)
            ans[id] = r - curValue;
        else
            ans[id] = max(j - curValue, segTree.get(max(j+1, l), r));
    }
    for(int u: ans)
        cout << u << '\n';
}