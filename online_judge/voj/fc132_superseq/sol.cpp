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
const int MAXN = 1e5 + 5;
const int MAXV = 450;

vector <int> indices[MAXV + 1];
int preIdx[MAXN][MAXV+1];

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n; cin >> n;
    vector <int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] <= MAXV)
            indices[a[i]].push_back(i);
    }

    for(int val = 1; val <= MAXV; val++){
        int j = 0;
        for(int i = val-1; i < indices[val].size(); i++, j++)
            preIdx[indices[val][i]][val] = indices[val][j];
    }
    
    for(int val = 1; val <= MAXV; val++)
        for(int i = 1; i <= n; i++)
            preIdx[i][val] = max(preIdx[i-1][val], preIdx[i][val]);

    int ans = 0;
    for(int i = 1; i <= n; i++){
        int j = i;
        for(int val = 1; val <= MAXV; val++){
            j = min(j, preIdx[i][val]);
            if(j == 0)
                break;
            int len = i-j+1;
            int curSum = val*(val+1)/2;
            if(len == curSum)
                ans++;
        }
    }
    cout << ans << '\n';
}