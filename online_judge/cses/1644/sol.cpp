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

int main(){
    io
    int n, a, b;
    cin >> n >> a >> b;
    vector <ll> preSum(n+1);
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        preSum[i] = preSum[i-1] + x;
    }
    deque <int> dq;
    int j = 0;
    ll ans = -1e15;
    for(int i = 1; i <= n; i++){
        if(i - j >= a){
            while(!dq.empty() && preSum[dq.back()] > preSum[j])
                dq.pop_back();
            dq.push_back(j);
            j++;
        }
        while(!dq.empty() && i - dq.front() > b)
            dq.pop_front();

        if(!dq.empty()){
            ans = max(ans, preSum[i] - preSum[dq.front()]);
        }
    }
    cout << ans << '\n';
}