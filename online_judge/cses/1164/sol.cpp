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

struct range{
    int l, r, id;
};


int main(){
    io
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int n; cin >> n;
    vector <range> ranges(n);
    vector <int> S;
    int curId = 0;
    for(auto &[u, v, id]: ranges){
        cin >> u >> v;
        S.push_back(u);
        S.push_back(v);
        id = curId++;
    }
    S.push_back(INT_MIN);
    sort(S.begin(), S.end());
    S.resize(unique(S.begin(), S.end()) - S.begin());
    int len = S.size();
    vector <int> cnt(len+1);
    for(auto &[u, v, id]: ranges){
        u = lower_bound(S.begin(), S.end(), u) - S.begin();
        v = lower_bound(S.begin(), S.end(), v) - S.begin();
        cnt[u]++;
        cnt[v+1]--;
    }
    int maxRoom = 0;
    for(int i = 1; i <= len; i++){
        cnt[i] += cnt[i-1];
        maxRoom = max(maxRoom, cnt[i]);
    }
    cout << maxRoom << '\n';
    priority_queue <ii, vii, greater <ii>> pq;
    queue <int> q;
    for(int i = 1; i <= maxRoom; i++)
        q.push(i);
    
    vector <int> ans(n);
    sort(ranges.begin(), ranges.end(), [](const range &A, const range &B){
        return (A.l == B.l)? A.r < B.r: A.l < B.l;
    });

    for(auto [u, v, id]: ranges){
        while(!pq.empty() && pq.top().fi < u){
            q.push(pq.top().se);
            pq.pop();
        }
        int idRoom = q.front(); q.pop();
        ans[id] = idRoom;
        pq.push({v, idRoom});
    }
    for(int u: ans)
        cout << u << ' ';
}