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
    int c, N;
    cin >> c >> N;
    vector <int> xList, yList;
    xList.push_back(0);
    yList.push_back(0);
    vii points;
    for(int i = 1, x, y; i <= N; i++){
        cin >> x >> y;
        xList.push_back(x);
        yList.push_back(y);
        points.push_back({x, y});
    }
    sort(xList.begin(), xList.end());
    sort(yList.begin(), yList.end());
    xList.resize(unique(xList.begin(), xList.end()) - xList.begin());
    yList.resize(unique(yList.begin(), yList.end()) - yList.begin());

    for(auto &[u, v]: points){
        u = lower_bound(xList.begin(), xList.end(), u) - xList.begin();
        v = lower_bound(yList.begin(), yList.end(), v) - yList.begin();
    }

    sort(points.begin(), points.end(), [](const ii &A, const ii &B){
        return (A.fi == B.fi)? A.se < B.se : A.fi < B.fi;
    });


    int n = xList.size()-1, m = yList.size()-1;
    vector <vector <int>> sum(n+1, vector <int>(m+1));
    vector<vector<int>> isFruit(n+1, vector<int>(m+1));
    vector<int> lenList;

    for(auto [u, v]: points)
        isFruit[u][v] += 1;

    int minLen = 1e5;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + isFruit[i][j];

            auto findMinLength = [&](){
                int p = i, t = j;
                for(int len: lenList){
                    while(p >= 1 && xList[i] - xList[p] + 1 <= len)
                        p--;
                    while (t >= 1 && yList[j] - yList[t] + 1 <= len)
                        t--;
                    int iLeft = p + 1, jLeft = t + 1;
                    if (jLeft > j || iLeft > i)
                        continue;
                    int numFruit = sum[i][j] - sum[iLeft - 1][j] - sum[i][jLeft - 1] + sum[iLeft - 1][jLeft - 1];
                    if (numFruit >= c){
                        // cerr << i << ' ' << j << ' ' << iLeft << ' ' << jLeft << '\n';
                        // cerr << len << '\n';
                        minLen = min(minLen, len);
                    }
                }
            };
            
            
            for(int tmp = i; tmp >= 1; tmp--)
                lenList.push_back(xList[i] - xList[tmp] + 1);
            findMinLength();
            lenList.clear();

            for (int tmp = j; tmp >= 1; tmp--)
                lenList.push_back(yList[j] - yList[tmp] + 1);
            findMinLength();
            lenList.clear();
        }

    cout << minLen << '\n';
}
