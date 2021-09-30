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

int n;

struct Bucket{
    int cost;
    vector <int> Id;
    Bucket(){
        cost = 0;
        Id.resize(n);
    }
    Bucket(int _cost, vector <int> _Id){
        cost = _cost;
        Id = _Id;
    }
};

bool operator < (const Bucket &A, const Bucket &B){
    return A.cost < B.cost;
}

int c[10];

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    vector <vector <int>> a;
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++){
        cin >> c[i];
        a[i].resize(c[i]);
        for(int j = 0; j < c[i]; j++)
            cin >> a[i][j];
    }
    int m; cin >> m;
    map <vector <int>, bool> M;
    for(int i = 0; i < m; i++){
        vector <int> Id(n);
        for(int j = 0; j < n; j++){
            cin >> Id[j];
            Id[j]--;
        }
        M[Id] = true;
    }

    priority_queue <Bucket> pq;
    Bucket bk;
    for(int i = 0; i < n; i++){
        bk.Id[i] = c[i]-1;
        bk.cost += a[i][bk.Id[i]];
    }
    pq.push(bk);

    map <vector <int>, bool> vi;
    queue <Bucket> Q;
    while(Q.size() < m+1){
        Bucket curBucket = pq.top();
        pq.pop();
        Q.push(curBucket);
        for(int i = 0; i < n; i++){
            vector <int> tmpId = curBucket.Id;
            if(tmpId[i] > 0){
                tmpId[i]--;
                if(vi[tmpId] == true)
                    continue;
                vi[tmpId] = true;
                pq.push({curBucket.cost - a[i][tmpId[i]+1] + a[i][tmpId[i]], tmpId});
            }
        }
    }
    while(!Q.empty()){
        Bucket curBucket = Q.front();
        Q.pop();
        if(!M[curBucket.Id]){
            for(int u: curBucket.Id)
                cout << u+1 << ' ';
            return 0;
        }
    }
}