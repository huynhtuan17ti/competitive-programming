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

int a[12][12][MAXN];

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n, d;
    cin >> n >> d;
    for(int i = 0; i < d; i++){
        int s, k, p;
        cin >> s >> k >> p;
        int t = s % k;
        // i = t + k*x
        int startPos = s/k;
        int endPos = min(p - 1 + s/k, (n-t)/k);

        a[t][k][startPos]++;
        a[t][k][endPos+1]--;
    }

    for(int t = 0; t < 10; t++)
        for(int k = 2; k <= 10; k++)
            for(int i = 1; i <= n; i++)
                a[t][k][i] += a[t][k][i-1];

    int Max = -1, ans;

    for(int i = 1; i <= n; i++){
        int total = 0;
        for(int t = 0; t < 10; t++)
            for(int k = 2; k <= 10; k++){
                if((i-t)%k != 0)
                    continue;
                int pos = (i-t)/k;
                total += a[t][k][pos];
            }
        if(Max < total){
            Max = total;
            ans = i;
        }
    }
    cout << "Dung can hack dien dan " << ans << ".\n";
}