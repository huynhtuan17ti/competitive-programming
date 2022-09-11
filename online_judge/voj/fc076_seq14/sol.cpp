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
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector <int> a(n+1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    // L[i] is the minimum as possible of the last number of non-decreasing array has length i.
    vector <int> L(n+1, INT_MAX);
    L[0] = INT_MIN;
    int curBest = 0;

    for(int i = 1; i <= n; i++){
        if(L[curBest] <= a[i] + k){
            L[curBest + 1] = max(L[curBest], a[i] - k);
            curBest++;
        }
        for(int j = curBest; j >= 1; j--) {
            if(L[j-1] <= a[i] + k){
                L[j] = min(L[j], max(L[j-1], a[i] - k));
            }
        }
    }

    cout << curBest << '\n';
}