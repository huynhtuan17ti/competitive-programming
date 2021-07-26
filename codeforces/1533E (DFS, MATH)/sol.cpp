#include <bits/stdc++.h>

using namespace std;
#define MAXN 300005

int vi[MAXN];
int adj[MAXN];

void DFS(int u){
    vi[u] = 1;
    if(!vi[adj[u]])
        DFS(adj[u]);
}

bool check(vector <int> p, int k, int n, int m){
    int v = n - k;
    for(int i = 0; i < k; i++){
        adj[p[i]] = v;
        v++;
    }
    for(int i = k; i < n; i++){
        adj[p[i]] = i - k;
    }
    fill(vi, vi+1+n, 0);
    int cnt_cmp = 0;
    for(int i = 0; i < n; i++){
        if(!vi[i]){
            cnt_cmp++;
            DFS(i);
        }
    }
    return n - cnt_cmp <= m;
}

int main(){
    int t; cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector <int> p(n);
        for(int i = 0; i < n; i++){
            cin >> p[i];
            p[i] -= 1;
        }
        vector <int> cnt(n);
        for(int i = 0; i < n; i++){
            int id = (i - p[i] + n)%n;
            cnt[id]++;
        }
        vector <int> res;
        for(int k = 0; k < n; k++){
            if(cnt[k] >= n - 2*m && check(p, k, n, m))
                res.push_back(k);
        }
        cout << res.size() << ' ';
        for(int u: res)
            cout << u << ' ';
        cout << '\n';
    }
}