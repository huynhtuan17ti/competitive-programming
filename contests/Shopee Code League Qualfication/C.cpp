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

struct Firework{
    int a, b, t;
};

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n, m, d;
    cin >> n >> m >> d;
    vector <Firework> a(m);
    vector <int> times;
    for(int i = 0; i < m; i++){
        cin >> a[i].a >> a[i].b >> a[i].t;
        times.push_back(a[i].t);
    }
    sort(times.begin(), times.end());
    times.resize(unique(times.begin(), times.end()) - times.begin());
    
    vector <ll> costPos(n+1);

    auto updateCost = [&](Firework x){
        int center = x.a, cost = x.b;
        while(center >= 1){
            costPos[center] += cost;
            cost--;
            center--;
        }
        center = x.a+1; cost = x.b-1;
        while(center <= n){
            costPos[center] += cost;
            cost--;
            center++;
        }
    };

    vector <ll> preCost(n+1);
    vector <ll> newCost(n+1);

    int j = 0;
    int lastTime = 1;
    for(int curTime: times){
        //cerr << curTime << '\n';
        fill(costPos.begin(), costPos.end(), 0);
        while(j < m && a[j].t == curTime){
            updateCost(a[j]);
            j++;
        }

        ll totalDis = min(1LL*n, 1LL*(curTime-lastTime)*d);
        lastTime = curTime;
        //cout << totalDis << '\n';
        
        deque <int> q;
        for(int i = 1; i <= n; i++){
            while(!q.empty() && preCost[q.back()] < preCost[i])
                q.pop_back();
            while(!q.empty() && q.front() < i - totalDis)
                q.pop_front();

            q.push_back(i);
            newCost[i] = preCost[q.front()];
        }

        while(!q.empty())
            q.pop_back();
        
        for(int i = n; i >= 1; i--){
            while(!q.empty() && preCost[q.back()] < preCost[i])
                q.pop_back();
            while(!q.empty() && q.front() > i + totalDis)
                q.pop_front();

            q.push_back(i);
            newCost[i] = max(newCost[i], preCost[q.front()]);
        }

        for(int i = 1; i <= n; i++)
            preCost[i] = newCost[i] + costPos[i];
    }

    ll ans = LLONG_MIN;
    for(int i = 1; i <= n; i++){
        ans = max(ans, preCost[i]);
    }
    cout << ans << '\n';
}